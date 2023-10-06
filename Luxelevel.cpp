#pragma once
#include <string>
#include <iostream>
#include "accomodatie.h"
#include "Luxelevel.h"

using namespace std;

bool Luxelevel::getblueray() {
	return blueray;
}
void Luxelevel::setblueray(bool yon) {
	blueray = yon;
}
bool Luxelevel::getbbq() {
	return bbq;
}
void Luxelevel::setbbq(bool input) {
	bbq = input;
}
bool Luxelevel::getbeddenopmaakservice() {
	return beddenopmaakservice;
}
void Luxelevel::setbeddenopmaakservice(bool ouiouno) {
	beddenopmaakservice = ouiouno;
}
bool Luxelevel::getontbijtservice() {
	return ontbijtservice;
}
void Luxelevel::setontbijtservice(bool siano) {
	ontbijtservice = siano;
}
Luxelevel::Luxelevel(bool yon , bool input , bool ouiouno , bool siano)  {
	blueray = yon;
	bbq = input;
	beddenopmaakservice = ouiouno;
	ontbijtservice = siano;
}