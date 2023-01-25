#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <cstdlib>
#include <numeric>
#include <math.h>
using namespace std;

class Zlomek {
private:
	int cit, jmen;
	void zkraceni(); // Privatni metoda pro zkraceni zlomku
public:
	Zlomek();
	friend ostream& operator << (ostream& output, Zlomek& content);
	friend istream& operator >> (istream& input, Zlomek& content);
	// Aritmeticke operace + - * / 
	friend Zlomek operator + (Zlomek a, Zlomek b);	
	friend Zlomek operator - (Zlomek a, Zlomek b);
	friend Zlomek operator * (Zlomek a, Zlomek b);
	friend Zlomek operator / (Zlomek a, Zlomek b);
	void mocnina();
	double zlomNaCele();
	
};


void porovnavani(Zlomek a, Zlomek b);

#endif
