#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <iomanip>
#include "bungalow.h"

using namespace std;

int Bungalow::getaantalslaapkamers() {
	return aantalslaapkamers;
}
void Bungalow::setaantalslaapkamers(int nummer) {
	aantalslaapkamers = nummer;
}
string Bungalow::toString(){
	ostringstream output;
	output << fixed << setprecision(2);
	output << "\nbungalow:" << Accomodatie::toString() << "slaapkamers " << getaantalslaapkamers() << endl;
	return output.str();
}
string Bungalow::toStringfile() {
	ostringstream output;
	output << fixed << setprecision(2);
	output << Accomodatie::toStringfile() << " " << getaantalslaapkamers();
	return output.str();
}
Bungalow::Bungalow(int nummer) : Accomodatie(luxelevel){
	aantalslaapkamers = nummer;
	
}
Bungalow::~Bungalow() {};