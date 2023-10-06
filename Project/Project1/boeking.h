#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "klanten.h"
#include "accomodatie.h"

using namespace std;
 
class Boeking {
private:
	int boekingid;
	string datum;
	Klanten klant;
	Accomodatie* accomodatie;
	int prijs;
public:
	int getboekingid();
	void setboekingid(int id);
	string getdatum();
	int getprijs();
	void setprijs(int prijs);
	void setdatum(string date);
	Klanten getklanten();
	void setklanten(Klanten klante);
	Accomodatie* getaccomodatie();
	void setaccomodatie(Accomodatie* aco);
	Boeking(Klanten cust, Accomodatie* aco, int id = 1, string datm = "1 januari", int pri = 0);
	string toString();
	string toStringfile();
	Boeking();
	~Boeking();
};