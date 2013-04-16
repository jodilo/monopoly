#ifndef SAO_H
#define SAO_H
#include <iostream>
#include <string>
using namespace std;

class SAO
{
	public:
		SAO();
		SAO(string, bool, int, int, int, bool, bool, bool);
		int getEffect();
		bool getGOOJ();
		bool getGTJ();
		int getMove();
		int getPos();
		string getDescription();
		bool getRR();
		bool getDH();

	private:
		string description;
		bool GOOJ;		//get out of jail
		int moneyEffect;
		int newLocation;
		int move;
		bool GTJ;		//go to jail
		bool RR;		//go to nearest railroad
		bool DH;		//go to nearest dining hall
};
#endif
		
