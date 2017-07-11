#ifndef ADELINE_BI_H

#define ADELINE_BI_H

#include "Neuron.h"
class Adeline_bi :
	public Neuron
{
public:
	Adeline_bi();
	~Adeline_bi();
	Adeline_bi(int ile_wejsc, double wartosc_uczaca, double min_wag, double max_wag) :Neuron(ile_wejsc, wartosc_uczaca, min_wag, max_wag)
	{};
	Adeline_bi(int ile_wejsc, double wartosc_uczaca) :Neuron(ile_wejsc, wartosc_uczaca)
	{};
	double uczenie(double *wejscie, double oczekiwane, double zakres_bledu);
};




#endif // ADELINE_BI_H

