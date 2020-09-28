#ifndef SIKIDOM_H
#define SIKIDOM_H

// absztrakt osztaly, tarolja egy sikidom meretet
// azonban a terulet() kiszamitasa a gyerekosztalyokban valosul meg
class Sikidom
{
protected:
	double meret;
public:
	Sikidom(double meret);
	virtual ~Sikidom();
	double getMeret() const;

	// csinal egy dinamikus masolatot az alakzatbol, gyerekosztaly szerint
	virtual Sikidom* clone() const = 0;

	// visszaadja a sikidom teruletet, a gyerekosztalyokban van kifejtve
	virtual double terulet() const = 0;
};

#endif // SIKIDOM_H
