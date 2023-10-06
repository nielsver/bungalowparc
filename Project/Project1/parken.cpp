#include <string>
#include <iostream>
#include "parken.h"
#include "services.h"
#include "accomodatie.h"
#include <iomanip>
#include <sstream>

using namespace std;



int Parken::getparkid() {
	return parkid;
}
void Parken::setparkid(int id) {
	parkid = id;
}
string Parken::getparknaam() {
	return parknaam;
}
void Parken::setparknaam(string park) {
	parknaam = park;
}
string Parken::getlocatie() {
	return locatie;
}
void Parken::setlocatie(string loc) {
	locatie = loc;
}
void Parken::setaccomodatie(vector<Accomodatie*> aco) {
	accomodatie = aco;
}
vector<Accomodatie*> Parken::getaccomodatie() {
	return accomodatie;
}
Services Parken::getservice() {
	return service;
}
void Parken::setservice(Services serv) {
	service = serv;
}
Parken::Parken() {};
Parken::Parken(vector<Accomodatie*> acco, Services serv, int id, string naam, string loc){
	parkid = id;
	parknaam = naam;
	locatie = loc;
	accomodatie = acco;
	service = serv;
}
string Parken::toString() {
	int size;
	Services service;
	vector<Accomodatie*> accomodatie;
	accomodatie = getaccomodatie();
	size = accomodatie.size();
	service = getservice();
	ostringstream output;
	output << fixed << setprecision(2);
	output << "\nParken: " << "\nid " << getparkid() << "\nnaam " << getparknaam() << "\nlocatie " << getlocatie() << "\nservices:\nbowling " << service.getbowling() << "\nfietsenverhuur " << service.getfietsen() << "\nkinderparadijs " << service.getkinderparadijs() << "\nwaterfietsen " << service.getwaterfietsen() << "\nsportinfrastructuur " << service.getsport() << "\nsubtropsiche zwembad " << service.getzwembad() << "\nserviceprijs " << service.getserviceprice() << endl;
	output << "\nAccomodaties:";
	for (int i = 0; i < size; i++) {
		output << accomodatie.at(i)->toString() << endl;
	}
	return output.str(); 
}
string Parken::toStringboeking() {
	Services service;
	service = getservice();
	ostringstream output;
	output << fixed << setprecision(2);
	output << "\nParken: " << "\nid " << getparkid() << "\nnaam " << getparknaam() << "\nlocatie " << getlocatie() << "\nservices:\nbowling " << service.getbowling() << "\nfietsenverhuur " << service.getfietsen() << "\nkinderparadijs " << service.getkinderparadijs() << "\nwaterfietsen " << service.getwaterfietsen() << "\nsportinfrastructuur " << service.getsport() << "\nsubtropsiche zwembad " << service.getzwembad() << "\nserviceprijs " << service.getserviceprice() << endl;
	return output.str();
}
string Parken::toStringfile() {
	int size;
	Services service;
	vector<Accomodatie*> accomodatie;
	accomodatie = getaccomodatie();
	size = accomodatie.size();
	service = getservice();
	ostringstream output;
	output << fixed << setprecision(2);
	output << getparkid() << " " << getparknaam() << " " << getlocatie() << " " << service.getbowling() << " " << service.getfietsen() << " " << service.getkinderparadijs() << " " << service.getwaterfietsen() << " " << service.getsport() << " " << service.getzwembad() << " " << service.getserviceprice() << endl;
	for (int i = 0; i < size; i++) {
		output << accomodatie.at(i)->toStringfile() << endl;
	}
	return output.str();
}