#ifndef TAROLO_H
#define TAROLO_H

#include <iostream>
using namespace std;

template <class T>
class Tarolo
{
protected:
    T* tomb;
    int N; // elemek szama
public:

    // letrehoz egy kezdetben 0 meretu T tombot
    Tarolo() :
        tomb(nullptr),
        N(0)
    {
    }

    // lemasol egy masik Tarolo-t
    Tarolo(const Tarolo<T>& masik) :
        tomb(new T[masik.N]),
        N(masik.N)
    {
        for (int i = 0; i < N; i++)
        {
            tomb[i] = masik[i];
        }
    }

    // felszabaditja a taroloban levo T dinamikus tombot
    virtual ~Tarolo()
    {
        delete[] tomb;
        tomb = nullptr;
        cout << "Tarolo (N=" << N << ") torolve." << endl;
    }

    // ujrafoglalja a tombot eggyel nagyobb meretben
    // majd beilleszti a vegere az uj elemet
    virtual void hozzaad(const T& ujelem)
    {
        T* ujtomb = new T[N + 1];
        for (int i = 0; i < N; i++)
        {
            ujtomb[i] = tomb[i];
        }
        ujtomb[N] = ujelem;
        delete[] tomb;
        tomb = ujtomb;
        N++;
    }

    // visszaadja a tomb elemeinek a szamat
    int getN() const
    {
        return N;
    }

    // visszaadja a tomb adott indexu elemet
    virtual const T& operator [] (int index) const
    {
        return tomb[index];
    }
};

#endif // TAROLO_H