#pragma once
#include "Poklon.h"
class Paketic
{
private:
	int n, top;
	Poklon** niz;
	void zauzmi(int n);
	void oslobodiMem();
public:

	Paketic();
	Paketic(int n);
	Paketic(const Paketic& paket);
	~Paketic();
	inline int BrojPoklona() { return n; }
	void Save(const char* imeFajla);
	Poklon* Max();

	void RemoveMinimum(Poklon* p);

	void Add(Poklon* p);
	const Paketic operator+(const Paketic& p);
	void print(std::ostream& out);
	friend std::ostream& operator<<(std::ostream& out, Paketic& paket);

};

