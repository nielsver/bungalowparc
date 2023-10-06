#pragma once
#include <string>
#include <iostream>

using namespace std;

class Services {
private:

	bool zwembad;
	bool sport;
	bool bowling;
	bool fietsen;
	bool kinderparadijs;
	bool waterfietsen;
	int serviceprice;
public:
	int getserviceprice();
	void setserviceprice(int prijs);
	bool getzwembad();
	void setzwembad(bool zwembad);
	bool getsport();
	void setsport(bool sport);
	bool getbowling();
	void setbowling(bool bowling);
	bool getfietsen();
	void setfietsen(bool fietsen);
	bool getkinderparadijs();
	void setkinderparadijs(bool kinderparadijs);
	bool getwaterfietsen();
	void setwaterfietsen(bool waterfietsen);
	Services(bool zwembad = 0, bool sport = 0, bool bowling = 0, bool fietsen = 0, bool kinderparadijs = 0, bool waterfietsen = 0, int servprice = 20);
	string toString();
	~Services();
};