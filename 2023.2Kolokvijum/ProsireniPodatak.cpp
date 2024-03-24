#include "ProsireniPodatak.h"

const double ProsireniPodatak::GetTs()
{
	return t + 0.33 * e - 0.7 * v - 4.0;
}

ProsireniPodatak::ProsireniPodatak()
{
	t = e = v = 0;
}

ProsireniPodatak::ProsireniPodatak(double t, double e, double v)
{
	this->t = t;
	this->e = e;
	this->v = v;
}

ProsireniPodatak::ProsireniPodatak(const ProsireniPodatak& p)
{
	this->t = p.t;
	this->e = p.e;
	this->v = p.v;
}

ProsireniPodatak::~ProsireniPodatak()
{
}


bool ProsireniPodatak::operator>(ProsireniPodatak& p)
{
	if (this->GetTs() > p.GetTs())
		return true;
	return false;
}

int ProsireniPodatak::operator+(const int suma)
{
	return this->GetTs() + suma;
}

std::ostream& operator<<(std::ostream& out, ProsireniPodatak& p)
{
	out << p.t << " " << p.e << " " << p.v << std::endl;
	return out;
}

std::istream& operator>>(std::istream& in, ProsireniPodatak& p)
{
	return in >> p.t >> p.e >> p.v;
}
