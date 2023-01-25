#include "hlavicka.h"
#include <iostream>

using namespace std;
Time::Time()
{
	this->hours = 0;															//Nastaveni pocatecnich hodin na 0 z predeslych testovacich duvodu
	this->minutes = 0;															//Nastaveni pocatecnich minut na 0 z predeslych testovacich duvodu
	this->seconds = 0;															//Nastaveni pocatecnich sekund na 0 z predeslych testovacich duvodu
}

ostream& operator << (ostream& output, Time& content){
	
		output << content.hours << ":" << content.minutes << ":" << content.seconds;			//Output nastavi nas cas - Mohl bych zlepsit format vypisu
		return output;																			//Vracime output
}

istream& operator >> (istream& input, Time& content)
{
	do {
		cout << "Zadej hodiny: " << endl;
		input >> content.hours;
		if (content.hours < 0 || content.hours > 24) {							//Osetreni hodin. Mohl bych zmenit na 0-23, jelikoz 24hodin je 00
			cout << "Hodiny musi byt v rozmezi 0-24" << endl;					//Chybova hlaska pro hodiny
		}
	} while (content.hours < 0 || content.hours > 24);
	do {
		cout << "Zadej minuty: " << endl;
		input >> content.minutes;
		if (content.minutes < 0 || content.minutes > 60) {						//Osetreni minut
			cout << "Minuty musi byt v rozmezi 0-60" << endl;					//Chybova hlaska pro minuty
		}
	} while (content.minutes < 0 || content.minutes > 60);
	do {
		cout << "Zadej sekundy: " << endl;										
		input >> content.seconds;
		if (content.seconds < 0 || content.seconds > 60) {						//Osetreni sekund
			cout << "Sekundy musi byt v rozmezi 0-60" << endl;					//Chybova hlaska pro sekundy
		}
	} while (content.seconds < 0 || content.seconds > 60);	
}
Time operator + (Time a, Time b)
{
	Time vys;
	vys.seconds = (a.seconds + b.seconds) % 60;									//Pouzivame %60, kdyz dojde k souctu vetsimu jak 60s tak jsme jakoby v "dalsi minute"
	int help = (a.seconds + b.seconds) / 60;
	vys.minutes = (a.minutes + b.minutes + help) % 60;							//Pouzivame %60, kdyz dojde k souctu vetsimu jak 60m tak jsme jakoby v "dalsi hodine"
	help = (a.minutes + b.minutes + help) / 60;
	vys.hours = (a.hours + b.hours + help) % 24;								//Pouzivame %24, kdyz dojde k souctu vetsimu jak 24h tak jsme jakoby v "dalsim dni"
	return vys;
}

Time operator - (Time a, Time b)
{
	Time vys;
	vys.seconds = a.seconds - b.seconds;
	vys.minutes = a.minutes - b.minutes;
	vys.hours = a.hours - b.hours;
	if (vys.seconds < 0) {														//Osetreni proto, kdyz odecteme vice sekund od mene, tak se odecte i 1 minuta
		vys.seconds += 60;
		vys.minutes--;
	}
	if (vys.minutes < 0) {														//Osetreni proto, kdyz odecteme vice minut od mene, tak se odecte i 1 hodina
		vys.minutes += 60;
		vys.hours--;
	}
	if (vys.hours < 0) {														//Osetreni proto, kdyz odecteme vice hodin od mene, tak se odecte i 1 hodina
		vys.hours += 24;														//Když přejdeme s hodinami přes 0, nastavi se zpatky na 24h jako minuly den
	}
	
	if (vys.hours < 0 || vys.minutes < 0 || vys.seconds < 0) {
		if (vys.hours < 0) vys.hours = -vys.hours;
		if (vys.minutes < 0) vys.minutes = -vys.minutes;
		if (vys.seconds < 0) vys.seconds = -vys.seconds;
		cout << "-";
	}
	return vys;
}

void porovnavani(Time a, Time b) {												//Funkce pro porovnavani casu
	if (a.hours > b.hours) {													//Pokud jsou hodiny prvniho casu vetsi jak druheho, automaticky cas1 > cas2
		cout << "cas1 > cas2" << endl;
	}
	else if (a.hours < b.hours) {												//Pokud jsou hodiny druheho casu vetsi jak prvniho, automaticky cas2 < cas1
		cout << "cas2 > cas1" << endl;
	}
	else {
		if (a.minutes > b.minutes) {											//Pokud jsou hodiny stejne, resime minuty atd.. atd..
			cout << "cas1 > cas2" << endl;
		}
		else if (a.minutes < b.minutes) {
			cout << "cas2 > cas1" << endl;
		}
		else {
			if (a.seconds > b.seconds) {
				cout << "cas1 > cas2" << endl;
			}
			else if (a.seconds < b.seconds) {
				cout << "cas2 > cas1" << endl;
			}
			else {
				cout << "cas1 = cas2" << endl;									//Pokud jsou hodiny, minuty i sekundy stejne, casy jsou si rovny
			}
		}
	}
}

