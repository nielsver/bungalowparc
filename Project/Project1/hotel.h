#pragma once
#include <string>
#include <iostream>
#include "accomodatie.h"

using namespace std;

class Hotel : public Accomodatie{
private:
	int verdiep;
	string locatie;
	int bedden;
	bool aanwezigheidkinderbedden;

public:
	int getverdiep();
	void setverdiep(int floor);
	string getlocatie();
	void setlocatie(string loc);
	int getbedden();
	void setbedden(int bed);
	bool getaanwezigheidkinderbedden();
	void setaanwezigheidkinderbedden(bool input);
	virtual string toString() override;
	virtual string toStringfile() override;
	Hotel(int floor = 0, string loc = "Japan", int bed = 1, bool input = false);

};