#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>
#include "klanten.h"
#include "parken.h"
#include "accomodatie.h"
#include "services.h"
#include "boeking.h"
#include "bungalow.h"
#include "Luxelevel.h"
#include <type_traits>
#include "hotel.h"
#include <fstream>
#include <cstdlib>
	
using namespace std;


Klanten registreren(int klantid);
vector<Accomodatie*> nieuweaccomodatie(vector<Accomodatie*> acco);
vector<Accomodatie*> verwijderaccomodatie(vector<Accomodatie*> acco);
vector<Accomodatie*> aanpassenaccomodatie(vector<Accomodatie*> acco);
vector<Parken*> nieuwpark(vector<Accomodatie*> acco, vector<Parken*> park);
vector<Parken*> verwijderenpark(vector<Parken*> park);
vector<Parken*> aanpassenpark(vector<Accomodatie*> acco, vector<Parken*> park);
vector<Boeking*> nieuweboeking(Klanten klant, vector<Parken*> park, vector<Boeking*> boeking);
vector<Boeking*> verwijderenboeking(vector<Boeking*> boeking);
vector<Boeking*> aanpassenboeking(vector<Parken*> park, vector<Boeking*> boeking);

int main() {
	int klantid, boekingid, accomodatieid, personen, oppervlakte, accomodatieprijs, verdiep, bedden, aantalslaapkamers, parkid, prijs, optie, x = 0, ingelogd = 0, currentklantid = 0, id = 0;

	bool bbq, beddenopmaakservice, blueray, ontbijtservice, type, badkamer, aanwezigheidkinderbedden, bowling, fietsen, kinderparadijs, waterfietsen, sport, zwembad,boekingtype;

	string naam, datum, pswd, locatie, parknaam, trash, username, paswoord, nieuweusername, zeker = "yes";

	Luxelevel luxelevel;
	Klanten klant;
	Hotel* hotel;
	Bungalow* bungalow;
	Boeking* boeking1;
	Services service;

	vector<Klanten> klanten;
	vector<Boeking*> boeking;
	vector<Accomodatie*> accomodatie;
	vector<Parken*> parken;
	vector<Accomodatie*> accomodatiep;
	vector<Accomodatie*> accomodatieb;

	ifstream inClientFile{ "clients.txt",ios::in };
	ifstream inBoekingFile{ "boeking.txt", ios::in };
	ifstream inAccomodatieFile{ "accomodatie.txt", ios::in };
	ifstream inParkenFile{ "parken.txt", ios::in };

	if (!inClientFile) {

	}
	else {
		while (inClientFile >> klantid >> naam >> pswd) {
			klanten.push_back(Klanten(klantid, naam, pswd));
		}
	}
	if (!inAccomodatieFile) {

	}
	else {
		while (inAccomodatieFile >> type) {
			if (type == 1) {
				hotel = new Hotel();
				inAccomodatieFile >> accomodatieid >> personen >> oppervlakte >> badkamer >> accomodatieprijs >> bbq >> beddenopmaakservice >> blueray >> ontbijtservice >> verdiep >> locatie >> bedden >> aanwezigheidkinderbedden;
				luxelevel.setbbq(bbq);
				luxelevel.setbeddenopmaakservice(beddenopmaakservice);
				luxelevel.setblueray(blueray);
				luxelevel.setontbijtservice(ontbijtservice);
				hotel->setaccomodatieid(accomodatieid);
				hotel->setpersonen(personen);
				hotel->setoppervlakte(oppervlakte);
				hotel->setbad(badkamer);
				hotel->setprice(accomodatieprijs);
				hotel->setluxelevelcomp(blueray, bbq, beddenopmaakservice, ontbijtservice);
				hotel->setverdiep(verdiep);
				hotel->setlocatie(locatie);
				hotel->setaanwezigheidkinderbedden(aanwezigheidkinderbedden);
				hotel->setbedden(bedden);
				accomodatie.push_back(hotel);

			}
			else {
				bungalow = new Bungalow();
				inAccomodatieFile >> accomodatieid >> personen >> oppervlakte >> badkamer >> accomodatieprijs >> bbq >> beddenopmaakservice >> blueray >> ontbijtservice >> aantalslaapkamers;
				luxelevel.setbbq(bbq);
				luxelevel.setbeddenopmaakservice(beddenopmaakservice);
				luxelevel.setblueray(blueray);
				luxelevel.setontbijtservice(ontbijtservice);
				bungalow->setaccomodatieid(accomodatieid);
				bungalow->setpersonen(personen);
				bungalow->setoppervlakte(oppervlakte);
				bungalow->setbad(badkamer);
				bungalow->setprice(accomodatieprijs);
				bungalow->setluxelevelcomp(blueray, bbq, beddenopmaakservice, ontbijtservice);
				bungalow->setaantalslaapkamers(aantalslaapkamers);
				accomodatie.push_back(bungalow);
			}
		}
	}
	if (!inParkenFile) {

	}
	else {
		inParkenFile >> parkid;
		while (inParkenFile >> parknaam >> locatie >> bowling >> fietsen >> kinderparadijs >> waterfietsen >> sport >> zwembad >> prijs) {
			while (inParkenFile >> type) {
				if (type == 1) {
					hotel = new Hotel();
					inParkenFile >> accomodatieid >> personen >> oppervlakte >> badkamer >> accomodatieprijs >> bbq >> beddenopmaakservice >> blueray >> ontbijtservice >> verdiep >> locatie >> bedden >> aanwezigheidkinderbedden;
					luxelevel.setbbq(bbq);
					luxelevel.setbeddenopmaakservice(beddenopmaakservice);
					luxelevel.setblueray(blueray);
					luxelevel.setontbijtservice(ontbijtservice);
					hotel->setaccomodatieid(accomodatieid);
					hotel->setpersonen(personen);
					hotel->setoppervlakte(oppervlakte);
					hotel->setbad(badkamer);
					hotel->setprice(accomodatieprijs);
					hotel->setluxelevelcomp(blueray, bbq, beddenopmaakservice, ontbijtservice);
					hotel->setverdiep(verdiep);
					hotel->setlocatie(locatie);
					hotel->setaanwezigheidkinderbedden(aanwezigheidkinderbedden);
					hotel->setbedden(bedden);
					accomodatiep.push_back(hotel);

				}
				else if (type == 0) {
					bungalow = new Bungalow();
					inParkenFile >> accomodatieid >> personen >> oppervlakte >> badkamer >> accomodatieprijs >> bbq >> beddenopmaakservice >> blueray >> ontbijtservice >> aantalslaapkamers;
					luxelevel.setbbq(bbq);
					luxelevel.setbeddenopmaakservice(beddenopmaakservice);
					luxelevel.setblueray(blueray);
					luxelevel.setontbijtservice(ontbijtservice);
					bungalow->setaccomodatieid(accomodatieid);
					bungalow->setpersonen(personen);
					bungalow->setoppervlakte(oppervlakte);
					bungalow->setbad(badkamer);
					bungalow->setprice(accomodatieprijs);
					bungalow->setluxelevelcomp(blueray, bbq, beddenopmaakservice, ontbijtservice);
					bungalow->setaantalslaapkamers(aantalslaapkamers);
					accomodatiep.push_back(bungalow);
				}
				else {
					parkid = type - 1;
					break;
				}
			}
			service = Services(zwembad, sport, bowling, fietsen, kinderparadijs, waterfietsen, prijs);
			parken.push_back(new Parken(accomodatiep, service, parkid, parknaam, locatie));
		}
	}
	if (!inBoekingFile) {

	}
	else {
		while (inBoekingFile >> boekingid >> datum >> prijs >> klantid >> naam >> pswd >> boekingtype ) {
			if (boekingtype == 1) {
				hotel = new Hotel();
				inBoekingFile >> accomodatieid >> personen >> oppervlakte >> badkamer >> accomodatieprijs >> bbq >> beddenopmaakservice >> blueray >> ontbijtservice >> verdiep >> locatie >> bedden >> aanwezigheidkinderbedden;
				luxelevel.setbbq(bbq);
				luxelevel.setbeddenopmaakservice(beddenopmaakservice);
				luxelevel.setblueray(blueray);
				luxelevel.setontbijtservice(ontbijtservice);
				hotel->setaccomodatieid(accomodatieid);
				hotel->setpersonen(personen);
				hotel->setoppervlakte(oppervlakte);
				hotel->setbad(badkamer);
				hotel->setprice(accomodatieprijs);
				hotel->setluxelevelcomp(blueray, bbq, beddenopmaakservice, ontbijtservice);
				hotel->setverdiep(verdiep);
				hotel->setlocatie(locatie);
				hotel->setaanwezigheidkinderbedden(aanwezigheidkinderbedden);
				hotel->setbedden(bedden);
				accomodatieb.push_back(hotel);

			}
			else if (boekingtype == 0) {
				bungalow = new Bungalow();
				inBoekingFile >> accomodatieid >> personen >> oppervlakte >> badkamer >> accomodatieprijs >> bbq >> beddenopmaakservice >> blueray >> ontbijtservice >> aantalslaapkamers;
				luxelevel.setbbq(bbq);
				luxelevel.setbeddenopmaakservice(beddenopmaakservice);
				luxelevel.setblueray(blueray);
				luxelevel.setontbijtservice(ontbijtservice);
				bungalow->setaccomodatieid(accomodatieid);
				bungalow->setpersonen(personen);
				bungalow->setoppervlakte(oppervlakte);
				bungalow->setbad(badkamer);
				bungalow->setprice(accomodatieprijs);
				bungalow->setluxelevelcomp(blueray, bbq, beddenopmaakservice, ontbijtservice);
				bungalow->setaantalslaapkamers(aantalslaapkamers);
				accomodatieb.push_back(bungalow);
			}
			klant = Klanten(klantid, naam, pswd);
			
			boeking.push_back(new Boeking(klant, accomodatieb.back(), boekingid, datum, prijs));
		}
	}

	ofstream outClientFile{ "clients.txt",ios::out };
	ofstream outBoekingFile{ "boeking.txt", ios::out };
	ofstream outAccomodatieFile{ "accomodatie.txt", ios::out };
	ofstream outParkenFile{ "parken.txt", ios::out };
	

	cout << "ben je een klant (1) werknemer (2) of baas (3): ";
	cin >> x;
	getline(cin, trash);
	while (true) {
	while (x != 1 && x != 2 && x != 3 && x != 4) {
		cout << "ben je een klant (1) werknemer (2) of baas (3), exit (4): ";
		cin >> x;
		getline(cin, trash);
	}
	switch (x) {
	case 1:
		//klant
		if (ingelogd == 0) {
			//niet ingelogd
			cout << "\nWat wil je doen: \n";
			cout << "1. registreren\n2. inloggen \n3. ik ben geen klant\n4. programma verlaten\n";
			cin >> optie;
			getline(cin, trash);
			while (optie != 1 && optie != 2 && optie != 3 && optie != 4) {
				cout << "geen optie\n";
				cout << "1. registreren\n 2. inloggen \n3. ik ben geen klant\n4. programma verlaten\n";
				cin >> optie;
				getline(cin, trash);
			}
			switch (optie) {
			case 1:
				//registreren
				klanten.push_back(registreren(klanten.size()));
				ingelogd = 1;
				currentklantid = klanten.size() - 1;
				break;
			case 2:
				//inloggen
				cout << "\ngeef een username(naam) of typ return: ";
				getline(cin, username);
				while (username != "return" && ingelogd == 0) {
					for (int i = 0; i < klanten.size(); i++) {
						if (username == klanten.at(i).getname()) {
							cout << "geef je wachtwoord of typ exit: ";
							getline(cin, paswoord);
							while (paswoord != "exit" && ingelogd == 0) {
								if (paswoord == klanten.at(i).getpaswoord()) {
									currentklantid = i;
									ingelogd = 1;
									continue;
								}
								cout << "\ngeef je wachtwoord of typ exit: ";
								getline(cin, paswoord);
							}
							if (paswoord == "exit") {
								if (!outClientFile) {
									cerr << "File could not be opened" << endl;
									exit(EXIT_FAILURE);
								}
								for (int i = 0; i < klanten.size(); i++) {
									outClientFile << klanten.at(i).getklantid() << ' ' << klanten.at(i).getname() << ' ' << klanten.at(i).getpaswoord() << endl;
								}
								if (!outAccomodatieFile) {
									cerr << "File could not be opened" << endl;
									exit(EXIT_FAILURE);
								}
								for (int i = 0; i < accomodatie.size(); i++) {
									outAccomodatieFile << accomodatie.at(i)->toStringfile();
								}
								if (!outBoekingFile) {
									cerr << "File could not be opened" << endl;
									exit(EXIT_FAILURE);
								}
								for (int i = 0; i < boeking.size(); i++) {
									outBoekingFile << boeking.at(i)->toStringfile();
								}
								if (!outParkenFile) {
									cerr << "File could not be opened" << endl;
									exit(EXIT_FAILURE);
								}
								for (int i = 0; i < parken.size(); i++) {
									outParkenFile << parken.at(i)->toStringfile();
								}
								exit(0);
							}

						}
					}
					if (ingelogd == 0) {
						cout << "\ngeen juiste username\n";
						cout << "\ngeef een username of typ return: ";
						getline(cin, username);
					}

				}
				if (username == "return") {
					optie = 0;
				}
				break;
			case 3:
				//ik ben geen klant terug naar home
				x = 0;
				break;
			case 4:
				//programma verlaten 
				if (!outClientFile) {
					cerr << "File could not be opened" << endl;
					exit(EXIT_FAILURE);
				}
				for (int i = 0; i < klanten.size(); i++) {
					outClientFile << klanten.at(i).getklantid() << ' ' << klanten.at(i).getname() << ' ' << klanten.at(i).getpaswoord() << endl;
				}
				if (!outAccomodatieFile) {
					cerr << "File could not be opened" << endl;
					exit(EXIT_FAILURE);
				}
				for (int i = 0; i < accomodatie.size(); i++) {
					outAccomodatieFile << accomodatie.at(i)->toStringfile();
				}
				if (!outBoekingFile) {
					cerr << "File could not be opened" << endl;
					exit(EXIT_FAILURE);
				}
				for (int i = 0; i < boeking.size(); i++) {
					outBoekingFile << boeking.at(i)->toStringfile();
				}
				if (!outParkenFile) {
					cerr << "File could not be opened" << endl;
					exit(EXIT_FAILURE);
				}
				for (int i = 0; i < parken.size(); i++) {
					outParkenFile << parken.at(i)->toStringfile();
				}
				exit(0);
				break;
			}
		}
		while (ingelogd == 1) {
			//ingelogd
			cout << "1. Wie ben ik\n2. programma verlaten\n3. gebruiker aanpassen\n4. accomodaties bekijken\n5. boeking maken\n6. boeking aanpassen\n7. uitloggen\n";
			cin >> optie;
			getline(cin, trash);
			while (optie != 1 && optie != 2 && optie != 3 && optie != 4 && optie != 5 && optie != 6 && optie != 7) {
				cout << "\ngeen optie juiste optie!";
				cout << "1. Wie ben ik\n2. programma verlaten\n3. gebruiker aanpassen\n4. accomodaties bekijken\n5. boeking maken\n6. boeking aanpassen\n7. uitloggen\n";
				cin >> optie;
				getline(cin, trash);
			}
			if (optie == 1) {
				cout << klanten.at(currentklantid).getname() << endl;

			}
			else if (optie == 2) {
				if (!outClientFile) {
					cerr << "File could not be opened" << endl;
					exit(EXIT_FAILURE);
				}
				for (int i = 0; i < klanten.size(); i++) {
					outClientFile << klanten.at(i).getklantid() << ' ' << klanten.at(i).getname() << ' ' << klanten.at(i).getpaswoord() << endl;
				}
				if (!outAccomodatieFile) {
					cerr << "File could not be opened" << endl;
					exit(EXIT_FAILURE);
				}
				for (int i = 0; i < accomodatie.size(); i++) {
					outAccomodatieFile << accomodatie.at(i)->toStringfile();
				}
				if (!outBoekingFile) {
					cerr << "File could not be opened" << endl;
					exit(EXIT_FAILURE);
				}
				for (int i = 0; i < boeking.size(); i++) {
					outBoekingFile << boeking.at(i)->toStringfile();
				}
				if (!outParkenFile) {
					cerr << "File could not be opened" << endl;
					exit(EXIT_FAILURE);
				}
				for (int i = 0; i < parken.size(); i++) {
					outParkenFile << parken.at(i)->toStringfile();
				}
				exit(0);
			}
			else if (optie == 3) {
				cout << "\nin wat wil je je naam veranderen: ";
				cin >> nieuweusername;
				getline(cin, trash);
				klanten.at(currentklantid).setname(nieuweusername);
				
			}
			else if (optie == 4) {
				for (int i = 0; i < accomodatie.size(); i++) {
					string acco = accomodatie.at(i)->toString();
					cout << acco << endl;
				}
			}
			else if (optie == 5) {
				//boeking maken
				boeking = nieuweboeking(klanten.at(currentklantid), parken, boeking);
				
			}
			else if (optie == 6){
				//boeking aanpassen
				boeking = aanpassenboeking(parken, boeking);
			}
			else if (optie == 7) {
				ingelogd = 0;
				x = 0;
			}
		}
		break;
	case 2:
		//werknemer
		cout << "\nWat wil je doen: \n";
		cout << "1. Boeking verwijderen\n2. Klant verwijderen\n3. Klanten tonen \n4. Accomodatie aanpassen\n5. Ik ben geen werknemer\n6. Programma verlaten\n";
		cin >> optie;
		getline(cin, trash);
		while (optie != 1 && optie != 2 && optie != 3 && optie != 4 && optie !=5 && optie !=6) {
			cout << "geen optie\n";
			cout << "1. Boeking verwijderen\n2. Klant verwijderen\n3. Klanten tonen \n4. Accomodatie aanpassen\n5. Ik ben geen werknemer\n6. Programma verlaten\n";;
			cin >> optie;
			getline(cin, trash);
		}
		switch (optie)
		{
		case 1:
			//boeking verwijderen
			boeking = verwijderenboeking(boeking);

			break;
		case 2:
			cout << "\ngeef een username(naam) of typ return: ";
			getline(cin, username);
			while (username != "return" && optie != 0) {
				for (int i = 0; i < klanten.size(); i++) {
					if (username == klanten.at(i).getname()) {
						cout << "geef je wachtwoord of typ return: ";
						getline(cin, paswoord);
						while (paswoord != "return" && optie != 0) {
							if (paswoord == klanten.at(i).getpaswoord()) {
								klanten.erase(klanten.begin() + i);
								cout << username << " succesvol verwijdert";
								optie = 0;
								continue;
							}
							cout << "\ngeef je wachtwoord of typ return: ";
							getline(cin, paswoord);
						}
						if (paswoord == "return") {
							optie = 0;
						}

					}
				}
				if (optie != 0) {
					cout << "\ngeen juiste username\n";
					cout << "\ngeef een username of typ return: ";
					getline(cin, username);
				}

			}
			if (username == "return") {
				optie = 0;
			}
			break;
			
		case 3:
			for (int i = 0; i < klanten.size(); i++) {
				 string klant = klanten.at(i).tostring();
				 cout << klant;
			}
			break;
		case 4:
			//acomodatie aanpassen
			accomodatie = aanpassenaccomodatie(accomodatie);
			
			break;
		case 5:
			x = 0;
			break;
		case 6:
			if (!outClientFile) {
				cerr << "File could not be opened" << endl;
				exit(EXIT_FAILURE);
			}
			for (int i = 0; i < klanten.size(); i++) {
				outClientFile << klanten.at(i).getklantid() << ' ' << klanten.at(i).getname() << ' ' << klanten.at(i).getpaswoord() << endl;
			}
			if (!outAccomodatieFile) {
				cerr << "File could not be opened" << endl;
				exit(EXIT_FAILURE);
			}
			for (int i = 0; i < accomodatie.size(); i++) {
				outAccomodatieFile << accomodatie.at(i)->toStringfile();
			}
			if (!outBoekingFile) {
				cerr << "File could not be opened" << endl;
				exit(EXIT_FAILURE);
			}
			for (int i = 0; i < boeking.size(); i++) {
				outBoekingFile << boeking.at(i)->toStringfile();
			}
			if (!outParkenFile) {
				cerr << "File could not be opened" << endl;
				exit(EXIT_FAILURE);
			}
			for (int i = 0; i < parken.size(); i++) {
				outParkenFile << parken.at(i)->toStringfile();
			}
			exit(0);
			break;
		}
		
		break;
	case 3:
		//baas
		cout << "\nWat wil je doen\n";
		cout << "1. Park creeren\n2. Park aanpassen\n3. Park verwijderen\n4. Accomodatie creeren\n5. Accomodatie aanpassen\n6. Accomodatie verwijderen\n7. Uitloggen\n";
		cin >> optie;
		getline(cin, trash);
			while (optie != 1 && optie != 2 && optie != 3 && optie != 4 && optie != 5 && optie != 6 && optie !=7) {
				cout << "1. Park creeren\n2. Park aanpassen\n3. Park verwijderen\n4. Accomodatie creeren\n5. Accomodatie aanpassen\n6. Accomodatie verwijderen\n7. Uitloggen\n";
				cin >> optie;
				getline(cin, trash);
			}
			switch (optie)
			{
			case 1:
				parken = nieuwpark(accomodatie, parken);
				
				break;
			case 2:
				parken = aanpassenpark(accomodatie, parken);
			
				break;
			case 3:
				parken = verwijderenpark(parken);
				
				break;
			case 4:
				 accomodatie = nieuweaccomodatie(accomodatie);
				 
				break;
			case 5:
				accomodatie = aanpassenaccomodatie(accomodatie);
				
				break;
			case 6:
				accomodatie = verwijderaccomodatie(accomodatie);
			
				break;
			case 7:
				x = 0;
				break;
			}
		break;
	case 4:
		//exit
		if (!outClientFile) {
			cerr << "File could not be opened" << endl;
			exit(EXIT_FAILURE);
		}
		for (int i = 0; i < klanten.size(); i++) {
			outClientFile << klanten.at(i).getklantid() << ' ' << klanten.at(i).getname() << ' ' << klanten.at(i).getpaswoord() << endl;
		}
		if (!outAccomodatieFile) {
			cerr << "File could not be opened" << endl;
			exit(EXIT_FAILURE);
		}
		for (int i = 0; i < accomodatie.size(); i++) {
			outAccomodatieFile << accomodatie.at(i)->toStringfile();
		}
		if (!outBoekingFile) {
			cerr << "File could not be opened" << endl;
			exit(EXIT_FAILURE);
		}
		for (int i = 0; i < boeking.size(); i++) {
			outBoekingFile << boeking.at(i)->toStringfile();
		}
		if (!outParkenFile) {
			cerr << "File could not be opened" << endl;
			exit(EXIT_FAILURE);
		}
		for (int i = 0; i < parken.size(); i++) {
			outParkenFile << parken.at(i)->toStringfile();
		}
		exit(0);
	}

	}

	return 0;
}
	
