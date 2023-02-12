///////////////////////////////////////
//Name: Shayan Chabook 
//Email: schabook@myseneca.ca
//Student ID: 159844208 
//WS5-Lab (Part 1)
///////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include "Flight.h"
#include <cstring>
using namespace std;


namespace sdds
{


    void Flight::emptyPlane()
    {
        m_fuel = 0;

        m_passengers = 0;

        strcpy(m_title, "EmptyPlane");
    }



    // New Flight
    Flight::Flight()
    {
        emptyPlane();
    }



    Flight::Flight(int passengers, double fuel, const char* title)
    {
        emptyPlane();

        if (passengers > 0 && passengers <= Boeing747_Capacity && fuel >= 0 &&
            fuel <= FuelTank_Capacity)
        {
            m_fuel = fuel;

            m_passengers = passengers;

            strcpy(m_title, title);
        }
    }



    std::ostream& Flight::display() const
    {

        if (*this)
        {
            cout << " Flight  |  Ready to Depart";

            cout << " ";
            cout.width(10);
            cout << string(*this);

            cout << " | ";
            cout << "Pass: ";
            cout.width(10);

            cout << int(*this);
            cout << " | ";
            cout.width(12);

            cout.precision(2);
            cout.setf(ios::right);

            cout.setf(ios::fixed);
            cout << double(*this);

            cout.unsetf(ios::right);
            cout << " Liters";
        }
        else if (~*this)
        {
            cout << " Flight  |  Empty Plane    ";
        }
        else
        {
            cout << " Flight  |  Low Fuel       ";
            cout << " ";

            cout.width(10);
            cout << (const char*)(*this);

            cout << " | ";
            cout << "Pass: ";

            cout.width(10);
            cout << int(*this);
            cout << " | ";

            cout.width(12);
            cout.precision(2);

            cout.setf(ios::right);
            cout.setf(ios::fixed);

            cout << double(*this);

            cout.unsetf(ios::right);
            cout << " Liters";
        }
        return cout;
    }


    Flight::operator bool() const
    {
        if (m_passengers > 0 && m_fuel >= m_passengers * 600)
            return true;
        return false;
    }



    Flight::operator int() const
    {
        return m_passengers;
    }



    Flight::operator double() const
    {
        return m_fuel;
    }



    Flight::operator char* () const
    {
        return (char*)m_title;
    }


    bool Flight::operator~() const
    {
        if (m_passengers == 0)
            return true;
        return false;
    }


    Flight& Flight::operator=(Flight& f)
    {
        if (this != &f)
        {
            m_fuel = f.m_fuel;

            m_passengers = f.m_passengers;

            strcpy(m_title, f.m_title);

            f.emptyPlane();
        }
        return *this;
    }

    Flight& Flight::operator=(const int passengers)
    {
        if (passengers > 0 && passengers <= Boeing747_Capacity)
            m_passengers = passengers;
        return *this;
    }

    Flight& Flight::operator=(const double fuel)
    {
        if (fuel > 0 && fuel < FuelTank_Capacity)
            m_fuel = fuel;
        return *this;
    }


    Flight& Flight::operator+=(const double value)
    {
        if (value > 0 && m_fuel + value <= FuelTank_Capacity)
            m_fuel += value;
        return *this;
    }


    Flight& Flight::operator+=(const int value)
    {
        if (value > 0 && m_passengers + value <= Boeing747_Capacity)
            m_passengers += value;
        return *this;
    }


    Flight& Flight::operator-=(const int value)
    {
        if (value > 0 && m_passengers - value >= 0)
            m_passengers -= value;
        return *this;
    }



    Flight& Flight::operator-=(const double value)
    {
        if (value > 0)
        {
            if (m_fuel - value >= 0)
                m_fuel -= value;
            else
                m_fuel = 0;
        }
        return *this;
    }



    Flight& Flight::operator <<(Flight& f)
    {
        if (this != &f && *this && f)
        {
            if (m_passengers + f.m_passengers <= Boeing747_Capacity)
            {
                m_passengers += f.m_passengers;
                f.m_passengers = 0;
            }
            else
            {
                f.m_passengers -= Boeing747_Capacity - m_passengers;
                m_passengers = Boeing747_Capacity;
            }
        }
        return *this;
    }




    Flight& Flight::operator >>(Flight& f)
    {
        if (this != &f && *this && f)
        {
            if (m_passengers + f.m_passengers <= Boeing747_Capacity)
            {


                f.m_passengers += m_passengers;

                m_passengers = 0;
            }
            else
            {


                m_passengers -= Boeing747_Capacity - f.m_passengers;

                f.m_passengers = Boeing747_Capacity;
            }
        }
        return *this;
    }


    int operator +(const Flight& l, const Flight& r)
    {
        if (l && r)
            return l.m_passengers + r.m_passengers;
        return 0;
    }



    int operator +=(int& value, const Flight& f)
    {
        if (f)
            return value += f.m_passengers;
        return value;
    }
}