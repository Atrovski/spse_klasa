#include "kniha.h"
#include <vector>

Kniha::Kniha()
{
	ID = 0;
	nazev = "";
	cena = 0.0;
}

Kniha::Kniha(int id, std::string nazevKniha, float cenaKniha)
{
	ID = id;
	nazev = nazevKniha;
	cena = cenaKniha;
}

int Kniha::getID() const
{
	return ID;
}

std::string Kniha::getNazev() const
{
	return nazev;
}

float Kniha::getCena() const
{
	return cena;
}

std::ostream& operator<< (std::ostream &out, const Kniha &kniha)
{
	out << "ID knihy: " << kniha.ID << std::endl;
	out << "Nazev knihy: " << kniha.nazev << std::endl;
	out << "Cena knihy: " << kniha.cena << std::endl;
	
	return out;
}

std::istream& operator>> (std::istream &in, Kniha &kniha)
{
	std::cout << "Zadejte ID knihy: ";
	in >> kniha.ID;
	fflush(stdin);
	std::cout << "Zadejte nazev knihy: ";
	getline(in,kniha.nazev);
	std::cout << "Zadejte cenu knihy: ";
	in >> kniha.cena;
	
	return in;
}
Knihovna::Knihovna()
{
	// Prázdný konstruktor
}

void Knihovna::pridatKniha(Kniha kniha)
{
	knihy.push_back(kniha);
}

void Knihovna::vypisKnih()
{
	std::cout << "knihovna obsahuje nasledujici knihy:" << std::endl;
	
	for (int i = 0; i < knihy.size(); i++)
	{
		std::cout << knihy[i];
	}
}
Kniha Knihovna::najitKniha(std::string nazev)
{
	for (int i = 0; i < knihy.size(); i++)
	{
		if (knihy[i].getNazev() == nazev)
		{
			return knihy[i];
		}
	}
	
	return Kniha();
}

