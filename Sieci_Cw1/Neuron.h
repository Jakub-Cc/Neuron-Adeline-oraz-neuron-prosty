#ifndef NEURON_H
#define NEURON_H

#include <iostream>
#include <ctime>
#include "Tools.h"

class Neuron
{
private:
	Tools pom=Tools();
public:
	int ilosc_wejsc;
	double war_uczaca;
	double *wagi;

	Neuron();
	~Neuron();
	Neuron(int ile_wejsc, double wartosc_uczaca, double min_wag, double max_wag);
	Neuron(int ile_wejsc, double wartosc_uczaca);
	void gereruj_wagi(double min_wag, double max_wag);

	double Net(double *wejcie);
	int Wyjscie(double *wejcie);
	virtual int Wyjscie(double net); //trzeba preciazyc dla kazdego (bipolarnego/ unipolarnego)

	virtual double uczenie(double *wejscie, double oczekiwane, double zakres_bledu);			//trzeba przeciazyc dla adeline
	int epoki(double **wejscie, double * oczekiwane, int ile_ciagow, double zakres_bledu);
	int epoki_srednia_bl(double **wejscie, double * oczekiwane, int ile_ciagow, double zakres_bledu, int max_epok);
	int Neuron::epoki_srednia_bl_wali ( double ** wejscie, double * oczekiwane, int ile_ciagow, double zakres_bledu, int max_epok, double ** walidacja, double * walidacja_oczekiwane );
	virtual void test(double a, double b); //trzeba preciazyc dla kazdego (bipolarnego/ unipolarnego)

};

#endif