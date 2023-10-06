	#pragma once
#include <string>
#include <iostream>

using namespace std;


class Klanten {
private:
	int klantid;
	string klantennaam;
	string paswoord;
	
public:
	int getklantid();
	void setklantid(int id);
	string getname();
	void setname(string name);
	string getpaswoord();
	void setpaswoord(string passwd);
	string tostring();
	string tostringfile();
	Klanten(int id = 1, string klantn = "john doe", string passwd="");
	~Klanten();








};