#pragma once
#include <string>
#include <iostream>

class Luxelevel {
private:
	bool blueray;
	bool bbq;
	bool beddenopmaakservice;
	bool ontbijtservice;
public:
	bool getblueray();
	void setblueray(bool yon);
	bool getbbq();
	void setbbq(bool input);
	bool getbeddenopmaakservice();
	void setbeddenopmaakservice(bool ouiouno);
	bool getontbijtservice();
	void setontbijtservice(bool siano);
	Luxelevel(bool yon = false, bool input = false, bool ouiouno = false, bool siano = false);
};