#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "accomodatie.h"

using namespace std;

int Accomodatie::getaccomodatieid() {
	return accomodatieid;
}
void Accomodatie::setaccomodatieid(int accoid) {
	accomodatieid = accoid;
}
int Accomodatie::getpersonen() {
	return personen;
}
void Accomodatie::setpersonen(int pers) {
	personen = pers;
}
int Accomodatie::getoppervlakte() {
	return oppervlakte;
}
void Accomodatie::setoppervlakte(int opp) {
	oppervlakte = opp;
}
bool Accomodatie::getbad() {
	return badkamer;
}
void Accomodatie::setbad(bool badkam) {
	badkamer = badkam;
}
int Accomodatie::getprice() {
	return accomodatieprice;
}
void Accomodatie::setprice(int prijs) {
	accomodatieprice = prijs;
}
Luxelevel Accomodatie::getluxelevel() {
	return luxelevel;
}
void Accomodatie::setluxelevel(Luxelevel lux) {
	luxelevel = lux;
}
void Accomodatie::setluxelevelcomp(bool blueray, bool bbq, bool opruimen, bool eten) {
	luxelevel.setblueray(blueray);
	luxelevel.setbbq(bbq);
	luxelevel.setbeddenopmaakservice(opruimen);
	luxelevel.setontbijtservice(eten);
}
void Accomodatie::setluxelevelbbq(bool bbq) {
	luxelevel.setbbq(bbq);
}
void Accomodatie::setluxelevelblueray(bool blueray) {
	luxelevel.setblueray(blueray);
}
void Accomodatie::setluxeleveleten(bool eten) {
	luxelevel.setontbijtservice(eten);
}
void Accomodatie::setluxelevelopruimen(bool opruimer) {
	luxelevel.setbeddenopmaakservice(opruimer);
}
bool Accomodatie::getType() {
	return type;
}
void Accomodatie::setType(bool typ) {
	type = typ;
}
string Accomodatie::toString()  {
	ostringstream output;
	output << fixed << setprecision(2);
	output << "\nid " << getaccomodatieid() << "\npersonen " << getpersonen()<< "\noppervlakte " << getoppervlakte() << " m²\nbad " << getbad() <<"\nprijs " << getprice() << " euro" << endl;
	return output.str();
};
string Accomodatie::toStringfile() {
	ostringstream output;
	output << fixed << setprecision(2);
	output << " " << getType() << " " << getaccomodatieid() << " " << getpersonen() << " " << getoppervlakte() << " " << getbad() << " " << getprice() << " " << luxelevel.getbbq() << " " << luxelevel.getbeddenopmaakservice() << " " << luxelevel.getblueray() << " " << luxelevel.getontbijtservice();
	return output.str();
};
Accomodatie::Accomodatie(Luxelevel lux, int accoid , int pers, int opp , bool isbad, int accoprice, bool typ) {
	luxelevel = lux;
	accomodatieid = accoid;
	personen = pers;
	oppervlakte = opp;
	badkamer = isbad;
	accomodatieprice = accoprice;
	type = typ;
}
Accomodatie::Accomodatie() {};
Accomodatie::~Accomodatie() {};