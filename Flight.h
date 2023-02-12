///////////////////////////////////////
//Name: Shayan Chabook 
//Email: schabook@myseneca.ca
//Student ID: 159844208 
//WS5-Lab (Part 1)
///////////////////////////////////////

#ifndef SDDS_FLIGHT_H
#define SDDS_FLIGHT_H
#include <iostream>

namespace sdds
{
    const int Boeing747_Capacity = 388;

    const int FuelTank_Capacity = 238840;

    class Flight
    {


        int m_passengers = 0;

        double m_fuel = 0;

        char m_title[16];

        void emptyPlane();

    public:

        Flight();



        Flight(int passengers, double fuel, const char* title);

        std::ostream& display() const;

        operator bool() const;

        operator int() const;
       
        operator double() const;
      
        operator char* () const;

        bool operator~() const;


        Flight& operator=(Flight& f);

        Flight& operator=(const int);

        Flight& operator=(const double);

        Flight& operator+=(const double);

        Flight& operator+=(const int);

        Flight& operator-=(const int);

        Flight& operator-=(const double);

        Flight& operator<<(Flight& f);

        Flight& operator>>(Flight& f);



        friend int operator+(const Flight& l, const Flight& r);

        friend int operator +=(int& value, const Flight& f);
    };


}
#endif 