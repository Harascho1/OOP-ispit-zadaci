#include "Paketic.h"
#include "Cokolada.h"
#include "Igracka.h"
#include <fstream>

void Paketic::zauzmi(int n)
{
	this->n = n;
	niz = new Poklon * [n];
	for (int i = 0; i < n; i++)
	{
		niz[i] = nullptr;
	}
}

void Paketic::oslobodiMem()
{
	if (niz != nullptr) {
		for (int i = 0; i < n; i++)
		{
			if (niz[i] != nullptr) {
				delete niz[i];
				niz[i] = nullptr;
			}
		}
		delete[] niz;
		niz = nullptr;
	}
}

Paketic::Paketic()
{
	this->n = this->top = 0;
	this->niz = nullptr;
}

Paketic::Paketic(int n)
{
	this->top = 0;
	zauzmi(n);
}

Paketic::Paketic(const Paketic& paket)
{
	this->top = 0;
	zauzmi(n);
	for (int i = 0; i < paket.top; i++)
	{
		if (typeid(*paket.niz[i]) == typeid(Cokolada))
			Add(new Cokolada(*dynamic_cast<Cokolada*>(paket.niz[i])));
		else
			Add(new Igracka(*dynamic_cast<Igracka*>(paket.niz[i])));
	}
}

Paketic::~Paketic()
{
	oslobodiMem();
}

void Paketic::Save(const char* imeFajla)
{
	std::ofstream fajl(imeFajla);
	if (fajl.good()) {
		fajl << *this;
		fajl.close();
	}
	else
	{
		std::cout << "NECE DA RADI KOMSINICE" << std::endl;
	}
	
}

Poklon* Paketic::Max()
{
	int maxI = 0;
	for (int i = 0; i < top; i++)
	{
		if (niz[i] != nullptr) {
			if (niz[i]->getMasnica() > niz[maxI]->getMasnica()) {
				maxI = i;
			}
		}
	}
	return niz[maxI];
}

void Paketic::RemoveMinimum(Poklon* p)
{
	if (top == 0)
		return;

	int min = 0;
	for (int i = 1; i < top; i++)
		if (niz[i]->getMasnica() < niz[min]->getMasnica())
			min = i;

	// kontam da u ovaj ulazni parametar treba stavim taj koji se brise
	p = niz[min];

	for (int i = min; i < top - 1; i++)
		niz[i] = niz[i + 1];

	niz[top - 1] = p; // ovo je da bi se izbrisao pokazivac na poklon u destruktor zato ga stavljam na zadnje mesto
	top--;
}

void Paketic::Add(Poklon* p)
{
	if (top < n) {
		niz[top++] = p;
	}
}

const Paketic Paketic::operator+(const Paketic& p)
{
	Paketic temp(this->n + p.n);
	for (int i = 0; i < top; i++) {
		if (typeid(*niz[i]) == typeid(Cokolada))
			temp.Add(new Cokolada(*dynamic_cast<Cokolada*>(niz[i])));
		// novi.Add(new Cokolada(*((Cokolada*)niz[i])));
		else
			temp.Add(new Igracka(*dynamic_cast<Igracka*>(niz[i])));
		// novi.Add(new Igracka(*((Igracka*)niz[i])));
	}
	for (int i = 0; i < p.top; i++) {
		if (typeid(*niz[i]) == typeid(Cokolada))
			temp.Add(new Cokolada(*dynamic_cast<Cokolada*>(niz[i])));
		// novi.Add(new Cokolada(*((Cokolada*)niz[i])));
		else
			temp.Add(new Igracka(*dynamic_cast<Igracka*>(niz[i])));
		// novi.Add(new Igracka(*((Igracka*)niz[i])));
	}
	return temp;
}

void Paketic::print(std::ostream& out)
{
	out << std::endl;
	out << "PAKETICI" << std::endl;
	out << "BROJ N: "<< this->n << std::endl;
	out << "BROJ top: "<<this->top << std::endl;
	out << std::endl;
	for (int i = 0; i < top; i++)
	{
		out << *niz[i] << std::endl;
	}
	out << "KRAJ POKLONA" << std::endl;
}

std::ostream& operator<<(std::ostream& out, Paketic& paket)
{
	paket.print(out);
	return out;
}
