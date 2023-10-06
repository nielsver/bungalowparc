#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "klanten.h"

using namespace std;

int Klanten::getklantid() {
	return klantid;
}
void Klanten::setklantid(int id) {
	klantid = id;
}
string Klanten::getname() {
	return klantennaam;
}
void Klanten::setname(string name) {
	klantennaam = name;
}
string Klanten::getpaswoord() {
	return paswoord;
}
void Klanten::setpaswoord(string passwd) {
	paswoord = passwd;
}
Klanten::Klanten(int id , string klantn, string passwd ) {
	klantid = id;
	klantennaam = klantn;
	paswoord = passwd;
}
string Klanten::tostringfile() {
	ostringstream output;
	output << fixed << setprecision(2);
	output << " " << getklantid() << " " << getname() << " " << getpaswoord();
	return output.str();
}
string Klanten::tostring() {
	ostringstream output;
	output << fixed << setprecision(2);
	output << "Klantid: " << getklantid() << " naam: " << getname() << " paswoord: " << getpaswoord() << endl;
	return output.str();
}
Klanten::~Klanten() {};