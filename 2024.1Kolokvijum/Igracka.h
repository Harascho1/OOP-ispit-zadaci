#pragma once
#include "Poklon.h"
class Igracka : public Poklon
{
private:
	char* tipMaterija;
public:
	Igracka();
	Igracka(double cena, int brMasnica, const char* tipMaterija);
	Igracka(const Igracka& i);
	~Igracka();
	int getMasnica() { return brMasnica + 2; }
	void print(std::ostream& out);
};

