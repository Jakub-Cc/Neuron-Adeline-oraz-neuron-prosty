#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Neuron.h"
#include "Unipolar.h"
#include "Adeline_bi.h"
#include "Adeline_uni.h"
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

int main()
{
	srand((unsigned int)time(NULL));
	
	int ile_ciagow = 4;
	double ciag_uczacy_bipolar[4][3] = { { 1,1,-1 } ,{ 1,-1,1 } ,{ 1,1,1 } ,{ 1,-1,-1 } };
	double ciag_wynikow_bipolar[4] = { -1,-1,1,-1 };
	double ciag_uczacy_unipolar[4][3] = { { 1,1,0 } ,{ 1,0,1 } ,{ 1,1,1 } ,{ 1,0,0 } };
	double ciag_wynikow_unipolar[4] = { 0,0,1,0 };
	
	//problem z konwersja danych
	double ** ciag_unipolar = new double*[4];	
	double ** ciag_bipolar = new double*[4];
	for (int i = 0;i < 4;i++)
	{
		ciag_bipolar[i] = new double[3];
		ciag_bipolar[i][0] = ciag_uczacy_bipolar[i][0];
		ciag_bipolar[i][1] = ciag_uczacy_bipolar[i][1];
		ciag_bipolar[i][2] = ciag_uczacy_bipolar[i][2];
		ciag_unipolar[i] = new double[3];
		ciag_unipolar[i][0] = ciag_uczacy_unipolar[i][0];
		ciag_unipolar[i][1] = ciag_uczacy_unipolar[i][1];
		ciag_unipolar[i][2] = ciag_uczacy_unipolar[i][2];
	}

	double a = 0.99;
	double b = 0.99;
	double test[3] = { 1.0, a, b };

	Adeline_bi Abi;
	Neuron bi;
	
	if (0) //perceptron bipolarny
	{ 
		std::cout << "perceptron bipolarny\n";
		bi= Neuron(3, 0.2, -0.01, 0.01);
		bi.epoki(ciag_bipolar, ciag_wynikow_bipolar, ile_ciagow, 0);
		bi.test(a, b);
		std::cout << "\n";
	}
	if (0) //adeline bipolarny
	{
		std::cout << "adeline bipolarny\n";
		Abi = Adeline_bi(3, 0.1 , -0.01, 0.01);
		//Abi.epoki(ciag_bipolar, ciag_wynikow_bipolar, ile_ciagow, 0.2);
		Abi.epoki_srednia_bl(ciag_bipolar, ciag_wynikow_bipolar, ile_ciagow, 0.4, 500);
		Abi.test(a, b);
		std::cout << "\n";
	}

	Unipolar uni;
	Adeline_uni Auni;
	if (0) //perceptron unipolarny
	{
		std::cout << "perceptron unipolarny\n";
		uni= Unipolar(3, 0.2, -0.01, 0.01);
		uni.epoki(ciag_unipolar, ciag_wynikow_unipolar, ile_ciagow, 0);
		std::cout << "\n";
		uni.test(a, b);
	}

	if (0) //adeline unipolarny
	{
		std::cout << "adeline unipolarny\n";
		Auni = Adeline_uni(3, 0.1, -0.1, 0.1);
		//Auni.epoki(ciag_unipolar, ciag_wynikow_unipolar, ile_ciagow, 0.10);
		Auni.epoki_srednia_bl(ciag_unipolar, ciag_wynikow_unipolar, ile_ciagow, 0.2, 100);
		std::cout << "\n";
		Auni.test(a, b);
	}

if (0) //badania
{
	std::streambuf* cout_sbuf = std::cout.rdbuf();
	std::cout.rdbuf(NULL);

	double wartosci_uczace[12] = { 0.5 , 0.4, 0.3, 0.25, 0.2, 0.15, 0.1, 0.05, 0.04, 0.03, 0.02, 0.01 };
	double wartosci_max[12] = { 1, 0.9, 0.8, 0.7, 0.6, 0.5, 0.4, 0.3, 0.2, 0.1, 0.05, 0.01 };

	double srednie_epok_bi[12][12];
	double srednie_epok_uni[12][12];
	double srednie_epok_ad_bi[12][12];
	double srednie_epok_ad_uni[12][12];

	int ilosc_powt = 1000;
	

	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			srednie_epok_bi[i][j]=0;
			srednie_epok_uni[i][j]=0;
			srednie_epok_ad_uni[i][j] = 0;
			srednie_epok_ad_bi[i][j] = 0;

			for (int k = 0;k < ilosc_powt;k++)
			{
				//uni = Unipolar(3, wartosci_uczace[i], -wartosci_max[j], wartosci_max[j]);
				//bi = Neuron(3, wartosci_uczace[i], -wartosci_max[j], wartosci_max[j]);
				Auni = Adeline_uni(3, wartosci_uczace[i], -wartosci_max[j], wartosci_max[j]);
				//Abi = Adeline_bi(3, wartosci_uczace[i], -wartosci_max[j], wartosci_max[j]);

				//srednie_epok_bi[i][j] += bi.epoki(ciag_bipolar,ciag_wynikow_bipolar,4,0);
				//srednie_epok_uni[i][j] += uni.epoki(ciag_unipolar, ciag_wynikow_unipolar, 4, 0);
				//srednie_epok_ad_bi[i][j] += Abi.epoki_srednia_bl(ciag_bipolar, ciag_wynikow_bipolar, 4, 0.4, 100);
				srednie_epok_ad_uni[i][j] += Auni.epoki_srednia_bl(ciag_unipolar, ciag_wynikow_unipolar, 4, 0.2, 100);
			}
			srednie_epok_bi[i][j] = srednie_epok_bi[i][j] / ilosc_powt;
			srednie_epok_uni[i][j] = srednie_epok_uni[i][j] / ilosc_powt;
			srednie_epok_ad_uni[i][j] = srednie_epok_ad_uni[i][j] / ilosc_powt;
			srednie_epok_ad_bi[i][j]= srednie_epok_ad_bi[i][j]/ ilosc_powt;
		}
	}




	//zapis do pliku
	std::string file_name = "Sieci_neuronowe_wyniki.csv";
	std::ofstream MyExcelFile;

	MyExcelFile.open(file_name);
	MyExcelFile << "Perceptron Bipolarny;"<< std::endl;
	MyExcelFile << "ucz/max;";

	for (int i = 0; i < 12; i++)
	{
		MyExcelFile << wartosci_max[i] << ';';
	}
	MyExcelFile << std::endl;


	for (int i = 0;i < 12; i++)
	{
		MyExcelFile << wartosci_uczace[i] << ';';
		for (int j = 0; j < 12;j++)
		{
			std::cout << srednie_epok_bi[i][j]<<" ";
			MyExcelFile << srednie_epok_bi[i][j] << ';';
		}
		std::cout << "\n";
		MyExcelFile << std::endl;
	}
	std::cout << "\n";
	MyExcelFile << std::endl;

	MyExcelFile << "Perceptron Unipolarny;" << std::endl;
	MyExcelFile << "ucz/max;";
	for (int i = 0; i < 12; i++)
	{
		MyExcelFile << wartosci_max[i] << ';';
	}

	MyExcelFile << std::endl;
	for (int i = 0;i < 12; i++)
	{
		MyExcelFile << wartosci_uczace[i] << ';';
		for (int j = 0; j < 12;j++)
		{
			std::cout << srednie_epok_uni[i][j] << " ";
			MyExcelFile << srednie_epok_uni[i][j] << ';';
		}
		MyExcelFile << std::endl;
		std::cout << "\n";
	}

	MyExcelFile << "Perceptron Adaline Bipolarny;" << std::endl;
	MyExcelFile << "ucz/max;";
	for (int i = 0; i < 12; i++)
	{
		MyExcelFile << wartosci_max[i] << ';';
	}
	MyExcelFile << std::endl;


	for (int i = 0;i < 12; i++)
	{
		MyExcelFile << wartosci_uczace[i] << ';';
		for (int j = 0; j < 12;j++)
		{
			std::cout << srednie_epok_ad_bi[i][j] << " ";
			MyExcelFile << srednie_epok_ad_bi[i][j] << ';';
		}
		std::cout << "\n";
		MyExcelFile << std::endl;
	}
	std::cout << "\n";
	MyExcelFile << std::endl;

	MyExcelFile << "Perceptron Adaline Unipolarny;" << std::endl;
	MyExcelFile << "ucz/max;";
	for (int i = 0; i < 12; i++)
	{
		MyExcelFile << wartosci_max[i] << ';';
	}
	MyExcelFile << std::endl;


	for (int i = 0;i < 12; i++)
	{
		MyExcelFile << wartosci_uczace[i] << ';';
		for (int j = 0; j < 12;j++)
		{
			std::cout << srednie_epok_ad_uni[i][j] << " ";
			MyExcelFile << srednie_epok_ad_uni[i][j] << ';';
		}
		std::cout << "\n";
		MyExcelFile << std::endl;
	}
	std::cout << "\n";
	MyExcelFile << std::endl;

	MyExcelFile.close();
	std::cout.rdbuf(cout_sbuf);
}


	system("pause");
	return 1;
}