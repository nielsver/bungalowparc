#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include "accomodatie.h"
#include "hotel.h"

using namespace std;

int Hotel::getverdiep() {
	return verdiep;
}
void Hotel::setverdiep(int floor) {
	verdiep = floor;
}
string Hotel::getlocatie() {
	return locatie;
}
void Hotel::setlocatie(string loc) {
	locatie = loc;
}
int Hotel::getbedden() {
	return bedden;
}
void Hotel::setbedden(int bed) {
	bedden = bed;
}
bool Hotel::getaanwezigheidkinderbedden() {
	return aanwezigheidkinderbedden;
}
void Hotel:: setaanwezigheidkinderbedden(bool input) {
	aanwezigheidkinderbedden = input;
}
string Hotel::toString() {
	ostringstream output;
	output << fixed << setprecision(2);
	output << "\nhotel: " << Accomodatie::toString() << "verdiep " << getverdiep() << "\nlocatie " << getlocatie() << "\nbedden " << getbedden() << "\naanwezigheidkinderbedden " << getaanwezigheidkinderbedden();
	return output.str();
}
string Hotel::toStringfile() {
	ostringstream output;
	output << fixed << setprecision(2);
	output << Accomodatie::toStringfile() << " " << getverdiep() << " " << getlocatie() << " " << getbedden() << " " << getaanwezigheidkinderbedden();
	return output.str();
}
Hotel::Hotel(int floor, string loc , int bed, bool input) : Accomodatie(luxelevel) {
	verdiep = floor;
	locatie = loc;
	bedden = bed;
	aanwezigheidkinderbedden = input;

}