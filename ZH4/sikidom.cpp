#include "sikidom.h"

#include <iostream>
using namespace std;

Sikidom::Sikidom(double meret) :
	meret(meret)
{
}

Sikidom::~Sikidom()
{
	// elobb a gyerekosztaly destruktora fut le, majd:
	cout << ", meret=" << meret << " felszabaditva." << endl;
}

double Sikidom::getMeret() const
{
	return meret;
}
