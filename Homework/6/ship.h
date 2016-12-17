//Kyle Hatfield
//04/28/2015
//ship.h
#ifndef SHIP_H
#define SHIP_H

//Just write the big three

using namespace std;

class Ship{
public:
	string m_name;
	int m_time_in;
	int m_fuel_units;
	int m_time_to_go;

	//destructor
	//INLINE
	~Ship(){}

	//default constructor
	Ship()
		: m_name("derp"), m_time_in(0), m_fuel_units(0), m_time_to_go(9999){}

	//constructor
	Ship(const string n, const int time, const int fuel)
		: m_name(n), m_time_in(time), m_fuel_units (fuel), m_time_to_go(9999){}

	//goTime
	//calculates the time to go
	void goTime (int x);

};
#endif

void Ship::goTime(int x)
{
	m_time_to_go = (x + (3 * m_fuel_units));
	return;
}