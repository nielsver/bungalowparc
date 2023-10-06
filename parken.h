#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "services.h"
#include "accomodatie.h"

using namespace std;

class Parken {
private:
	int parkid;
	string parknaam;
	string locatie;
	vector<Accomodatie*> accomodatie;
	Services service;
public:
	int getparkid();
	void setparkid(int id);
	string getparknaam();
	void setparknaam(string park);
	string getlocatie();
	void setlocatie(string loc);
	void setaccomodatie(vector<Accomodatie*> aco);
	vector<Accomodatie*> getaccomodatie();
	Services getservice();
	void setservice(Services serv);
	Parken(vector<Accomodatie*> acco, Services serv, int id = 1, string naam = "park mol", string loc = "china");
	Parken();
	string toString();
	string toStringfile();
	string toStringboeking();
};