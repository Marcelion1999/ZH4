#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "halmaz.h"
#include "sikidom.h"
#include "tarolo.h"

// A feladatokhoz #define direktivak kellenek, lasd: megoldott_feladatok.h
// A megoldott_feladatok.h fajlt is BE KELL ADNI a megirt osztalyokkal egyutt!

#include "megoldott_feladatok.h"

class Negyzet : public Sikidom
{
public:
	Negyzet(double meret) : Sikidom(meret) {}
	~Negyzet() { cout << "Negyzet"; }
	Negyzet* clone() const { return new Negyzet(*this); }

	double terulet() const { return meret * meret; }
};

class Kor : public Sikidom
{
public:
	Kor(double meret) : Sikidom(meret) {}
	~Kor() { cout << "Kor"; }
	Kor* clone() const { return new Kor(*this); }

	double terulet() const { return meret * meret * 3.14159265; }
};

void printPartStart(const string& partname);
void printPartEnd(const string& partname);

int main()
{
	cout << "main() eleje!" << endl << endl;

	{
		cout << "Pelda Tarolo<int>:" << endl;
		Tarolo<int> psq;
		for (int i = 1;i <= 10;i++)
		{
			psq.hozzaad(i * i);
		}
		for (int i = 0;i < psq.getN();i++)
		{
			cout << psq[i] << " ";
		}
		cout << endl;
		// 1 4 9 16 25 36 49 64 81 100
		// Tarolo (N=3) torolve.
	}

#ifdef PART1
	printPartStart("PART1");
	// Szarmaztatas Tarolo<Sikidom*>-bol (1 pont)
	{
		Tarolo<Sikidom*>* ures = new Halmaz;
		cout << "Ures tarolo, elemek szama: " << ures->getN() << endl;
		delete ures;
		// Tarolo (N=0) torolve.
	}
	printPartEnd("PART1");
#endif

#ifdef PART2
	printPartStart("PART2");
	// Destruktor helyes memoriakezelessel (2 pont)
	{
		Tarolo<Sikidom*>* pelda = new Halmaz;
		pelda->hozzaad(new Kor(10));
		pelda->hozzaad(new Negyzet(9));
		cout << "Elso terulet: " << (*pelda)[0]->terulet() << endl; // 314.159
		cout << "Masodik terulet: " << (*pelda)[1]->terulet() << endl; // 81
		cout << endl;
		delete pelda;
		// Kor, meret=10 felszabaditva.
		// Negyzet, meret=9 felszabaditva.
		// Tarolo (N=2) torolve.
	}
	printPartEnd("PART2");
#endif

#ifdef PART3
	printPartStart("PART3");
	// setElem (2 pont)
	{
		Halmaz t;
		t.hozzaad(new Kor(3));
		t.hozzaad(new Negyzet(4));
		t.hozzaad(new Kor(5));
		t.hozzaad(new Negyzet(6));

		cout << "Uj elem: Kor(7) a 2-es indexre." << endl;
		t.setElem(2, new Kor(7));
		cout << endl;
		// Kor, meret=5 felszabaditva.

		cout << "Uj elem: Negyzet(1.23) a 0-s indexre." << endl;
		t.setElem(0, new Negyzet(1.23));
		cout << endl;
		// Kor, meret=3 felszabaditva.

		cout << "Most nezzuk, hogy torleskor mi a tarolo tartalma:" << endl;
		// Negyzet, meret=1.23 felszabaditva.
		// Negyzet, meret=4 felszabaditva.
		// Kor, meret=7 felszabaditva.
		// Negyzet, meret=6 felszabaditva.
		// Tarolo (N=4) torolve.
	}
	printPartEnd("PART3");
#endif

#ifdef PART4
	printPartStart("PART4");
	// osszterulet (2 pont)
	{
		Halmaz t;
		cout << "Eddigi teruletek osszege: " << t.osszterulet() << endl; // 0
		t.hozzaad(new Kor(30));
		cout << "Eddigi teruletek osszege: " << t.osszterulet() << endl; // 2827.43
		t.hozzaad(new Negyzet(40));
		cout << "Eddigi teruletek osszege: " << t.osszterulet() << endl; // 4427.43
		t.hozzaad(new Kor(50));
		cout << "Eddigi teruletek osszege: " << t.osszterulet() << endl; // 12281.4
		t.hozzaad(new Negyzet(60));
		cout << "Eddigi teruletek osszege: " << t.osszterulet() << endl; // 15881.4
		cout << endl;

		// Kor, meret=30 felszabaditva.
		// Negyzet, meret=40 felszabaditva.
		// Kor, meret=50 felszabaditva.
		// Negyzet, meret=60 felszabaditva.
		// Tarolo (N=4) torolve.
	}
	printPartEnd("PART4");
#endif

#ifdef PART5
	printPartStart("PART5");
	// = operator (3 pont)
	{
		Halmaz* h1 = new Halmaz;
		h1->hozzaad(new Negyzet(1));
		h1->hozzaad(new Kor(2));

		Halmaz* h2 = new Halmaz;
		h2->hozzaad(new Negyzet(3));
		h2->hozzaad(new Kor(4));
		h2->hozzaad(new Negyzet(5));

		cout << "Ertekadas, H1=H2." << endl << endl;
		(*h1) = (*h2);
		// Negyzet, meret=1 felszabaditva.
		// Kor, meret=2 felszabaditva.

		cout << endl << "Most H2-t toroljuk." << endl << endl;
		delete h2;
		cout << endl;
		// Negyzet, meret=3 felszabaditva.
		// Kor, meret=4 felszabaditva.
		// Negyzet, meret=5 felszabaditva.
		// Tarolo (N=3) torolve.

		cout << "Nezzuk, H1 megorzodott-e. Ot is toroljuk." << endl << endl;
		delete h1;
		// Negyzet, meret=3 felszabaditva.
		// Kor, meret=4 felszabaditva.
		// Negyzet, meret=5 felszabaditva.
		// Tarolo (N=3) torolve.

	}
	printPartEnd("PART5");
#endif

	cout << "main() vege!" << endl;
	return 0;
}

void printPartStart(const string& partname)
{
	cout << endl << "----START OF " << partname << "----" << endl << endl;
}

void printPartEnd(const string& partname)
{
	cout << endl << "----END OF " << partname << "----" << endl << endl;
}
