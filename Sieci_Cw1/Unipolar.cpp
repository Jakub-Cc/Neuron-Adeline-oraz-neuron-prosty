#include "Unipolar.h"



Unipolar::Unipolar()
{
}


Unipolar::~Unipolar()
{
}

int Unipolar::Wyjscie(double net)
{
	//std::cout << "\nBipolar wyjscie \n";
	if (net >= 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void Unipolar::test(double a, double b)
{
	double test[3] = { 1, a, b };
	std::cout << "Test: \n";
	std::cout << "Wagi: " << wagi[0] << " " << wagi[1] << " " << wagi[2] << "\n";


	std::cout << a << " " << b << " wynik: " << Wyjscie(Net(test)) << "\n";

	test[1] = a; test[2] = 1-b;
	std::cout << a << " " << 1-b << " wynik: " << Wyjscie(Net(test)) << "\n";

	test[1] = 1-a; test[2] = 1-b;
	std::cout << 1-a << " " << 1-b << " wynik: " << Wyjscie(Net(test)) << "\n";

	test[1] = 1-a; test[2] = b;
	std::cout << 1-a << " " << b << " wynik: " << Wyjscie(Net(test)) << "\n";

	test[1] = 0; test[2] = 1;
	std::cout << 0 << " " << 1 << " wynik: " << Wyjscie ( Net ( test ) ) << "\n";
	test[1] = 0; test[2] = 0;
	std::cout << 0 << " " << 0 << " wynik: " << Wyjscie ( Net ( test ) ) << "\n";
	test[1] = 1; test[2] = 1;
	std::cout << 1<< " " << 1 << " wynik: " << Wyjscie ( Net ( test ) ) << "\n";
	test[1] = 1; test[2] = 0;
	std::cout << 1 << " " << 0 << " wynik: " << Wyjscie ( Net ( test ) ) << "\n";

}
