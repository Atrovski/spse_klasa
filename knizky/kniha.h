#ifndef KNIHA_H
#define KNIHA_H
#include <iostream>
#include <string>
#include <vector>

class Kniha
{
private:
	int ID;
	std::string nazev;
	float cena;
	
public:
	Kniha();
	Kniha(int id, std::string nazevKniha, float cenaKniha);
	int getID() const;
	std::string getNazev() const;
	float getCena() const;
	friend std::ostream& operator<< (std::ostream &out, const Kniha &kniha);
	friend std::istream& operator>> (std::istream &in, Kniha &kniha);
};
class Knihovna
{
private:
	std::vector<Kniha> knihy;
	
public:
	Knihovna();
	void pridatKniha(Kniha kniha);
	void vypisKnih();
	Kniha najitKniha(std::string nazev);
};

#endif
