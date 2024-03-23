#include "Igracka.h"

Igracka::Igracka()
	:Poklon()
{
	this->tipMaterija = nullptr;
}

Igracka::Igracka(double cena, int brMasnica, const char* tipMaterija)
	:Poklon(cena,brMasnica)
{
	this->tipMaterija = new char[strlen(tipMaterija) + 1];
	strcpy(this->tipMaterija, tipMaterija);
}

Igracka::Igracka(const Igracka& i)
	:Poklon(i)
{
	this->tipMaterija = new char[strlen(i.tipMaterija) + 1];
	strcpy(this->tipMaterija, i.tipMaterija);
}

Igracka::~Igracka()
{
	if (tipMaterija != nullptr)
	{
		delete[] tipMaterija;
		tipMaterija = nullptr;
	}
}

void Igracka::print(std::ostream& out)
{
	out << "IGRACAKA" << std::endl;
	Poklon::print(out);
	out << "TIP MATERIJA: " << this->tipMaterija << std::endl;
}
