#ifndef ADELINE_UNI_H
#define ADELINE_UNI_H

#include "Unipolar.h"
class Adeline_uni :
	public Unipolar
{
public:
	Adeline_uni();
	~Adeline_uni();
	Adeline_uni(int ile_wejsc, double wartosc_uczaca, double min_wag, double max_wag) :Unipolar(ile_wejsc, wartosc_uczaca, min_wag, max_wag)
	{};
	Adeline_uni(int ile_wejsc, double wartosc_uczaca) :Unipolar(ile_wejsc, wartosc_uczaca)
	{};
	double uczenie(double *wejscie, double oczekiwane, double zakres_bledu);
};


#endif // !ADELINE_UNI_H


