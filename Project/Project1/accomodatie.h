#pragma once
#include <string>
#include <iostream>
#include "Luxelevel.h"

using namespace std;

class Accomodatie {
protected:
	int accomodatieid;
	int personen;
	int oppervlakte;
	bool badkamer;//true als het een bad is
	int accomodatieprice;
	Luxelevel luxelevel;
	bool type; //1 of true is een hotel
public:
	int getaccomodatieid();
	void setaccomodatieid(int accoid);
	int getpersonen();
	void setpersonen(int pers);
	int getoppervlakte();
	void setoppervlakte(int opp);
	bool getbad();
	void setbad(bool badkam);
	int getprice();
	void setprice(int prijs);
	Luxelevel getluxelevel();
	void setluxelevel(Luxelevel lux);
	bool getType();
	void setType(bool typ);
	virtual string toString();
	virtual string toStringfile();
	void setluxelevelcomp(bool bluerays, bool bbq, bool opruimen, bool eten);
	void setluxelevelblueray(bool bluerays);
	void setluxelevelbbq(bool bbq);
	void setluxelevelopruimen(bool opruimen);
	void setluxeleveleten(bool eten);
	Accomodatie(Luxelevel lux, int accoid = 1, int pers = 1, int opp = 100, bool isbad = false, int accoprice = 100,bool typ = 0);
	Accomodatie();
	~Accomodatie();
};