Klanten registreren(int id) {
		
		string naam;
		string paswoord;
		string trash;

		cout << "geef je naam: ";
		cin >> naam;
		getline(cin, trash);
		cout << "\ngeef een paswoord: ";
		cin >> paswoord;
		getline(cin, trash);
		Klanten klant1(id = id + 1, naam, paswoord);
		return klant1;
}
vector<Accomodatie*> nieuweaccomodatie(vector<Accomodatie*> acco) {
	int hobu;
	string trash;
	int id = acco.size();
	int tempvariable;
	string tmpvariable;
	bool tmpvar;
	bool bbq;
	bool beddenopmaakservice;
	bool ontbijt;
	bool blueray;
	cout << "Wil je een Hotel (1) of bungalow (2) aanmaken: ";
	cin >> hobu;
	getline(cin, trash);
	while (hobu != 1 && hobu != 2) {
		cout << "Wil je een Hotel (1) of bungalow (2) aanmaken: ";
		cin >> hobu;
		getline(cin, trash);
	}
	if (hobu == 1) {
		id++;
		Hotel* temproom = new Hotel();
		temproom->setaccomodatieid(id);
		temproom->setType(true);
		cout << "\nverdieping: ";
		cin >> tempvariable;
		getline(cin, trash);
		temproom->setverdiep(tempvariable);
		cout << "\nlocatie: ";
		cin >> tmpvariable;
		getline(cin,trash);
		temproom->setlocatie(tmpvariable);
		cout << "\naantalbedden: ";
		cin >> tempvariable;
		getline(cin, trash);
		temproom->setbedden(tempvariable);
		cout << "\nzijn er kinderbedden (1 = true): ";
		cin >> tmpvar;
		while(tmpvar != 0 && tmpvar != 1) {
			cout << "\ngeen juiste optie";
			cout << "\nzijn er kinderbedden (1 = true): ";
			cin >> tmpvar;
		}
		temproom->setaanwezigheidkinderbedden(tmpvar);
		cout << "\npersonen: ";
		cin >> tempvariable;
		getline(cin, trash);
		temproom->setpersonen(tempvariable);
		cout << "\noppervlakte: ";
		cin >> tempvariable;
		getline(cin, trash);
		temproom->setoppervlakte(tempvariable);
		cout << "\nis er een bad (1 = true): ";
		cin >> tmpvar;
		while (tmpvar != 0 && tmpvar != 1) {
			cout << "\ngeen juiste optie";
			cout << "\nis er een bad (1 = true): ";
			cin >> tmpvar;
		}
		temproom->setbad(tmpvar);
		cout << "\nprijs: ";
		cin >> tempvariable;
		getline(cin, trash);
		temproom->setprice(tempvariable);
		cout << "\naanwezigheid bbq (1 = true): ";
		cin >> bbq;
		while (bbq != 0 && bbq != 1) {
			cout << "\ngeen juiste optie";
			cout << "\naanwezigheid bbq (1 = true): ";
			cin >> bbq;
		}
		cout << "\naanwezigheid bluaray (1 = true): ";
		cin >> blueray;
		while (blueray != 0 && blueray != 1) {
			cout << "\ngeen juiste optie";
			cout << "\naanwezigheid bluaray (1 = true): ";
			cin >> blueray;
		}
		cout << "\naanwezigheid ontbijt (1 = true): ";
		cin >> ontbijt;
		while (ontbijt != 0 && ontbijt != 1) {
			cout << "\ngeen juiste optie";
			cout << "\naanwezigheid ontbijt (1 = true): ";
			cin >> ontbijt;
		}
		cout << "\naanwezigheid beddenopmaakservice (1 = true): ";
		cin >> beddenopmaakservice;
		while (beddenopmaakservice != 0 && beddenopmaakservice != 1) {
			cout << "\ngeen juiste optie";
			cout << "\naanwezigheid beddenopmaakservice (1 = true): ";
			cin >> beddenopmaakservice;
		}
		temproom->setluxelevelcomp(blueray, bbq, beddenopmaakservice, ontbijt);
		acco.push_back(temproom);
		return acco;
	}
	else {
		id++;
		Bungalow* tempbungalow = new Bungalow();
		tempbungalow->setaccomodatieid(id);
		tempbungalow->setType(false);
		cout << "\npersonen: ";
		cin >> tempvariable;
		getline(cin, trash);
		tempbungalow->setpersonen(tempvariable);
		cout << "\noppervlakte: ";
		cin >> tempvariable;
		getline(cin, trash);
		tempbungalow->setoppervlakte(tempvariable);
		cout << "\nis er een bad (1 = true): ";
		cin >> tmpvar;
		while (tmpvar != 0 && tmpvar != 1) {
			cout << "\ngeen juiste optie";
			cout << "\nis er een bad (1 = true): ";
			cin >> tmpvar;
		}
		tempbungalow->setbad(tmpvar);
		cout << "\nprijs: ";
		cin >> tempvariable;
		getline(cin, trash);
		tempbungalow->setprice(tempvariable);
		cout << "\naanwezigheid bbq (1 = true): ";
		cin >> bbq;
		while (bbq != 0 && bbq != 1) {
			cout << "\ngeen juiste optie";
			cout << "\naanwezigheid bbq (1 = true): ";
			cin >> bbq;
		}
		cout << "\naanwezigheid bluaray (1 = true): ";
		cin >> blueray;
		while (blueray != 0 && blueray != 1) {
			cout << "\ngeen juiste optie";
			cout << "\naanwezigheid bluaray (1 = true): ";
			cin >> blueray;
		}
		cout << "\naanwezigheid ontbijt (1 = true): ";
		cin >> ontbijt;
		while (ontbijt != 0 && ontbijt != 1) {
			cout << "\ngeen juiste optie";
			cout << "\naanwezigheid ontbijt (1 = true): ";
			cin >> ontbijt;
		}
		cout << "\naanwezigheid beddenopmaakservice (1 = true): ";
		cin >> beddenopmaakservice;
		while (beddenopmaakservice != 0 && beddenopmaakservice != 1) {
			cout << "\ngeen juiste optie";
			cout << "\naanwezigheid beddenopmaakservice (1 = true): ";
			cin >> beddenopmaakservice;
		}
		tempbungalow->setluxelevelcomp(blueray, bbq, beddenopmaakservice, ontbijt);
		acco.push_back(tempbungalow);
		return acco;

	}
	
}
vector<Accomodatie*> verwijderaccomodatie(vector<Accomodatie*> acco) {
	int x;
	string trash;
	cout << "\nwelke accomodatie wil je verwijderen: ";
	for (int i = 0; i < acco.size(); i++) {
		string accom = acco.at(i)->toString();
		cout << accom << endl;
	}
	cout << "\nGeef de accomodatie id die je wil verwijderen: ";
	cin >> x;
	getline(cin, trash);
	while (x > acco.size()) {
		cout << "\ngeen geldige accomodatieid";
		cout << "\nGeef de accomodatie id die je wil verwijderen: ";
		cin >> x;
		getline(cin, trash);
	}
	cout << "\nDeze accomodatie word verwijdert: \n";
	cout << acco.at(x)->toString();
	cout << "\nverwijderen...";
	cout << "\naccomodatie succesvol verwijdert";
	delete acco.at(x);
	return acco;
}
vector<Accomodatie*> aanpassenaccomodatie(vector<Accomodatie*> acco) {
	int z = 0;
	int optie = 0;
	int tempvariable;
	string tmpvariable;
	bool tmpvar;
	string trash;
	bool bbq;
	bool blueray;
	bool beddenopmaakservice;
	bool ontbijt;
	string accom;
	for (int i = 0; i < acco.size(); i++) {
		accom = acco.at(i)->toString();
		cout << accom << endl;
	}
		cout << "\nwelke accomodatie wil je aanpassen: ";
		cin >> z;
		getline(cin, trash);
		while (z > acco.size()) {
			cout << "\ngeen juiste optie";
			cout << "\nwelke accomodatie wil je aanpassen: ";
			cin >> z;
		}
		if (z == 0) {
			return acco;
		}
		cout << "\ngeselecteerde accomodatie: ";
		accom = acco.at(z-1)->toString();
		cout << accom;
		cout << "\nwat wil je aanpassen: ";
		if (acco.at(z-1)->getType() == 1) {
			//hotel
			Hotel* ptr = dynamic_cast<Hotel*> (acco.at(z-1));
			cout << "\n1. personen\n2. oppervlakte\n3. bad\n4. prijs\n5. blueray\n6. bbq\n7. beddenopmaakservice\n8. ontbijtservice\n9. verdiep\n10. locatie\n11. bedden\n12. aanwezigheidkinderbedden\n";
			cin >> optie;
			getline(cin, trash);
			while (optie != 1 && optie != 2 && optie != 3 && optie != 4 && optie != 5 && optie != 6 && optie != 7 && optie != 8 && optie != 9 && optie != 10 && optie != 11 && optie != 12) {
				cout << "\n geen juiste optie";
				cout << "\n1. personen\n2. oppervlakte\n3. bad\n4. prijs\n5. blueray\n6. bbq\n7. beddenopmaakservice\n8. ontbijtservice\n9. verdiep\n10. locatie\n11. bedden\n12. aanwezigheidkinderbedden\n";
				cin >> optie;
				getline(cin, trash);
			}
			switch (optie)
			{
			case 1:
				cout << "\nhoeveel personen: ";
				cin >> tempvariable;
				getline(cin, trash);
				ptr->setpersonen(tempvariable);
				break;
			case 2:
				cout << "\noppervlakte: ";
				cin >> tempvariable;
				getline(cin, trash);
				ptr->setoppervlakte(tempvariable);
				break;
			case 3:
				cout << "\nis er een bad (1 = true): ";
				cin >> tmpvar;
				while (tmpvar != 0 && tmpvar != 1) {
					cout << "\ngeen juiste optie";
					cout << "\nis er een bad (1 = true): ";
					cin >> tmpvar;
				}
				ptr->setbad(tmpvar);
				break;
			case 4:
				cout << "\nprijs: ";
				cin >> tempvariable;
				getline(cin, trash);
				ptr->setprice(tempvariable);
				break;
			case 5:
				cout << "\naanwezigheid blueray (1 = true): ";
				cin >> blueray;
				while (blueray != 0 && blueray != 1) {
					cout << "\ngeen juiste optie";
					cout << "\naanwezigheid blueray (1 = true): ";
					cin >> blueray;
				}
				ptr->setluxelevelblueray(blueray);
				break;
			case 6:
				cout << "\naanwezigheid bbq (1 = true): ";
				cin >> bbq;
				while (bbq != 0 && bbq != 1) {
					cout << "\ngeen juiste optie";
					cout << "\naanwezigheid bbq (1 = true): ";
					cin >> bbq;
				}
				ptr->setluxelevelbbq(bbq);
				break;
			case 7:
				cout << "\naanwezigheid beddenopmaakservice (1 = true): ";
				cin >> beddenopmaakservice;
				while (beddenopmaakservice != 0 && beddenopmaakservice != 1) {
					cout << "\ngeen juiste optie";
					cout << "\naanwezigheid beddenopmaakservice (1 = true): ";
					cin >> beddenopmaakservice;
				}
				ptr->setluxelevelopruimen(beddenopmaakservice);
				break;
			case 8:
				cout << "\naanwezigheid ontbijt (1 = true): ";
				cin >> ontbijt;
				while (ontbijt != 0 && ontbijt != 1) {
					cout << "\ngeen juiste optie";
					cout << "\naanwezigheid ontbijt (1 = true): ";
					cin >> ontbijt;
				}
				ptr->setluxeleveleten(ontbijt);
				break;
			case 9:
				cout << "\nverdiep: ";
				cin >> tempvariable;
				getline(cin, trash);
				ptr->setverdiep(tempvariable);
				break;
			case 10:
				cout << "\nlocatie: ";
				cin >> tmpvariable;
				getline(cin, trash);
				ptr->setlocatie(tmpvariable);
				break;
			case 11:
				cout << "\nbedden: ";
				cin >> tempvariable;
				getline(cin, trash);
				ptr->setbedden(tempvariable);
				break;
			case 12:
				cout << "\naanwezigheidkinderbedden: ";
				cout << "\nzijn er kinderbedden (1 = true): ";
				cin >> tmpvar;
				while (tmpvar != 0 && tmpvar != 1) {
					cout << "\ngeen juiste optie";
					cout << "\nzijn er kinderbedden (1 = true): ";
					cin >> tmpvar;
				}
				ptr->setaanwezigheidkinderbedden(tmpvar);
				break;
			}
			acco.at(z-1) = ptr;
			return acco;

		}
		else {
			//bungalow
			Bungalow* ptr = dynamic_cast<Bungalow*> (acco.at(z-1));
			cout << "\n1. personen\n2. oppervlakte\n3. bad\n4. prijs\n5. blueray\n6. bbq\n7. beddenopmaakservice\n8. ontbijtservice\n9. slaapkamers\n";
			cin >> optie;
			getline(cin, trash);
			while (optie != 1 && optie != 2 && optie != 3 && optie != 4 && optie != 5 && optie != 6 && optie != 7 && optie != 8 && optie != 9 && optie ) {
				cout << "\n geen juiste optie";
				cout << "\n1. personen\n2. oppervlakte\n3. bad\n4. prijs\n5. blueray\n6. bbq\n7. beddenopmaakservice\n8. ontbijtservice\n9. slaapkamers\n";
				cin >> optie;
				getline(cin, trash);
			}
			switch (optie)
			{
			case 1:
				cout << "\nhoeveel personen: ";
				cin >> tempvariable;
				getline(cin, trash);
				ptr->setpersonen(tempvariable);
				break;
			case 2:
				cout << "\noppervlakte: ";
				cin >> tempvariable;
				getline(cin, trash);
				ptr->setoppervlakte(tempvariable);
				break;
			case 3:
				cout << "\nis er een bad (1 = true): ";
				cin >> tmpvar;
				while (tmpvar != 0 && tmpvar != 1) {
					cout << "\ngeen juiste optie";
					cout << "\nis er een bad (1 = true): ";
					cin >> tmpvar;
				}
				ptr->setbad(tmpvar);
				break;
			case 4:
				cout << "\nprijs: ";
				cin >> tempvariable;
				getline(cin, trash);
				ptr->setprice(tempvariable);
				break;
			case 5:
				cout << "\naanwezigheid blueray (1 = true): ";
				cin >> blueray;
				while (blueray != 0 && blueray != 1) {
					cout << "\ngeen juiste optie";
					cout << "\naanwezigheid blueray (1 = true): ";
					cin >> blueray;
				}
				ptr->setluxelevelblueray(blueray);
				break;
			case 6:
				cout << "\naanwezigheid bbq (1 = true): ";
				cin >> bbq;
				while (bbq != 0 && bbq != 1) {
					cout << "\ngeen juiste optie";
					cout << "\naanwezigheid bbq (1 = true): ";
					cin >> bbq;
				}
				ptr->setluxelevelbbq(bbq);
				break;
			case 7:
				cout << "\naanwezigheid beddenopmaakservice (1 = true): ";
				cin >> beddenopmaakservice;
				while (beddenopmaakservice != 0 && beddenopmaakservice != 1) {
					cout << "\ngeen juiste optie";
					cout << "\naanwezigheid beddenopmaakservice (1 = true): ";
					cin >> beddenopmaakservice;
				}
				ptr->setluxelevelopruimen(beddenopmaakservice);
				break;
			case 8:
				cout << "\naanwezigheid ontbijt (1 = true): ";
				cin >> ontbijt;
				while (ontbijt != 0 && ontbijt != 1) {
					cout << "\ngeen juiste optie";
					cout << "\naanwezigheid ontbijt (1 = true): ";
					cin >> ontbijt;
				}
				ptr->setluxeleveleten(ontbijt);
				break;
			case 9:
				cout << "\nslaapkamers: ";
				cin >> tempvariable;
				getline(cin, trash);
				ptr->setaantalslaapkamers(tempvariable);
				break;
			}
			acco.at(z-1) = ptr;
			return acco;
		}
}
vector<Parken*> nieuwpark(vector<Accomodatie*> acco, vector<Parken*> park) {
	int parkid = park.size();
	string tempvar;
	bool tempvariable;
	int price = 0;
	bool zwembad = 0;
	bool bowling = 0;
	bool sport = 0;
	bool fietsen = 0;
	bool kinderparadijs = 0;
	bool waterfietsen = 0; 
	int x;
	string trash;
	vector<Services> service;
	vector<Accomodatie*> accomo;
	Parken* tmppark = new Parken();
	parkid++;
	tmppark->setparkid(parkid);
	cout << "\ngeef een parknaam: ";
	getline(cin, tempvar);
	tmppark->setparknaam(tempvar);
	cout << "\ngeef een locatie: ";
	getline(cin, tempvar);
	tmppark->setlocatie(tempvar);
	cout << "\nwelke accomodaties wil je toevoegen (0 om te stoppen): ";
	for (int i = 0; i < acco.size(); i++) {
		string accom = acco.at(i)->toString();
		cout << accom << endl;
	}
	cin >> x;
	getline(cin, trash);
	while (x != 0 && x <= acco.size()) {
		accomo.push_back(acco.at(x - 1));
		cout << "\nwelke accomodaties wil je toevoegen (0 om te stoppen): ";
		cin >> x;
		getline(cin, trash);
	}
	tmppark->setaccomodatie(accomo);
	cout << "\nis er een subtropische zwembad (1 = true): ";
	cin >> zwembad;
	getline(cin, trash);
	while (zwembad != 0 && zwembad != 1) {
		cout << "\ngeen juiste optie";
		cout << "\nis er een subtropische zwembad (1 = true): ";
		cin >> zwembad;
		getline(cin, trash);
	}
	cout << "\nis er een sportinfrastructuur(1 = true): ";
	cin >> sport;
	getline(cin, trash);
	while (sport != 0 && sport != 1) {
		cout << "\ngeen juiste optie";
		cout << "\nis er een sportinfrastructuur (1 = true): ";
		cin >> sport;
		getline(cin, trash);
	}
	cout << "\nis er een bowlingbaan (1 = true): ";
	cin >> bowling;
	getline(cin, trash);
	while (bowling != 0 && bowling != 1) {
		cout << "\ngeen juiste optie";
		cout << "\nis er een bowlingbaan (1 = true): ";
		cin >> bowling;
		getline(cin, trash);
	}
	cout << "\nis er een fietsverhuur (1 = true): ";
	cin >> fietsen;
	getline(cin, trash);
	while (fietsen != 0 && fietsen != 1) {
		cout << "\ngeen juiste optie";
		cout << "\nis er een fietsverhuur (1 = true): ";
		cin >> fietsen;
		getline(cin, trash);
	}
	cout << "\nis er een kinderparadijs (1 = true): ";
	cin >> kinderparadijs;
	getline(cin, trash);
	while (kinderparadijs != 0 && kinderparadijs != 1) {
		cout << "\ngeen juiste optie";
		cout << "\nis er een kinderparadijs (1 = true): ";
		cin >> kinderparadijs;
		getline(cin, trash);
	}
	cout << "\nzijn er waterfietsen (1 = true): ";
	cin >> waterfietsen;
	getline(cin, trash);
	while (waterfietsen != 0 && waterfietsen != 1) {
		cout << "\ngeen juiste optie";
		cout << "\nzijn er waterfietsen (1 = true): ";
		cin >> waterfietsen;
		getline(cin, trash);
	}
	cout << "\nhoeveel kosten de services: ";
	cin >> price;
	getline(cin, trash);

	
	Services service1(zwembad, sport, bowling, fietsen, kinderparadijs, waterfietsen, price);
	tmppark->setservice(service1);
	park.push_back(tmppark);
	return park;
}
vector<Parken*> aanpassenpark(vector<Accomodatie*> acco, vector<Parken*> park) {
	int x;
	int z;
	int optie;
	string trash;
	bool zwembad;
	bool sport;
	bool fietsen;
	bool bowling;
	bool kinderparadijs;
	bool waterfietsen;
	int price;
	string naam;
	string locatie;
	vector<Accomodatie*> accomo;
	Services service;
	cout << "\nwelk park wil je aanpassen: ";
	for (int i = 0; i < park.size(); i++) {
		string parke = park.at(i)->toString();
		cout << parke << endl;
	}
	cin >> z;
	getline(cin, trash);
	while (z > park.size()) {
		cout << "\ngeen juiste optie";
		cout << "\nwelk park wil je aanpassen: ";
		cin >> z;
	}
	cout << "\nwat wil je aanpassen: ";
	cout << "\n1. parknaam\n2. locatie\n3. accomodaties\n4. services\n5. return\n";
	cin >> x;
	getline(cin, trash);
	while (x != 1 && x != 2 && x != 3 && x != 4 && x != 5) {
		cout << "\nwat wil je aanpassen: ";
		cout << "\n1. parknaam\n2. locatie\n3. accomodaties\n4. services\n5. return\n";
		cin >> x;
		getline(cin, trash);
	}
	switch (x)
	{
	case 1:
		cout << "\ngeef een nieuwe parknaam: ";
		getline(cin, naam);
		park.at(z - 1)->setparknaam(naam);
		break;
	case 2:
		cout << "\ngeef een nieuwe locatie: ";
		getline(cin, locatie);
		park.at(z - 1)->setlocatie(locatie);
		break;
	case 3:
		cout << "\nwelke accomodaties wil in dit park(0 om te stoppen): ";
		for (int i = 0; i < acco.size(); i++) {
			string accom = acco.at(i)->toString();
			cout << accom << endl;
		}
		cin >> x;
		getline(cin, trash);
		while (x != 0 && x <= acco.size()) {
			accomo.push_back(acco.at(x - 1));
		}
		park.at(z - 1)->setaccomodatie(accomo);
		break;
	case 4:
		cout << "\nwelke service wil je veranderen: ";
		cout << "\n1. subtropische zwembad\n2. sportinfrastructuur\n3. fietsenverhuur\n4. bowling\n5. kinderparadijs\n6. waterfietsen\n7. prijs";
		cin >> optie;
		getline(cin, trash);
		while (optie != 1 && optie != 2 && optie != 3 && optie != 4 && optie != 5 && optie != 6 && optie !=7)
		{
			cout << "\nwelke service wil je veranderen: ";
			cout << "\n1. subtropische zwembad\n2. sportinfrastructuur\n3. fietsenverhuur\n4. bowling\n5. kinderparadijs\n6. waterfietsen\n7. prijs";
			cin >> optie;
			getline(cin, trash);
		}
		switch (optie)
		{
		case 1:
			cout << "\nis er een subtropische zwembad (1 = true): ";
			cin >> zwembad;
			getline(cin, trash);
			while (zwembad != 0 && zwembad != 1) {
				cout << "\ngeen juiste optie";
				cout << "\nis er een subtropische zwembad (1 = true): ";
				cin >> zwembad;
				getline(cin, trash);
			}
			service = park.at(z - 1)->getservice();
			service.setzwembad(zwembad);
			park.at(z - 1)->setservice(service);
			break;
		case 2:
			cout << "\nis er een sportinfrastructuur(1 = true): ";
			cin >> sport;
			getline(cin, trash);
			while (sport != 0 && sport != 1) {
				cout << "\ngeen juiste optie";
				cout << "\nis er een sportinfrastructuur (1 = true): ";
				cin >> sport;
				getline(cin, trash);
			}
			service = park.at(z - 1)->getservice();
			service.setsport(sport);
			park.at(z - 1)->setservice(service);
			break;
		case 3:
			cout << "\nis er een fietsverhuur (1 = true): ";
			cin >> fietsen;
			getline(cin, trash);
			while (fietsen != 0 && fietsen != 1) {
				cout << "\ngeen juiste optie";
				cout << "\nis er een fietsverhuur (1 = true): ";
				cin >> fietsen;
				getline(cin, trash);
			}
			service = park.at(z - 1)->getservice();
			service.setfietsen(fietsen);
			park.at(z - 1)->setservice(service);
			break;
		case 4:
			cout << "\nis er een bowlingbaan (1 = true): ";
			cin >> bowling;
			getline(cin, trash);
			while (bowling != 0 && bowling != 1) {
				cout << "\ngeen juiste optie";
				cout << "\nis er een bowlingbaan (1 = true): ";
				cin >> bowling;
				getline(cin, trash);
			}
			service = park.at(z - 1)->getservice();
			service.setbowling(bowling);
			park.at(z - 1)->setservice(service);
			break;
		case 5:
			cout << "\nis er een kinderparadijs (1 = true): ";
			cin >> kinderparadijs;
			getline(cin, trash);
			while (kinderparadijs != 0 && kinderparadijs != 1) {
				cout << "\ngeen juiste optie";
				cout << "\nis er een kinderparadijs (1 = true): ";
				cin >> kinderparadijs;
				getline(cin, trash);
			}
			service = park.at(z - 1)->getservice();
			service.setkinderparadijs(kinderparadijs);
			park.at(z - 1)->setservice(service);
			break;
		case 6:
			cout << "\nzijn er waterfietsen (1 = true): ";
			cin >> waterfietsen;
			getline(cin, trash);
			while (waterfietsen != 0 && waterfietsen != 1) {
				cout << "\ngeen juiste optie";
				cout << "\nzijn er waterfietsen (1 = true): ";
				cin >> waterfietsen;
				getline(cin, trash);
			}
			service = park.at(z - 1)->getservice();
			service.setwaterfietsen(waterfietsen);
			park.at(z - 1)->setservice(service);
			break;
		case 7: 
			cout << "\nhoeveel kosten de services: ";
			cin >> price;
			getline(cin, trash);
			service = park.at(z - 1)->getservice();
			service.setserviceprice(price);
			park.at(z - 1)->setservice(service);
			break;
		}
		break;
	case 5:
		return park;
	}
	return park;
}
vector<Parken*> verwijderenpark(vector<Parken*> park) {
	int x;
	string trash;
	cout << "\nwelk park wil je verwijderen: ";
	for (int i = 0; i < park.size(); i++) {
		string parke = park.at(i)->toString();
		cout << parke << endl;
	}
	cout << "\nGeef de park id die je wil verwijderen: ";
	cin >> x;
	getline(cin, trash);
	while (x > park.size()) {
		cout << "\ngeen geldige parkid";
		cout << "\nGeef de park id die je wil verwijderen: ";
		cin >> x;
		getline(cin, trash);
	}
	cout << "\nDit park word verwijdert: \n";
	cout << park.at(x-1)->toString();
	cout << "\nverwijderen...";
	cout << "\npark succesvol verwijdert";
	delete park.at(x-1);
	return park;
}
vector<Boeking*> nieuweboeking(Klanten klant, vector<Parken*> park, vector<Boeking*> boek) {
	int id = boek.size();
	int x,z;
	int prijs;
	string datum;
	string trash;
	Services services;
	vector<Accomodatie*> accomo;
	Boeking* tmpboek = new Boeking();
	id++;
	cout << "\nDag " << klant.getname() << "\nop welke datum wil je boeken(aan elkaar): ";
	getline(cin, datum);
	cout << "\nIn welk park wil je boeken: ";
	for (int i = 0; i < park.size(); i++) {
		string parke = park.at(i)->toStringboeking();
		cout << parke << endl;
	}
	cout << "\nGeef de park id: ";
	cin >> z;
	getline(cin, trash);
	while (z > park.size()) {
		cout << "\ngeen geldige parkid";
		cout << "\nGeef de park id: ";
		cin >> z;
		getline(cin, trash);
	}
	if (z == 0) {
		return boek;
	}
	cout << "\nwelke accomodatie wil je boeken: ";
	accomo = park.at(z-1)->getaccomodatie();
	for (int i = 0; i < accomo.size(); i++) {
		cout << accomo.at(i)->toString();
	}
	cout << "\nGeef de accomodatie id: ";
	cin >> x;
	getline(cin, trash);
	while (x > accomo.size()) {
		cout << "\ngeen geldige accomodatieid";
		cout << "\nGeef de accomodatie id: ";
		cin >> x;
		getline(cin, trash);
	}
	services = park.at(z-1)->getservice();
	prijs = services.getserviceprice() + accomo.at(x-1)->getprice();
	cout << "\n" << accomo.at(x - 1)->toString() << "\nis geboekt\n";
	tmpboek->setaccomodatie(accomo.at(x-1));
	tmpboek->setboekingid(id);
	tmpboek->setklanten(klant);
	tmpboek->setdatum(datum);
	tmpboek->setprijs(prijs);
	boek.push_back(tmpboek);
	return boek;
}
vector<Boeking*> aanpassenboeking(vector<Parken*> park, vector<Boeking*> boek) {
	int x,z,y;
	string trash;
	string datum;
	string boekout;
	vector<Accomodatie*> accomo;
	cout << "\nwelke boeking wil je aanpassen: ";
	for (int i = 0; i < boek.size(); i++) {
		boekout = boek.at(i)->toString();
		cout << boekout << endl;
	}
	cout << "\nGeef de boekingsid die je wil aanpassen: ";
	cin >> x;
	getline(cin, trash);
	while (x > boek.size()) {
		cout << "\ngeen geldig boekingsid";
		cout << "\nGeef de boekingsid die je wil aanpassen: ";
		cin >> x;
		getline(cin, trash);
	}
	if (x == 0) {
		return boek;
	}
	cout << "\nwat wil je aanpassen: ";
	cout << "\n1. accomodatie\n2. datum ";
	cin >> z;
	getline(cin, trash);
	while (z != 1 && z != 2) {
		cout << "\ngeen juiste optie";
		cout << "\nwat wil je aanpassen: ";
		cout << "\n1. accomodatie\n2. datum ";
		cin >> z;
		getline(cin, trash);
	}
	if (z == 1) {
		cout << "\nin welk park wil je boeken: ";
		for (int i = 0; i < park.size(); i++) {
			string parke = park.at(i)->toString();
			cout << parke << endl;
		}
		cout << "\nGeef de park id: ";
		cin >> y;
		getline(cin, trash);
		while (y > park.size()) {
			cout << "\ngeen geldige parkid";
			cout << "\nGeef de park id: ";
			cin >> y;
			getline(cin, trash);
		}
		while (y > park.size()) {
			cout << "\ngeen geldige parkid";
			cout << "\nGeef de park id: ";
			cin >> y;
			getline(cin, trash);
		}
		cout << "\nwelke accomodatie wil je boeken: ";
		accomo = park.at(y-1)->getaccomodatie();
		for (int i = 0; i < accomo.size(); i++) {
			cout << accomo.at(i)->toString();
		}
		cout << "\nGeef de accomodatie id: ";
		cin >> y;
		getline(cin, trash);
		while (y > accomo.size()) {
			cout << "\ngeen geldige accomodatieid";
			cout << "\nGeef de accomodatie id: ";
			cin >> y;
			getline(cin, trash);
		}
		boek.at(x-1)->setaccomodatie(accomo.at(y - 1));
	}
	else {
		cout << "\nnaar welke datum wil je de boeking veranderen(aan elkaar ): ";
		getline(cin, datum);
		boek.at(x - 1)->setdatum(datum);
	}
	return boek;
};
vector<Boeking*> verwijderenboeking(vector<Boeking*> boek) {
	int x;
	string trash;
	string boekout;
	cout << "\nwelke boeking wil je verwijderen: ";
	for (int i = 0; i < boek.size(); i++) {
		boekout = boek.at(i)->toString();
		cout << boekout << endl;
	}
	cout << "\nGeef de boekingsid die je wil verwijderen: ";
	cin >> x;
	getline(cin, trash);
	while (x > boek.size()) {
		cout << "\ngeen geldig boekingsid";
		cout << "\nGeef de boekingsid die je wil verwijderen: ";
		cin >> x;
		getline(cin, trash);
	}
	if (x == 0) {
		return boek;
	}
	cout << "\ndeze boeking word verwijdert: \n";
	cout << boek.at(x - 1)->toString();
	cout << "\nverwijderen...";
	cout << "\nboeking succesvol verwijdert";
	delete boek.at(x - 1);

	return boek;
};