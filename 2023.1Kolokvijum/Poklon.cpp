#include "Poklon.h"

Poklon::Poklon()
{
	this->cena = this->brMasnica = 0;
}

Poklon::Poklon(double cena, double brMasnica)
{
	this->cena = cena;
	this->brMasnica = brMasnica;
}

Poklon::Poklon(const Poklon& p)
{
	this->cena = p.cena;
	this->brMasnica = p.brMasnica;
}

Poklon::~Poklon()
{

}

void Poklon::print(std::ostream& out)
{
	out << "CENA: " << this->cena << std::endl;
	out << "BROJ MASNICA" << this->brMasnica << std::endl;
}

std::ostream& operator<<(std::ostream& out, Poklon& p)
{
	p.print(out);
	return out;
}
