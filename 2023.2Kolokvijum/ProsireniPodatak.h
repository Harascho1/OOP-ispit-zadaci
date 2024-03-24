#pragma once
#include <iostream>
class ProsireniPodatak
{
private:
	double t, e, v;
	const double GetTs();
public:
	ProsireniPodatak();
	ProsireniPodatak(double t, double e, double v);
	ProsireniPodatak(const ProsireniPodatak& p);
	~ProsireniPodatak();
	

	bool operator>(ProsireniPodatak& p);
	int operator+(const int suma);
	friend std::ostream& operator<<(std::ostream& out, ProsireniPodatak& p);
	friend std::istream& operator>>(std::istream& in, ProsireniPodatak& p);
};

