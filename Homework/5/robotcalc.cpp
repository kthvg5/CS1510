//Kyle Hatfield
//04/20/2015
//robotcalc.cpp

#include <string>
#include <cstdlib>
#include <iostream>
#include "calcwithfuncs.h"
using namespace std;

int main(){
	string putIn = "howdy";
	int num = INIT_TO_ZERO;
	calcWithFuncs<int> buttons;
	while (cin >> putIn)
	{
		if(putIn == "+")
			buttons.add();
		else if(putIn == "-")
			buttons.minus();
		else if (putIn == "*")
			buttons.multiply();
		else if (putIn == "/")
			buttons.iCutChuUp();
		else if (putIn == "%")//the % is highlighted and I have no idea why
			buttons.allThatRemains();
		else if (putIn == "!")
			buttons.emoBand();
		else if (putIn == "SUM")
			buttons.addEmUp();
		else if (putIn == "R")
			buttons.backAsswards();
		else if (putIn == "#")
			buttons.spitThatOutRightNow();
		else if (putIn == "$")
			buttons.omNomNom();
		else if (putIn == "@")
			return 0;
		else
		{
			num = atoi(putIn.c_str() );
			buttons.push(num);
		}
	}
	return 0;
}