//Kyle Hatfield
//fuelsim.cpp
#include <iostream>
#include "ship.h"
#include "llqueue.h"

const int INIT_TO_ZERO = 0;

int main()
{
	LLQueue<Ship> motherQueue;
	LLQueue<Ship> A;
	LLQueue<Ship> B;
	LLQueue<Ship> C;
	int aSize = INIT_TO_ZERO;
	int bSize = INIT_TO_ZERO;
	int cSize = INIT_TO_ZERO;
	int aTimeFront = INIT_TO_ZERO;
	int bTimeFront = INIT_TO_ZERO;
	int cTimeFront = INIT_TO_ZERO;
	int time_right_now = INIT_TO_ZERO;
	int num_ships = INIT_TO_ZERO;
	Ship flagship("derp", INIT_TO_ZERO, INIT_TO_ZERO);
	int wait = INIT_TO_ZERO;
	int max_wait = INIT_TO_ZERO;
	int min_wait = 9999;
	string longWaitName = "herp";
	string shortWaitName = "deDerp";


	cin >> num_ships;
	for (int i = 0; i < num_ships; i++)
	{
		cin >> flagship.m_time_in;
		cin >> flagship.m_name;
		cin >> flagship.m_fuel_units;
		motherQueue.enqueue(flagship);
	}
	while (!motherQueue.isEmpty() || !A.isEmpty() || !B.isEmpty() || !C.isEmpty())
	{
		time_right_now++;
		if(!motherQueue.isEmpty())
		{
			flagship = motherQueue.front();
			if(time_right_now == flagship.m_time_in)
			{
				motherQueue.dequeue();
				if(aSize <= bSize && aSize <= cSize)
				{
					if(A.isEmpty())
						aTimeFront = time_right_now;
					A.enqueue(flagship);
					cout << "At time " << time_right_now << " " << 
					flagship.m_name <<" joins port A." << endl;
					aSize++;
				}
				else if (bSize <= cSize)
				{
					if(B.isEmpty())
						bTimeFront = time_right_now;
					B.enqueue(flagship);
					cout << "At time " << time_right_now << " " << 
					flagship.m_name <<" joins port B." << endl;
					bSize++;
				}
				else
				{
					if(C.isEmpty())
						cTimeFront = time_right_now;
					C.enqueue(flagship);
					cout << "At time " << time_right_now << " " << 
					flagship.m_name <<" joins port C." << endl;
					cSize++;
				}
			}
		}
		if (!A.isEmpty())
		{
			flagship = A.front();
			flagship.goTime(aTimeFront);
			if (flagship.m_time_to_go == time_right_now)
			{
			A.dequeue();
			aTimeFront = time_right_now;
			aSize--;
				wait = (time_right_now - flagship.m_time_in);
				if (wait > max_wait)
				{
					longWaitName = flagship.m_name;
					max_wait = wait;
				}
				if (wait < min_wait)
				{
					shortWaitName = flagship.m_name;
					min_wait = wait;
				}
				cout << "At time " << time_right_now << " " 
				<< flagship.m_name <<" is done fueling." << endl;
			}
		}
		if(!B.isEmpty())
		{
			flagship = B.front();
			flagship.goTime(bTimeFront);
			if (flagship.m_time_to_go == time_right_now)
			{
				B.dequeue();
				bTimeFront = time_right_now;
				bSize--;
				wait = (time_right_now-flagship.m_time_in);
				if (wait > max_wait)
				{
					longWaitName = flagship.m_name;
					max_wait = wait;
				}
				if (wait < min_wait)
				{
					shortWaitName = flagship.m_name;
					min_wait = wait;
				}	
			cout << "At time " << time_right_now << " " 
				<< flagship.m_name <<" is done fueling." << endl;
			}
		}
		if(!C.isEmpty())
		{
			flagship = C.front();
			flagship.goTime(cTimeFront);
			if (flagship.m_time_to_go == time_right_now)
			{
				C.dequeue();
				cTimeFront = time_right_now;
				cSize--;	
				wait = (time_right_now - flagship.m_time_in);
				if (wait > max_wait)
				{
					longWaitName = flagship.m_name;
					max_wait = wait;
				}
				if (wait < min_wait)
				{
					shortWaitName = flagship.m_name;
					min_wait = wait;
				}
				cout << "At time " << time_right_now << " " 
				<< flagship.m_name <<" is done fueling." << endl;
			}
		}
	}
	cout << endl << "Longest wait: " << longWaitName << ", " << max_wait << " mins." << endl;
	cout << "Shortest wait: " << shortWaitName << ", " << min_wait << " mins." << endl;
	return 0;
}