#include "hlavicka.h"

Zlomek::Zlomek(){
	this->cit = 0;
	this->jmen = 1;
}

ostream& operator << (ostream& output, Zlomek& content){
	if(content.cit < 0 && content.jmen < 0)
	{
		output << content.cit * -1 << "/" << content.jmen * -1;
	}
	else if(content.jmen < 0 && content.cit >= 0)
	{
		output << content.cit * -1 << "/" << content.jmen * -1;
	}
	else
	{
		output << content.cit << "/" << content.jmen;
	}
	
	return output;
}

istream& operator >> (istream& input, Zlomek& content)
{
	cout << "Zadej citatel: ";
	input >> content.cit;
	do{
		cout << "Zadej jmenovatel: ";
		input >> content.jmen;
		if(content.jmen == 0){
			cout << "Nesmis zadat jmenovatele 0"  << endl;
		}
	}while(content.jmen == 0);
	
}

Zlomek operator + (Zlomek a, Zlomek b)
{
	
	Zlomek vys;
	vys.cit = (a.cit * b.jmen) + (a.jmen * b.cit);
	vys.jmen = a.jmen * b.jmen;
	vys.zkraceni();
	return vys;
}

Zlomek operator - (Zlomek a, Zlomek b)
{
	
	Zlomek vys;
	vys.cit = (a.cit * b.jmen) - (a.jmen * b.cit);
	vys.jmen = a.jmen * b.jmen;
	vys.zkraceni();
	return vys;
}

Zlomek operator * (Zlomek a, Zlomek b)
{
	
	Zlomek vys;
	vys.cit = a.cit * b.cit;
	vys.jmen = a.jmen * b.jmen;
	vys.zkraceni();
	return vys;
}

Zlomek operator / (Zlomek a, Zlomek b)
{
	
	Zlomek vys;
	vys.cit = a.cit * b.jmen;
	vys.jmen = a.jmen * b.cit;
	vys.zkraceni();
	return vys;
}

double Zlomek::zlomNaCele()
{
	double vys;
	
	vys = this->cit / this->jmen;
	
	return vys;
}

void porovnavani(Zlomek a, Zlomek b) 
{
	double ac = a.zlomNaCele();
	double bc = b.zlomNaCele();
	
	if(ac < bc){
		cout << a << "<" << b << endl;
	}else if(ac > bc){
		cout << a << ">" << b << endl;
	}else if(ac == bc){
		cout << a << "=" << b << endl;
	}
}

void Zlomek::zkraceni()
{
	
	double spolJmen = gcd(this->cit, this->jmen);
	cout << "Spolecny jmenovatel zadanych zlomku: " << spolJmen << endl;
	this->cit = this->cit / spolJmen;
	this->jmen = this->jmen / spolJmen;
}
void Zlomek::mocnina()
{
	int mocn;
	cout << "Zadej celociselnou mocninu: " <<endl;
	do{
		cin >> mocn;
		if(mocn<0){
			cout << "Nesmis zadat celociselnou mocninu mensi nez 0";
			
		}
		
	}while(mocn<0);
	
	this->cit = pow(this->cit, mocn);
	this->jmen= pow(this->jmen, mocn);
		
}
