#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>
#include "boeking.h"

using namespace std; 
int Boeking::getboekingid() {
	return boekingid;
}
void Boeking::setboekingid(int id) {
	boekingid = id;
}
string Boeking::getdatum() {
	return datum;
}
void Boeking::setdatum(string date) {
	datum = date;
}
Klanten Boeking::getklanten() {
	return klant;
}
void Boeking::setklanten(Klanten klante) {
	klant = klante;
}
void Boeking::setprijs(int pri) {
	prijs = pri;
};
int Boeking::getprijs() {
	return prijs;
}
Accomodatie* Boeking::getaccomodatie() {
	return accomodatie;
}
void Boeking::setaccomodatie(Accomodatie* aco) {
	accomodatie = aco;
}
Boeking::Boeking() {
};
string Boeking::toString() {
	ostringstream output;
	Klanten klant = getklanten();
	Accomodatie* accomodatie = getaccomodatie();
	output << fixed << setprecision(2);
	output << "\nBoeking: " << "\nid " << getboekingid() << "\ndatum " << getdatum() << "\nklant " << klant.tostring() << "\naccomodatie " << accomodatie->toString() << "\ntotale prijs " << getprijs() << endl;
	return output.str();
}
string Boeking::toStringfile() {
	ostringstream output;
	Klanten klant = getklanten();
	Accomodatie* accomodatie = getaccomodatie();
	output << fixed << setprecision(2);
	output << " " << getboekingid() << " " << getdatum() << " " << getprijs() << " " << klant.tostringfile() << " " << accomodatie->toStringfile();
	return output.str();
}
Boeking::Boeking(Klanten cust,Accomodatie* aco, int id , string datm, int pri ) {
	boekingid = id;
	datum = datm;
	klant = cust;
	accomodatie = aco;
	prijs = pri;
}
Boeking::~Boeking() {};