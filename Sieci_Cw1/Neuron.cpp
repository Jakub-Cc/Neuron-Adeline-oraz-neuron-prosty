#include "Neuron.h"
#include <cmath>


Neuron::Neuron()
{
}


Neuron::~Neuron()
{
	delete [] wagi;
	//delete wagi;
}

Neuron::Neuron(int ile_wejsc, double wartosc_uczaca,double min_wag, double max_wag)
{
	ilosc_wejsc = ile_wejsc;
	war_uczaca = wartosc_uczaca;
	wagi = new double[ilosc_wejsc];
	gereruj_wagi(min_wag, max_wag);
}

Neuron::Neuron(int ile_wejsc, double wartosc_uczaca)
{
	ilosc_wejsc = ile_wejsc;
	war_uczaca = wartosc_uczaca;
	wagi = new double[ilosc_wejsc];
}

void Neuron::gereruj_wagi(double min_wag, double max_wag)
{
	for (int i = 0; i < ilosc_wejsc; i++)
	{
		wagi[i] = pom.r_db(min_wag, max_wag);
	}
	std::cout << "Wagi poczatkowe: " << wagi[0] << " " << wagi[1] << " " << wagi[2] << "\n";
}

double Neuron::Net(double * wejcie)
{
	double net = 0;
	for (int i = 0; i < ilosc_wejsc; i++)
	{
		net += wagi[i] * ( wejcie[i] );
	}
	return net;
}

int Neuron::Wyjscie(double * wejcie)
{
	return Wyjscie(Net(wejcie));
}

