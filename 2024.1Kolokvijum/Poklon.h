#pragma once
#include <iostream>
class Poklon
{
protected:
	double cena;
	int brMasnica;
public:
	Poklon();
	Poklon(double cena, double brMasnica);
	Poklon(const Poklon& p);
	virtual ~Poklon();

	virtual int getMasnica() = 0;

	virtual void print(std::ostream& out);
	friend std::ostream& operator<<(std::ostream& out, Poklon& p);
};

