#pragma once
#include <iostream>
class Ispit
{
private:
	char* nazivIspita;
	int ocena, espb;
	void zauzmi(const char* nazivIspita, int ocena, int espb);
public:
	Ispit();
	Ispit(const char* nazivIspita, int ocena, int espb);
	Ispit(const Ispit& i);
	virtual ~Ispit();
	
	bool operator> (Ispit& i);
	int operator+(const int i);
	friend std::ostream& operator<<(std::ostream& out, Ispit& i);
	friend std::istream& operator>>(std::istream& in, Ispit& i);
};

