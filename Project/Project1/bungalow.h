#pragma once
#include <string>
#include <iostream>
#include "accomodatie.h"

using namespace std;

class Bungalow : public Accomodatie {
private:
	int aantalslaapkamers;



public:
	int getaantalslaapkamers();
	void setaantalslaapkamers(int nummer);
	virtual string toString() override;
	virtual string toStringfile() override;
	Bungalow(int nummer = 1);
	~Bungalow();

};