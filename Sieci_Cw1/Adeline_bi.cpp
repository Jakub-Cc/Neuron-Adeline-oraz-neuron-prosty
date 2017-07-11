#include "Adeline_bi.h"



Adeline_bi::Adeline_bi()
{
}


Adeline_bi::~Adeline_bi()
{
}

double Adeline_bi::uczenie(double * wejscie, double oczekiwane, double zakres_bledu)
{
	double net = Net(wejscie);
	double blad = (oczekiwane - net)*(oczekiwane - net);

	std::cout << "Uczenie wzorca: wej: " << wejscie[0] << " " << wejscie[1] << " " << wejscie[2] << "\n";
	std::cout << "Uczenie wzorca: oczekiwana: " << oczekiwane << " net: " << net << "\n";

	for (int i = 0; i < ilosc_wejsc; i++)
	{
		wagi[i] += war_uczaca*(oczekiwane - net)*wejscie[i];
	}

	std::cout << "Uczenie wzorca: blad: " << blad <<", korekcja: "<< (oczekiwane - net) << "\n";
	std::cout << "Uczenie wzorca: wagi po ucz: " << wagi[0] << " " << wagi[1] << " " << wagi[2] << "\n";

	std::cout << std::showpos << "Krzywa: y=" << -wagi[1] / wagi[2] << "x" << -wagi[0] / wagi[2] << std::noshowpos << '\n';

	return blad;
}
