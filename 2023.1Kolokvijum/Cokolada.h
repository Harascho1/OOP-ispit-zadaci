#pragma once
#include "Poklon.h"
class Cokolada : public Poklon
{
private:
	double procenatKakaa;
public:
	Cokolada();
	Cokolada(double cena, int brMasnica, double procenatKakaa);
	Cokolada(const Cokolada& c);
	~Cokolada();

	int getMasnica() { return brMasnica * 2; }
	void print(std::ostream& out);
};

