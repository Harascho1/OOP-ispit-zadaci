#pragma once
#include <iostream>
#include <fstream>

template <class T>
class Kolekcija
{
private:
	int n, top;
	T* niz;
	void zauzmi(int n);
public:
	Kolekcija();
	Kolekcija(int n);
	~Kolekcija();
	Kolekcija(Kolekcija& k);
	void DodajPodatak(T& t);
	void Obrisi(int i);
	float OdrediProsek();
	T NajveciPodatak();
	void Sacuvaj(const char* imeFajla);
	void Ucitaj(const char* imeFajla);

	friend std::ostream& operator<<(std::ostream& out, Kolekcija& k) {
		for (int i = 0; i < k.top; i++)
		{
			out << k.niz[i] << std::endl;
		}
		return out;
	}
};

template<class T>
inline void Kolekcija<T>::zauzmi(int n)
{
	this->n = n;
	niz = new T[n];
	this->top = 0;
}

template<class T>
inline Kolekcija<T>::Kolekcija()
{
	this->n = this->top = 0;
	niz = T();
}

template<class T>
inline Kolekcija<T>::Kolekcija(int n)
{
	zauzmi(n);
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
inline Kolekcija<T>::Kolekcija(Kolekcija& k)
{
	zauzmi(k.n);
	for (int i = 0; i < n; i++)
	{
		this->DodajPodatak(k.niz[i]);
	}
}

template<class T>
inline void Kolekcija<T>::DodajPodatak(T& t)
{
	if (top < n) {
		niz[top++] = t;
	}
	else {
		throw "Ne radi";
	}
}

template<class T>
inline void Kolekcija<T>::Obrisi(int i)
{
	for (int j = i; j < top-1; j++)
	{
		niz[j] = niz[j + 1];
	}
	top--;
	niz[top] = T();
}

template<class T>
inline float Kolekcija<T>::OdrediProsek()
{
	float suma = 0;
	for (int i = 0; i < top; i++)
	{
		suma = niz[i] + suma;
	}
	return suma/top;
}

template<class T>
inline T Kolekcija<T>::NajveciPodatak()
{
	int iMax = 0;
	for (int i = 1; i < top; i++)
	{
		if (niz[i] > niz[iMax])
			iMax = i;
	}
	return niz[iMax];
}

template<class T>
inline void Kolekcija<T>::Sacuvaj(const char* imeFajla)
{
	std::ofstream fajl(imeFajla);
	if (fajl.good()) {
		fajl << *this;
		fajl.close();
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
		fajl.close();
	}
	else
		throw "NECE";
}