int Neuron::Wyjscie(double net) 
{
	//std::cout << "Uruchomiona funkcja bazowa Neuron-Wyjscie \n";

	if (net >= 0)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

double Neuron::uczenie(double * wejscie, double oczekiwane, double zakres_bledu)  
{
	std::cout << "Uczenie wzorca: wej: " << wejscie[0] << " " << wejscie[1] << " " << wejscie[2] << "\n";
	std::cout << "Uczenie wzorca: oczekiwana: " << oczekiwane << "\n";
	std::cout << "Uczenie wzorca: otrzymana: " << Wyjscie ( wejscie ) << "\n";
	double blad = oczekiwane - Wyjscie(wejscie);
	if (blad > zakres_bledu || blad < -zakres_bledu)
	{
		for (int i = 0; i < ilosc_wejsc; i++)
		{
			wagi[i] += war_uczaca*blad*wejscie[i];
		}
	}
	//std::cout << "Uczenie wzorca: blad: " << blad << "\n";
	std::cout << "Uczenie wzorca: wagi po ucz: " << wagi[0] << " " << wagi[1] << " " << wagi[2] << "\n";
	std::cout << std::showpos << "Krzywa: y=" << -wagi[1] / wagi[2] << "x" << -wagi[0] / wagi[2] << std::noshowpos << '\n';
	return blad;
}

int Neuron::epoki(double ** wejscie, double * oczekiwane, int ile_ciagow, double zakres_bledu) //trzeba przeciazyc dla adaline
{
	int epoka = 0;
	bool stop = false;
	int *ciag_uzyty = new int[ile_ciagow] ();
	int ciag;

	while (!stop)
	{
		epoka++;
		std::cout << "\n: " << epoka << "\n";
		std::cout << "Wagi: " << wagi[0] << " " << wagi[1] << " " << wagi[2] << "\n";
		for ( int i = 0; i < ile_ciagow; i++ )
		{
			ciag_uzyty[i] = 0;
		}
		
		stop = true;
		for (int i = 0; i < ile_ciagow; i++) 
		{
			ciag = pom.r_int(0, ile_ciagow);

			while (i < ile_ciagow && ciag_uzyty[ciag]==1)
			{
				ciag = pom.r_int(0, ile_ciagow);
			}
			ciag_uzyty[ciag] = 1;

			double blad = uczenie(wejscie[ciag], oczekiwane[ciag], zakres_bledu);
			if (blad > zakres_bledu || blad < -zakres_bledu)
			{
				stop = false;
			}
		}
	}
	delete [] ciag_uzyty;
	
	std::cout << "\n: " << epoka << "\n";
	return epoka;
}

int Neuron::epoki_srednia_bl(double ** wejscie, double * oczekiwane, int ile_ciagow, double zakres_bledu, int max_epok)
{
	int epoka = 0;
	int *ciag_uzyty;
	int ciag;
	double suma_bledow = 10000;
	while ( ( suma_bledow > zakres_bledu || suma_bledow < -zakres_bledu ) && epoka< max_epok )
	{
		suma_bledow = 0;
		epoka++;
		std::cout << "\n: " << epoka << "\n";
		//std::cout << "Wagi: " << wagi[0] << " " << wagi[1] << " " << wagi[2] << "\n";

		ciag_uzyty = new int[ile_ciagow]();
		for (int i = 0; i < ile_ciagow; i++)
		{
			ciag = pom.r_int(0, ile_ciagow);

			while (i < ile_ciagow && ciag_uzyty[ciag] == 1)
			{
				ciag = pom.r_int(0, ile_ciagow);
			}
			ciag_uzyty[ciag] = 1;

			double blad = uczenie(wejscie[ciag], oczekiwane[ciag], zakres_bledu);
			suma_bledow += std::abs(blad);
		}
		suma_bledow = suma_bledow /(double) ile_ciagow ;
	}

	//std::cout << "\n: " << epoka << "\n";
	return epoka;
}

int Neuron::epoki_srednia_bl_wali ( double ** wejscie, double * oczekiwane, int ile_ciagow, double zakres_bledu, int max_epok, double ** walidacja, double * walidacja_oczekiwane, int ile_ciagow_walidacyjnych )
{
	int epoka = 0;
	int *ciag_uzyty = new int[ile_ciagow] ();
	int ciag;
	double suma_bledow = 10000;
	while ( suma_bledow > zakres_bledu && epoka< max_epok )
	{
		suma_bledow = 0;
		epoka++;
		//std::cout << "\n: " << epoka << "";
		//std::cout << "   Wagi: " << wagi[0] << " " << wagi[1] << " " << wagi[2] << "\n";
		for ( int i = 0; i < ile_ciagow; i++ )
		{
			ciag_uzyty[i] = 0;
		}
		for ( int i = 0; i < ile_ciagow; i++ )
		{
			ciag = pom.r_int ( 0, ile_ciagow );

			while ( i < ile_ciagow && ciag_uzyty[ciag] == 1 )
			{
				ciag = pom.r_int ( 0, ile_ciagow );
			}
			ciag_uzyty[ciag] = 1;

			double blad = uczenie ( wejscie[ciag], oczekiwane[ciag], zakres_bledu );
			suma_bledow += std::abs ( blad );
		}
		double pom_walidacja = 0;
		for ( int i = 0; i < ile_ciagow_walidacyjnych; i++ )
		{
			if ( walidacja_oczekiwane[i] != Wyjscie ( walidacja[i] ) )
			pom_walidacja ++;
		}
		suma_bledow = pom_walidacja / (double) ile_ciagow_walidacyjnych;
	}
	delete[] ciag_uzyty;
	//std::cout << "\n: " << epoka << "\n";
	return epoka;
}

void Neuron::test(double a, double b) //trzeba preciazyc dla kazdego (bipolarnego/ unipolarnego)
{
	double test[3] = { 1, a, b };
	std::cout << "Test: \n";
	std::cout << "Wagi: " << wagi[0] << " " << wagi[1] << " " << wagi[2]<<"\n";

	std::cout << a << " " << b << " wynik: " << Wyjscie(Net( test )  ) << "\n";

	test[1] = a; test[2] = -b;
	std::cout << a << " " << -b << " wynik: " << Wyjscie(Net(test))<<"\n";

	test[1] = -a; test[2] = -b;
	std::cout << -a << " " << -b << " wynik: " << Wyjscie(Net(test)) << "\n";

	test[1] = -a; test[2] = b;
	std::cout << -a << " " << b << " wynik: " << Wyjscie(Net(test)) << "\n";

	test[1] = -1; test[2] = 1;
	std::cout << -1 << " " << 1 << " wynik: " << Wyjscie ( Net ( test ) ) << "\n";
	test[1] = -1; test[2] = -1;
	std::cout << -1 << " " << -1 << " wynik: " << Wyjscie ( Net ( test ) ) << "\n";
	test[1] = 1; test[2] = 1;
	std::cout << 1 << " " << 1 << " wynik: " << Wyjscie ( Net ( test ) ) << "\n";
	test[1] = 1; test[2] = -1;
	std::cout << 1 << " " << -1 << " wynik: " << Wyjscie ( Net ( test ) ) << "\n";
}
