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
		std::cout << "4. Ulozit knihy do souboru" << std::endl;
		std::cout << "5. Nacist ze souboru" << std::endl;
		std::cout << "6. Vypise knihu s nejmensi cenou" << std::endl;
		std::cout << "7. Vypise knihu s nejvetsi cenou" << std::endl;
		std::cout << "8. Seradi knihy podle nejlevnejsi (Musite opetovne vypsat knihy [2])" << std::endl;
		std::cout << "9. Seradi knihy podle nejdrazsi (Musite opetovne vypsat knihy [2])" << std::endl;
		std::cout << "10. Umozni editovat knihu" << std::endl;
		std::cout << "0. Konec programu" << std::endl;
		
		std::cin >> volba;
		fflush(stdin);
		if (volba == 1)
		{
			int id;
			std::string nazev;
			double cena;
			
			std::cout << "Zadejte ID knihy: ";
			std::cin >> id;
			
			std::cout << "Zadejte nazev knihy: ";
			fflush(stdin);
			getline(std::cin,nazev);
			
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
		fflush(stdin);
		getline(std::cin,nazev);
		
		hledanaKniha = knihovna.najitKniha(nazev);
		
		if (hledanaKniha.getID() != 0)
		{
			std::cout << "Nalezena kniha: " << std::endl << hledanaKniha;
		}
		else
		{
			std::cout << "Kniha s nazvem '" << nazev << "' nebyla nalezena." << std::endl;
		}
	}
	else if (volba == 4)
	{
		knihovna.savetofile();
	}
	else if (volba == 5)
	{
		knihovna.loadfromfile();
	}
	else if (volba == 6)
	{
		knihovna.lowestPrice();
	}
	else if (volba == 7)
	{	
		knihovna.highestPrice();
	}
	else if (volba == 8)
	{
		knihovna.sortByPrice();
	}
	else if (volba == 9)
	{
		knihovna.sortByPriceDescending();
	}
	/*
	else if (volba == 10)
	{
		int id;
		int newID, newCena;
		std::string newNazev;
	    knihovna.editBook(id, newID, newNazev, newCena);
	}
	*/
	} while (volba != 0);
	
	return 0;
}
