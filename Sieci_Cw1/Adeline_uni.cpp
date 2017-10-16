#include "Adeline_uni.h"



Adeline_uni::Adeline_uni()
{
}


Adeline_uni::~Adeline_uni()
{
	//delete[] wagi;
	//delete wagi;

}

double Adeline_uni::uczenie(double * wejscie, double oczekiwane, double zakres_bledu)
{
	double net = Net(wejscie);
	double blad = (oczekiwane - net)*(oczekiwane - net);

	std::cout << "Uczenie wzorca: wej: " << wejscie[0] << " " << wejscie[1] << " " << wejscie[2] << "\n";
	std::cout << "Uczenie wzorca: oczekiwana: " << oczekiwane << " net: " << net << "\n";

	std::cout << "Uczenie wzorca: korekcja wag: " ;
	for (int i = 0; i < ilosc_wejsc; i++)
	{
		std::cout << war_uczaca * 2 * ( oczekiwane - net )*wejscie[i] << " ";
		wagi[i] += war_uczaca*2*(oczekiwane - net)*wejscie[i];
	}
	std::cout << "\n";
	std::cout << "Uczenie wzorca: blad: " << blad <<", korekcja: "<< war_uczaca * 2 * ( oczekiwane - net )<< "\n";
	std::cout << "Uczenie wzorca: wagi po ucz: " << wagi[0] << " " << wagi[1] << " " << wagi[2] << "\n";

	std::cout << std::showpos << "Krzywa: y=" << -wagi[1] / wagi[2] << "x" << -wagi[0] / wagi[2] << std::noshowpos << '\n';
	
	return blad;
}
