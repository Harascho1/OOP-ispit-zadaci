#include "Ispit.h"

void Ispit::zauzmi(const char* nazivIspita, int ocena, int espb)
{
	this->nazivIspita = new char[strlen(nazivIspita) + 1];
	strcpy(this->nazivIspita, nazivIspita);
	this->ocena = ocena;
	this->espb = espb;
}

Ispit::Ispit()
{
	this->nazivIspita = nullptr;
	this->espb = this->ocena = 1;

}

Ispit::Ispit(const char* nazivIspita, int ocena, int espb)
{
	this->nazivIspita = new char[strlen(nazivIspita) + 1];
	strcpy(this->nazivIspita, nazivIspita);
	this->ocena = ocena;
	this->espb = espb;
}

Ispit::Ispit(const Ispit& i)
{
	this->nazivIspita = new char[strlen(i.nazivIspita) + 1];
	strcpy(this->nazivIspita, i.nazivIspita);
	this->ocena = i.ocena;
	this->espb = i.espb;
}



Ispit::~Ispit()
{
	if(nazivIspita != nullptr)
	{
		delete[] nazivIspita;
		nazivIspita = nullptr;
	}
}




bool Ispit::operator>(Ispit& i)
{
	if (espb > i.espb)	
		return true;
	return false;
}


int Ispit::operator+(const int i)
{

	return this->ocena+i;
}

std::ostream& operator<<(std::ostream& out, Ispit& i)
{
	out << i.nazivIspita <<" ";
	out << i.ocena	 << " ";
	out << i.espb << " ";
	return out;
}

std::istream& operator>>(std::istream& in, Ispit& i)
{
	char naziv[4];
	int oc;
	int e;
	in >> naziv >> oc >> e;
	i.zauzmi(naziv, oc, e);
	return in;
}
