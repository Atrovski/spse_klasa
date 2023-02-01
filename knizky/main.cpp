#include <iostream>
#include "kniha.h"

int main()
{
	Knihovna knihovna;
	int volba;
	
	do
	{
		std::cout << "Vyberte volbu:" << std::endl;
		std::cout << "1. Pridat knihu" << std::endl;
		std::cout << "2. Vypisovat knihy" << std::endl;
		std::cout << "3. Hledat knihu" << std::endl;
		std::cout << "0. Konec programu" << std::endl;
		
		std::cin >> volba;
		
		if (volba == 1)
		{
			int id;
			std::string nazev;
			double cena;
			
			std::cout << "Zadejte ID knihy: ";
			std::cin >> id;
			
			std::cout << "Zadejte nazev knihy: ";
			std::cin >> nazev;
			
			std::cout << "Zadejte cenu knihy: ";
			std::cin >> cena;
			
			Kniha kniha(id, nazev, cena);
			knihovna.pridatKniha(kniha);
		}
		else if (volba == 2)
		{
			knihovna.vypisKnih();
		}
	else if (volba == 3)
	{
		Kniha hledanaKniha;
		std::string nazev;
		
		std::cout << "Zadejte nazev hledane knihy: ";
		std::cin >> nazev;
		
		hledanaKniha = knihovna.najitKniha(nazev);
		
		if (hledanaKniha.getID() != 0)
		{
			std::cout << "Nalezena kniha: " << hledanaKniha;
		}
		else
		{
			std::cout << "Kniha s nazvem '" << nazev << "' nebyla nalezena." << std::endl;
		}
	}
	} while (volba != 0);
	
	return 0;
}
