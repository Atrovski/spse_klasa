#include "hlavicka.h"

int main() {
	Zlomek zlom1, zlom2, vysledek;  //Deklarace promennych
	
	int volba;

	cout << " ZADAVANI PRVNIHO ZLOMKU " << endl;		
	cin >> zlom1;                   //Nacteni zlomku 1 z klavesnice
	cout << zlom1 << endl;			//Vypis zlomku 1
	
	
	cout << " ZADAVANI DRUHEHO ZLOMKU " << endl;
	cin >> zlom2; 					//Nacteni zlomku 2 z klavesnice
	cout << zlom2 << endl;			//Vypis zlomku 2
	
	cout << "1- Scitani zlomku" << endl;
	cout << "2- Odcitani zlomku" << endl;
	cout << "3- Nasobeni zlomku" << endl;
	cout << "4- Deleni zlomku" << endl;
	cout << "5- Porovnavani zlomku" << endl;
	cout << "6- Celociselna mocnina zlomku" << endl;
	do{
	cin >> volba;
	switch (volba) {
	case 1:
		vysledek = zlom1 + zlom2;
		cout << "Vysledek scitani zlomku: "<< vysledek <<endl;
		break;
	case 2:
		vysledek = zlom1 - zlom2;
		cout << "Vysledek odcitani zlomku: "<< vysledek <<endl;
		break;
	case 3:
		vysledek = zlom1 * zlom2;
		cout << "Vysledek nasobeni zlomku: "<< vysledek  <<endl;
		break;
	case 4:
		vysledek = zlom1 / zlom2;
		cout << "Vysledek deleni zlomku: "<< vysledek <<endl;
		break;
	case 5:
		porovnavani(zlom1, zlom2);
		break;
	case 6:
		zlom1.mocnina();
		cout << "Vysledek celociselne mocniny prvniho zlomku: " << zlom1 << endl;
		break;
	}
	}while(volba!=0);
}
