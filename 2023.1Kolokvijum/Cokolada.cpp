#include "Cokolada.h"

Cokolada::Cokolada()
	:Poklon()
{
	this->procenatKakaa = 0;
}

Cokolada::Cokolada(double cena, int brMasnica, double procenatKakaa)
	:Poklon(cena,brMasnica)
{
	this->procenatKakaa = procenatKakaa;
}

Cokolada::Cokolada(const Cokolada& c)
	:Poklon(c)
{
	this->procenatKakaa = c.procenatKakaa;
}

Cokolada::~Cokolada()
{
}

void Cokolada::print(std::ostream& out)
{
	out << "COKOLADA" << std::endl;
	Poklon::print(out);
	out << "PROCENAT KAKAA: " << this->procenatKakaa << std::endl;
}
