#ifndef HLAVICKA_H														//Define hlavicka_h aby jsme tuto tridu mohli pouzivat mimo tento source file
#define HLAVICKA_H

#include <iostream>
#include <cstdlib>
#include <numeric>
#include <math.h>
using namespace std;

class Time {															//Deklarace tridy Time
private:
	int hours;
	int minutes;
	int seconds;
public:
	Time();
	friend ostream& operator << (ostream& output, Time& content);		//Kamaradska funkce output, pro vypis casu z funkci
	friend istream& operator >> (istream& input, Time& content);		//Kamaradska funkce input, pro nacitani casu ve funkci
	// Aritmeticke operace + - 
	friend	Time operator + (Time a, Time b);	
	friend	Time operator - (Time a, Time b);
	friend void porovnavani(Time a, Time b);
	
};


#endif

