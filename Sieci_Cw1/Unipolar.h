#ifndef UNIPOLAR_H
#define UNIPOLAR_H

#include "Neuron.h"
class Unipolar : public Neuron
{
public:
	Unipolar();
	~Unipolar();
	Unipolar(int ile_wejsc, double wartosc_uczaca, double min_wag, double max_wag) :Neuron(ile_wejsc, wartosc_uczaca, min_wag, max_wag)
	{};
	Unipolar(int ile_wejsc, double wartosc_uczaca) :Neuron(ile_wejsc, wartosc_uczaca)
	{};

	int Wyjscie(double net);
	void test(double a, double b);
};

#endif
