#include <iostream>
#include "hlavicka.h"

// Mohl jsem implementovat do uzivatelske nabidky, aby uzivatel mohl zadavat casy do aleluja, dokud neukonci program
// Z Testovacich duvodu ve škole jsem tak neučinil
// @author Atrovski

int main() {
	Time t1,t2,vysl;
	cin >> t1;
	cout << "Prvni cas je:";
	cout << t1 << endl;
	cin >> t2;
	cout << "Druhy cas je:";
	cout << t2 << endl;

	cout << "1- Scitani casu" << endl;
	cout << "2- Odcitani casu" << endl;
	cout << "3- Porovnani casu" << endl;
	cout << "0- Odchod z programu" << endl;
	int volba;
	do{															//Zacatek smycky do, aby se program mohl opakovat do aleluja
		cin >> volba;
		switch (volba) {
		case 1:
			vysl = t1 + t2;
			cout << "Vysledek scitani casu: "<< vysl <<endl;	//Vysledek je osetreny zpatky do 24h soustavy, aby nedoslo k preteceni casu
			break;
		case 2:
			vysl = t1 - t2;
			cout << "Vysledek odcitani casu: "<< vysl <<endl;   //Vysledek se automaticky prevadi zpet do kladnych hodnot
			break;
		case 3:
			porovnavani(t1,t2);
			break;
		}
	}while(volba!=0);											//Pokud uzivatel zada 0 podle uz. nabidky, program se ukonci
	return 0;
}
