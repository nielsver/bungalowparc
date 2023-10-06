#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "accomodatie.h"
#include "services.h"

using namespace std;


int Services::getserviceprice() {
	return serviceprice;
}
void Services::setserviceprice(int prijs) {
	serviceprice = prijs;
}
bool Services::getzwembad() {
	return zwembad;
};
void Services::setzwembad(bool zwemba) {
	zwembad = zwemba;
};
bool Services::getsport() {
	return sport;
};
void Services::setsport(bool spor) {
	sport = spor;
};
bool Services::getbowling() {
	return bowling;
};
void Services::setbowling(bool bowlin) {
	bowling = bowlin;
};
bool Services::getfietsen() {
	return fietsen;
};
void Services::setfietsen(bool fietse) {
	fietsen = fietse;
};
bool Services::getkinderparadijs() {
	return kinderparadijs;
};
void Services::setkinderparadijs(bool kinderparadij) {
	kinderparadijs = kinderparadij;
};
bool Services::getwaterfietsen() {
	return waterfietsen;
};
void Services::setwaterfietsen(bool waterfietse) {
	waterfietsen = waterfietse;
};
string Services::toString() {
	ostringstream output;
	output << fixed << setprecision(2);
	output << "\nsubtropische zwembad: " << getzwembad() << "\nsportinfrastructuur: " << getsport() << "\nbowlingbaan: " << getbowling() << "\nfietsverhuur: " << getfietsen() << "\nkinderparadijs: " << getkinderparadijs() << "\nwaterfietsen: " << getwaterfietsen() << "\nprijs: " << getserviceprice() << endl;
	return output.str();
}
Services::~Services() {};
Services::Services(bool zwemba, bool spor, bool bowlin, bool fietse, bool kinderparadij, bool waterfietse , int servprice ) {

	zwembad = zwemba;
	sport = spor;
	bowling = bowlin;
	fietsen = fietse;
	kinderparadijs = kinderparadij;
	waterfietsen = waterfietse;
	serviceprice = servprice;
}