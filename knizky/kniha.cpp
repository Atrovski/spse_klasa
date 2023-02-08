#include "kniha.h"
#include <vector>
#include <sstream>
#include <algorithm>

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
bool Knihovna::savetofile(){
	int i=0;
	std::ofstream file;
	file.open("knihy.txt");
	if(file.fail()){
		return false;
	}
	for(i=0;i<knihy.size();i++){
		file<<knihy[i].getID()<<"/"<<knihy[i].getNazev()<<"/"<<knihy[i].getCena()<< "/" << std::endl;
	}
	file.close();
}
bool Knihovna::loadfromfile()
{
	int id;
	std::string nazev;
	double cena;
	std::string radek;
	std::ifstream file("knihy.txt");
	if(file.fail())
	{
		return false;
	}
	
	while (std::getline(file, radek))
	{
		std::istringstream ss(radek);
		std::string line;
		std::getline(ss, line, '/');
		id = std::stoi(line);
		std::getline(ss, nazev, '/');
		std::string cena_str;
		getline(ss, cena_str, '/');
		cena = stoi(cena_str);
		
		Kniha kniha(id, nazev, cena);
		knihy.push_back(kniha);
	}
	
	file.close();
	return true;
}
void Knihovna::lowestPrice(){
	int i;
	double lowest = knihy[0].getCena();
	int lowestIndex = 0;
	for(i = 1; i < knihy.size(); i++){
		if(knihy[i].getCena() < lowest){
			lowest = knihy[i].getCena();
			lowestIndex = i;
		}
	}
	std::cout<<"Nejnizsi cena knihy s ID " << knihy[lowestIndex].getID() << " je " << lowest << std::endl;
}
void Knihovna::highestPrice(){
	double maxPrice = 0;
	for(int i=0; i < knihy.size(); i++){
		if(knihy[i].getCena() > maxPrice){
			maxPrice = knihy[i].getCena();
		}
	}
	std::cout<<"Nejvyzsi cena knihy s ID " << knihy[maxPrice].getID() << " je " << maxPrice << std::endl;
}
void Knihovna::sortByPrice() {
	std::sort(knihy.begin(), knihy.end(), [](const Kniha& a, const Kniha& b) {
		return a.getCena() < b.getCena();
		});
}
void Knihovna::sortByPriceDescending(){
	std::sort(knihy.begin(), knihy.end(), [](const Kniha& a, const Kniha& b){
		return a.getCena() > b.getCena();
		});
}
void Knihovna::editBook(int id, std::string newNazev, double newCena) {
	for (int i = 0; i < knihy.size(); i++) {
		if (knihy[i].getID() == id) {
			knihy[i].setNazev(newNazev);
			knihy[i].setCena(newCena);
		}
	}
}
