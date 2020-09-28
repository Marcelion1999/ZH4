#ifndef HALMAZ_H
#define HALMAZ_H

#include "sikidom.h"
#include "tarolo.h"


class Halmaz : public Tarolo<Sikidom*>
{
public:
	Halmaz() {}
	~Halmaz()
	{
		for (int i = 0; i < getN(); i++)
		{
			//tomb[i] = nullptr;
			delete tomb[i];
		}
	}

	Sikidom* setElem(int index, Sikidom* adat) 
	{
		return tomb[index] = adat;
	}
	virtual double osszterulet() const
	{
		double t = 0;
		for (int i = 0; i < getN(); i++)
		{
			t = t + tomb[i]->terulet();
		}
		return t;
	}
};


#endif // SIKIDOM_H