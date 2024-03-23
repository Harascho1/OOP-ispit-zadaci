#pragma once
#include <iostream>
#include <fstream>

template <class T>
class Kolekcija
{
private:
	T* niz;
	int top, n;
public:
	Kolekcija();
	Kolekcija(int n);
	virtual ~Kolekcija();
	void DodajPodatak(T& pod);
	void Obrisi(int i);
	float OdrediProsek();
	T NajveciPodatak();
	
	void Sacuvaj(const char* imeFajla);
	void Ucitaj(const char* imeFajla);

	friend std::ostream& operator<<(std::ostream& out, Kolekcija<T>& k) {
		for (int i = 0; i < k.top; i++)
		{
			out << k.niz[i] << std::endl;
		}
		return out;
	}
};

template<class T>
inline Kolekcija<T>::Kolekcija()
{
	this->top = this->n = 0;
	this->niz = nullptr;
}

template<class T>
inline Kolekcija<T>::Kolekcija(int n)
{
	this->n = n;
	niz = new T[n];						//Ovo poziva pazan konstruktor!!!
	this->top = 0;
}

template<class T>
inline Kolekcija<T>::~Kolekcija()
{
	if (niz != nullptr) {
		delete[] niz;
		niz = nullptr;
	}
}

template<class T>
inline void Kolekcija<T>::DodajPodatak(T& pod)
{
	if (top < n) {
		niz[top++] = pod;
	}
	else {
		throw "NECE";
	}
}

template<class T>
inline void Kolekcija<T>::Obrisi(int i)
{
	if (i < 0 || i >= top)
		throw "Ne postoji podatak sa tim zadatim rednim brojem.";
	else {
		for (int j = i; j < top-1; j++)
		{
			niz[j] = niz[j + 1];
		}
		top--;
		niz[top] = T();
	}
}


template<class T>
inline float Kolekcija<T>::OdrediProsek()
{
	int suma = 0;
	for (int i = 0; i < top; i++)
	{
		suma = niz[i] + suma;		//niz[i].saberi(suma)  niz[] + suma
	}
	float resenje = (float)suma / top;
	return resenje;
}

template<class T>
inline T Kolekcija<T>::NajveciPodatak()
{
	int maxI = 0;
	for (int i = 1; i < this->top; i++)
	{
		if (niz[i] > niz[maxI]) {
			maxI = i;
		}
	}


	return niz[maxI];
}

template<class T>
inline void Kolekcija<T>::Sacuvaj(const char* imeFajla)
{
	std::ofstream fajl(imeFajla);
	if (fajl.good()) {
		fajl << *this;
		fajl.close();
	}
	else {
		throw "NE RADI SMESTANJE PODATAKA U FAJL";
	}
}

template<class T>
inline void Kolekcija<T>::Ucitaj(const char* imeFajla)
{
	std::ifstream fajl(imeFajla);
	if (fajl.good()) {
		T podatak = T();
		while (fajl >> podatak) {
			this->DodajPodatak(podatak);
		}
	}
	else
		throw "NE RADI UZIMANJE PODATAKA IZ FAJLA";
}

