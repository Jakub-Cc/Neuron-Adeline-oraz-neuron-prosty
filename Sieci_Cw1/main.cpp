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

	double ciag_uczacy_bipolar_walidacja[4][3] = { { 1,0.99,-0.99 } ,{ 1,-0.99,0.99 } ,{ 1,0.99,0.99 } ,{ 1,-0.99,-0.99 } };
	double ciag_wynikow_bipolar_walidacja[4] = { -1,-1,1,-1 };

	double ciag_uczacy_unipolar_walidacja[4][3] = { { 1,0.99,0.01 } ,{ 1,0.01,0.99 } ,{ 1,0.99,0.99 } ,{ 1,0.01,0.01 } };
	double ciag_wynikow_unipolar_walidacja[4] = { 0,0,1,0 };

	double ciag_uczacy_xor_bipolar[4][3] = { { 1,1,-1 } ,{ 1,-1,1 } ,{ 1,1,1 } ,{ 1,-1,-1 } };
	double ciag_wynikow_xor_bipolar[4] = { 1,1,-1,-1 };

	double ciag_uczacy_xor_unipolar[4][3] = { { 1,1,0 } ,{ 1,0,1 } ,{ 1,1,1 } ,{ 1,0,0 } };
	double ciag_wynikow_xor_unipolar[4] = { 1,1,0,0 };

	
	//konwersja danych
	double ** ciag_unipolar = new double*[4];	
	double ** ciag_bipolar = new double*[4];
	double ** ciag_unipolar_xor = new double*[4];
	double ** ciag_bipolar_xor = new double*[4];
	double ** ciag_bipolar_walidacja = new double*[4];
	double ** ciag_unipolar_walidacja = new double*[4];
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

		ciag_bipolar_xor[i] = new double[3];
		ciag_bipolar_xor[i][0] = ciag_uczacy_xor_bipolar[i][0];
		ciag_bipolar_xor[i][1] = ciag_uczacy_xor_bipolar[i][1];
		ciag_bipolar_xor[i][2] = ciag_uczacy_xor_bipolar[i][2];
		ciag_unipolar_xor[i] = new double[3];
		ciag_unipolar_xor[i][0] = ciag_uczacy_xor_unipolar[i][0];
		ciag_unipolar_xor[i][1] = ciag_uczacy_xor_unipolar[i][1];
		ciag_unipolar_xor[i][2] = ciag_uczacy_xor_unipolar[i][2];

		ciag_bipolar_walidacja[i] = new double[3];
		ciag_bipolar_walidacja[i][0] = ciag_uczacy_bipolar_walidacja[i][0];
		ciag_bipolar_walidacja[i][1] = ciag_uczacy_bipolar_walidacja[i][1];
		ciag_bipolar_walidacja[i][2] = ciag_uczacy_bipolar_walidacja[i][2];

		ciag_unipolar_walidacja[i] = new double[3];
		ciag_unipolar_walidacja[i][0] = ciag_uczacy_unipolar_walidacja[i][0];
		ciag_unipolar_walidacja[i][1] = ciag_uczacy_unipolar_walidacja[i][1];
		ciag_unipolar_walidacja[i][2] = ciag_uczacy_unipolar_walidacja[i][2];
	}


	double a = 0.99;
	double b = 0.99;
	double test[3] = { 1.0, a, b };

	Adeline_bi *Abi;
	Neuron *bi;
	Tools pom;
	//for (int i=0; i<100; i++ )
	
	//std::cout << pom.r_db ( -1, 1 )<<"\n";

	if ( 0 ) //perceptron bipolarny xor
	{
		std::cout << "perceptron bipolarny\n";
		bi =new Neuron ( 3, 0.2, -0.01, 0.01 );
		bi->epoki_srednia_bl_wali ( ciag_bipolar_xor, ciag_wynikow_xor_bipolar, ile_ciagow, 0.5, 100, ciag_bipolar_xor, ciag_wynikow_xor_bipolar);
		bi->test ( a, b );
		std::cout << "\n";
		delete bi;
	}

	if (0) //perceptron bipolarny
	{ 
		std::cout << "perceptron bipolarny\n";
		bi= new Neuron(3, 0.9, -1, 1);
		//bi.epoki(ciag_bipolar, ciag_wynikow_bipolar, ile_ciagow, 0);
		bi->epoki_srednia_bl_wali ( ciag_bipolar, ciag_wynikow_bipolar, ile_ciagow, 0, 100, ciag_bipolar_walidacja, ciag_wynikow_bipolar_walidacja );
		bi->test(a, b);
		std::cout << "\n";
		delete bi;
	}
	if (0) //adeline bipolarny
	{
		std::cout << "adeline bipolarny\n";
		Abi = new Adeline_bi(3, 0.01 , -0.01, 0.01);
		//Abi.epoki(ciag_bipolar, ciag_wynikow_bipolar, ile_ciagow, 0.2);
		//Abi.epoki_srednia_bl(ciag_bipolar, ciag_wynikow_bipolar, ile_ciagow, 0.4, 500);
		Abi->epoki_srednia_bl_wali ( ciag_bipolar, ciag_wynikow_bipolar, 4, 0, 200, ciag_bipolar_walidacja, ciag_wynikow_bipolar_walidacja );

		Abi->test(a, b);
		std::cout << "\n";
		delete Abi;
	}

	Unipolar * uni;
	Adeline_uni * Auni;
	if ( 0) //perceptron unipolarny xor
	{
		std::cout << "perceptron unipolarny\n";
		uni =new Unipolar ( 3, 0.2, -0.01, 0.01 );
		uni->epoki_srednia_bl ( ciag_unipolar_xor, ciag_wynikow_xor_unipolar, ile_ciagow, 0.20, 100 );
		std::cout << "\n";
		uni->test ( a, b );
		delete uni;
	}

	if (0) //perceptron unipolarny
	{
		std::cout << "perceptron unipolarny\n";
		uni= new Unipolar(3, 0.2, -0.01, 0.01);
		//uni.epoki(ciag_unipolar, ciag_wynikow_unipolar, ile_ciagow, 0);
		uni->epoki_srednia_bl_wali ( ciag_unipolar, ciag_wynikow_unipolar, 4, 0, 50, ciag_unipolar_walidacja, ciag_wynikow_unipolar_walidacja );

		std::cout << "\n";
		uni->test(a, b);
		delete uni;
	}

	if (0) //adeline unipolarny
	{
		std::cout << "adeline unipolarny\n";
		Auni = new Adeline_uni(3, 0.2, 1, 1);
		//Auni.epoki(ciag_unipolar, ciag_wynikow_unipolar, ile_ciagow, 0.10);
		//Auni.epoki_srednia_bl(ciag_unipolar, ciag_wynikow_unipolar, ile_ciagow, 0.2, 100);
		Auni->epoki_srednia_bl_wali ( ciag_unipolar, ciag_wynikow_unipolar, 4, 0, 100, ciag_unipolar, ciag_wynikow_unipolar);

		std::cout << "\n";
		Auni->test(a, b);
		delete Auni;
	}
	if ( 1 ) //badania z srednia i wariancja
	{
		std::streambuf* cout_sbuf = std::cout.rdbuf ();
		std::cout.rdbuf ( NULL );

		static const int ilosc_war_uczacych = 16;
		double wartosci_uczace[ilosc_war_uczacych] = {0.9, 0.8, 0.7, 0.6, 0.5 , 0.4, 0.3, 0.25, 0.2, 0.15, 0.1, 0.05, 0.04, 0.03, 0.02, 0.01 };
		static const int ilosc_war_max = 12;
		double wartosci_max[ilosc_war_max] = { 1, 0.9, 0.8, 0.7, 0.6, 0.5, 0.4, 0.3, 0.2, 0.1, 0.05, 0.01 };


		double srednie_epok_bi[ilosc_war_uczacych][ilosc_war_max];
		double srednie_epok_uni[ilosc_war_uczacych][ilosc_war_max];
		double srednie_epok_ad_bi[ilosc_war_uczacych][ilosc_war_max];
		double srednie_epok_ad_uni[ilosc_war_uczacych][ilosc_war_max];
		double wariancja_epok_bi[ilosc_war_uczacych][ilosc_war_max];
		double wariancja_epok_uni[ilosc_war_uczacych][ilosc_war_max];
		double wariancja_epok_ad_bi[ilosc_war_uczacych][ilosc_war_max];
		double wariancja_epok_ad_uni[ilosc_war_uczacych][ilosc_war_max];

		double nie_naucz_bi[ilosc_war_uczacych][ilosc_war_max];
		double nie_naucz_uni[ilosc_war_uczacych][ilosc_war_max];
		double nie_naucz_abi[ilosc_war_uczacych][ilosc_war_max]; 
		double nie_naucz_auni[ilosc_war_uczacych][ilosc_war_max];

		int ilosc_powt = 10000;

		double* ilosc_epok_w_powtorzeniu_bi = new double[ilosc_powt] ();
		double* ilosc_epok_w_powtorzeniu_uni = new double[ilosc_powt] ();
		double* ilosc_epok_w_powtorzeniu_abi = new double[ilosc_powt] ();
		double* ilosc_epok_w_powtorzeniu_auni = new double[ilosc_powt] ();

		int ile_max_epok = 10000;

		for ( int i = 0; i < ilosc_war_uczacych; i++ )
		{
			for ( int j = 0; j < ilosc_war_max; j++ )
			{
				std::cout.rdbuf ( cout_sbuf );
				std::cout << i << " " << j<<"\n";

				std::cout.rdbuf ( NULL );

				srednie_epok_bi[i][j] = 0;
				srednie_epok_uni[i][j] = 0;
				srednie_epok_ad_uni[i][j] = 0;
				srednie_epok_ad_bi[i][j] = 0;
				wariancja_epok_bi[i][j] = 0;
				wariancja_epok_uni[i][j] = 0;
				wariancja_epok_ad_uni[i][j] = 0;
				wariancja_epok_ad_bi[i][j] = 0;
				nie_naucz_bi[i][j] = 0;
				nie_naucz_uni[i][j] = 0;
				nie_naucz_abi[i][j] = 0;
				nie_naucz_auni[i][j] = 0;

				

				for ( int k = 0; k < ilosc_powt; k++ )
				{

					if ( 1 )
					{
						uni = new Unipolar(3, wartosci_uczace[i], -wartosci_max[j], wartosci_max[j]);
						//ilosc_epok_w_powtorzeniu_uni[k] = uni.epoki ( ciag_unipolar, ciag_wynikow_unipolar, 4, 0  );
						ilosc_epok_w_powtorzeniu_uni[k] = uni->epoki_srednia_bl_wali ( ciag_unipolar, ciag_wynikow_unipolar, 4, 0, ile_max_epok, ciag_unipolar, ciag_wynikow_unipolar );
						if ( ile_max_epok == ilosc_epok_w_powtorzeniu_uni[k] )
						{
							nie_naucz_uni[i][j]++;
						}
						srednie_epok_uni[i][j] += ilosc_epok_w_powtorzeniu_uni[k] / ilosc_powt;
						delete uni;
					}
					if ( 1 )
					{
						bi = new Neuron(3, wartosci_uczace[i], -wartosci_max[j], wartosci_max[j]);
						//ilosc_epok_w_powtorzeniu_bi[k] = bi.epoki ( ciag_bipolar, ciag_wynikow_bipolar, 4, 0 );
						ilosc_epok_w_powtorzeniu_bi[k]= bi->epoki_srednia_bl_wali ( ciag_bipolar, ciag_wynikow_bipolar, 4, 0, ile_max_epok, ciag_bipolar, ciag_wynikow_bipolar );
						if ( ile_max_epok == ilosc_epok_w_powtorzeniu_bi[k] )
						{
							nie_naucz_bi[i][j]++;
							std::cout.rdbuf ( cout_sbuf );
							//std::cout << bi.wagi[0] <<" "<< bi.wagi[1] << " " << bi.wagi[2] << '\n';
							std::cout.rdbuf ( NULL );
						}
						srednie_epok_bi[i][j] += ilosc_epok_w_powtorzeniu_bi[k] / ilosc_powt;
						delete bi;
					}
					if ( 1 )
					{
						Auni = new Adeline_uni ( 3, wartosci_uczace[i], -wartosci_max[j], wartosci_max[j] );
						//ilosc_epok_w_powtorzeniu_auni[k] = Auni.epoki_srednia_bl ( ciag_unipolar, ciag_wynikow_unipolar, 4, 0.2, 100 );
						ilosc_epok_w_powtorzeniu_auni[k] = Auni->epoki_srednia_bl_wali ( ciag_unipolar, ciag_wynikow_unipolar, 4, 0, ile_max_epok, ciag_unipolar, ciag_wynikow_unipolar );
						if ( ile_max_epok == ilosc_epok_w_powtorzeniu_auni[k] )
						{
							nie_naucz_auni[i][j]++;
						}
						srednie_epok_ad_uni[i][j] += ilosc_epok_w_powtorzeniu_auni[k] / ilosc_powt;
						delete Auni;
						
					}
					if ( 1 )
					{
						Abi =new Adeline_bi(3, wartosci_uczace[i], -wartosci_max[j], wartosci_max[j]);
						//ilosc_epok_w_powtorzeniu_abi[k] = Abi.epoki_srednia_bl ( ciag_bipolar, ciag_wynikow_bipolar, 4, 0.4, 100 );
						ilosc_epok_w_powtorzeniu_abi[k] = Abi->epoki_srednia_bl_wali ( ciag_bipolar, ciag_wynikow_bipolar, 4, 0, ile_max_epok, ciag_bipolar, ciag_wynikow_bipolar );
						if ( ile_max_epok == ilosc_epok_w_powtorzeniu_abi[k] )
						{
							nie_naucz_abi[i][j]++;
						}
						srednie_epok_ad_bi[i][j] += ilosc_epok_w_powtorzeniu_abi[k] / ilosc_powt;
						delete Abi;
					}
				}

				for ( int k = 0; k < ilosc_powt; k++ )
				{
					wariancja_epok_bi[i][j] += ( ilosc_epok_w_powtorzeniu_bi[k] - srednie_epok_bi[i][j] ) * ( ilosc_epok_w_powtorzeniu_bi[k] - srednie_epok_bi[i][j] ) / ilosc_powt;
					wariancja_epok_uni[i][j] += ( ilosc_epok_w_powtorzeniu_uni[k] - srednie_epok_uni[i][j] ) * ( ilosc_epok_w_powtorzeniu_uni[k] - srednie_epok_uni[i][j] ) / ilosc_powt;
					wariancja_epok_ad_bi[i][j] += ( ilosc_epok_w_powtorzeniu_abi[k] - srednie_epok_ad_bi[i][j] ) * ( ilosc_epok_w_powtorzeniu_abi[k] - srednie_epok_ad_bi[i][j] ) / ilosc_powt;
					wariancja_epok_ad_uni[i][j] += ( ilosc_epok_w_powtorzeniu_auni[k] - srednie_epok_ad_uni[i][j] ) * ( ilosc_epok_w_powtorzeniu_auni[k] - srednie_epok_ad_uni[i][j] ) / ilosc_powt;
				}
			}
		}
		std::cout.rdbuf ( cout_sbuf );

		if ( 1 )
		{
			//zapis do pliku
			std::string file_name = "Sieci_neuronowe_wyniki_+wariancja.csv";
			std::ofstream MyExcelFile;

			MyExcelFile.open ( file_name );
			MyExcelFile << "Perceptron Bipolarny;" << std::endl;
			MyExcelFile << "ucz/max;";

			for ( int i = 0; i < ilosc_war_max; i++ )
			{
				MyExcelFile << wartosci_max[i] << ';';
			}
			MyExcelFile << "Œrednia:" << ';';
			MyExcelFile << std::endl;


			for ( int i = 0; i < ilosc_war_uczacych; i++ )
			{
				MyExcelFile << wartosci_uczace[i] << ';';
				for ( int j = 0; j < ilosc_war_max; j++ )
				{
					std::cout << srednie_epok_bi[i][j] << " ";
					MyExcelFile << srednie_epok_bi[i][j] << ';';
				}
				std::cout << "\n";
				MyExcelFile << "=ŒREDNIA(" << 'B' << 3 + i << ":" << (char) ( 'B' + ilosc_war_max - 1 ) << 3 + i << ");";
				MyExcelFile << std::endl;
			}
			std::cout << "\n";
			MyExcelFile << "Srednia:;";
			for ( int i = 0; i < ilosc_war_max + 1; i++ )
			{
				MyExcelFile << "=ŒREDNIA(" << (char) ( 'B' + i ) << 3 << ":" << (char) ( 'B' + i ) << 2 + ilosc_war_uczacych << ");";
			}
			MyExcelFile << std::endl;

			MyExcelFile << "Perceptron Bipolarny wariancja;" << std::endl;
			MyExcelFile << "ucz/max;";

			for ( int i = 0; i < ilosc_war_max; i++ )
			{
				MyExcelFile << wartosci_max[i] << ';';
			}
			MyExcelFile << "Œrednia:" << ';';
			MyExcelFile << std::endl;

			for ( int i = 0; i < ilosc_war_uczacych; i++ )
			{
				MyExcelFile << wartosci_uczace[i] << ';';
				for ( int j = 0; j < ilosc_war_max; j++ )
				{
					std::cout << wariancja_epok_bi[i][j] << " ";
					MyExcelFile << wariancja_epok_bi[i][j] << ';';
				}
				std::cout << "\n";
				MyExcelFile << "=ŒREDNIA(" << 'B' << 22 + i << ":" << (char) ( 'B' + ilosc_war_max - 1 ) << 22 + i << ");";
				MyExcelFile << std::endl;
			}
			std::cout << "\n";
			MyExcelFile << "Srednia:;";
			for ( int i = 0; i < ilosc_war_max + 1; i++ )
			{
				MyExcelFile << "=ŒREDNIA(" << (char) ( 'B' + i ) << 22 << ":" << (char) ( 'B' + i ) << 21 + ilosc_war_uczacych << ");";
			}
			MyExcelFile << std::endl;

			MyExcelFile << "Perceptron Unipolarny;" << std::endl;
			MyExcelFile << "ucz/max;";
			for ( int i = 0; i < ilosc_war_max; i++ )
			{
				MyExcelFile << wartosci_max[i] << ';';
			}
			MyExcelFile << "Œrednia:" << ';';
			MyExcelFile << std::endl;
			for ( int i = 0; i < ilosc_war_uczacych; i++ )
			{
				MyExcelFile << wartosci_uczace[i] << ';';
				for ( int j = 0; j < ilosc_war_max; j++ )
				{
					std::cout << srednie_epok_uni[i][j] << " ";
					MyExcelFile << srednie_epok_uni[i][j] << ';';
				}
				MyExcelFile << "=ŒREDNIA(" << 'B' << 41 + i << ":" << (char) ( 'B' + ilosc_war_max - 1 ) << 41 + i << ");";
				MyExcelFile << std::endl;
				std::cout << "\n";
			}
			MyExcelFile << "Srednia:;";
			for ( int i = 0; i < ilosc_war_max + 1; i++ )
			{
				MyExcelFile << "=ŒREDNIA(" << (char) ( 'B' + i ) << 41 << ":" << (char) ( 'B' + i ) << 40 + ilosc_war_uczacych << ");";
			}
			MyExcelFile << std::endl;


			MyExcelFile << "Perceptron Unipolarny wariancja;" << std::endl;
			MyExcelFile << "ucz/max;";
			for ( int i = 0; i < ilosc_war_max; i++ )
			{
				MyExcelFile << wartosci_max[i] << ';';
			}
			MyExcelFile << "Œrednia:" << ';';
			MyExcelFile << std::endl;
			for ( int i = 0; i < ilosc_war_uczacych; i++ )
			{
				MyExcelFile << wartosci_uczace[i] << ';';
				for ( int j = 0; j < ilosc_war_max; j++ )
				{
					std::cout << wariancja_epok_uni[i][j] << " ";
					MyExcelFile << wariancja_epok_uni[i][j] << ';';
				}
				MyExcelFile << "=ŒREDNIA(" << 'B' << 60 + i << ":" << (char) ( 'B' + ilosc_war_max - 1 ) << 60 + i << ");";
				MyExcelFile << std::endl;
				std::cout << "\n";
			}
			MyExcelFile << "Srednia:;";
			for ( int i = 0; i < ilosc_war_max + 1; i++ )
			{
				MyExcelFile << "=ŒREDNIA(" << (char) ( 'B' + i ) << 60 << ":" << (char) ( 'B' + i ) << 59 + ilosc_war_uczacych << ");";
			}
			MyExcelFile << std::endl;

			MyExcelFile << "Perceptron Adaline Bipolarny;" << std::endl;
			MyExcelFile << "ucz/max;";
			for ( int i = 0; i < ilosc_war_max; i++ )
			{
				MyExcelFile << wartosci_max[i] << ';';
			}
			MyExcelFile << "Œrednia:" << ';';
			MyExcelFile << std::endl;

			for ( int i = 0; i < ilosc_war_uczacych; i++ )
			{
				MyExcelFile << wartosci_uczace[i] << ';';
				for ( int j = 0; j < ilosc_war_max; j++ )
				{
					std::cout << srednie_epok_ad_bi[i][j] << " ";
					MyExcelFile << srednie_epok_ad_bi[i][j] << ';';
				}
				MyExcelFile << "=ŒREDNIA(" << 'B' << 79 + i << ":" << (char) ( 'B' + ilosc_war_max - 1 ) << 79 + i << ");";
				std::cout << "\n";
				MyExcelFile << std::endl;
			}
			std::cout << "\n";
			MyExcelFile << "Srednia:;";
			for ( int i = 0; i < ilosc_war_max + 1; i++ )
			{
				MyExcelFile << "=ŒREDNIA(" << (char) ( 'B' + i ) << 79 << ":" << (char) ( 'B' + i ) << 78 + ilosc_war_uczacych << ");";
			}
			MyExcelFile << std::endl;

			MyExcelFile << "Perceptron Adaline Bipolarny wariancja;" << std::endl;
			MyExcelFile << "ucz/max;";
			for ( int i = 0; i < ilosc_war_max; i++ )
			{
				MyExcelFile << wartosci_max[i] << ';';
			}
			MyExcelFile << "Œrednia:" << ';';
			MyExcelFile << std::endl;


			for ( int i = 0; i < ilosc_war_uczacych; i++ )
			{
				MyExcelFile << wartosci_uczace[i] << ';';
				for ( int j = 0; j < ilosc_war_max; j++ )
				{
					std::cout << wariancja_epok_ad_bi[i][j] << " ";
					MyExcelFile << wariancja_epok_ad_bi[i][j] << ';';
				}
				std::cout << "\n";
				MyExcelFile << "=ŒREDNIA(" << 'B' << 98 + i << ":" << (char) ( 'B' + ilosc_war_max - 1 ) << 98 + i << ");";
				MyExcelFile << std::endl;
			}
			std::cout << "\n";
			MyExcelFile << "Srednia:;";
			for ( int i = 0; i < ilosc_war_max + 1; i++ )
			{
				MyExcelFile << "=ŒREDNIA(" << (char) ( 'B' + i ) << 98 << ":" << (char) ( 'B' + i ) << 97 + ilosc_war_uczacych << ");";
			}
			MyExcelFile << std::endl;

			MyExcelFile << "Perceptron Adaline Unipolarny;" << std::endl;
			MyExcelFile << "ucz/max;";
			for ( int i = 0; i < ilosc_war_max; i++ )
			{
				MyExcelFile << wartosci_max[i] << ';';
			}
			MyExcelFile << "Œrednia:" << ';';
			MyExcelFile << std::endl;


			for ( int i = 0; i < ilosc_war_uczacych; i++ )
			{
				MyExcelFile << wartosci_uczace[i] << ';';
				for ( int j = 0; j < ilosc_war_max; j++ )
				{
					std::cout << srednie_epok_ad_uni[i][j] << " ";
					MyExcelFile << srednie_epok_ad_uni[i][j] << ';';
				}
				std::cout << "\n";
				MyExcelFile << "=ŒREDNIA(" << 'B' << 117 + i << ":" << (char) ( 'B' + ilosc_war_max - 1 ) << 117 + i << ");";
				MyExcelFile << std::endl;
			}
			std::cout << "\n";
			MyExcelFile << "Srednia:;";
			for ( int i = 0; i < ilosc_war_max + 1; i++ )
			{
				MyExcelFile << "=ŒREDNIA(" << (char) ( 'B' + i ) << 117 << ":" << (char) ( 'B' + i ) << 116 + ilosc_war_uczacych << ");";
			}
			MyExcelFile << std::endl;

			MyExcelFile << "Perceptron Adaline Unipolarny wariancja;" << std::endl;
			MyExcelFile << "ucz/max;";
			for ( int i = 0; i < ilosc_war_max; i++ )
			{
				MyExcelFile << wartosci_max[i] << ';';
			}
			MyExcelFile << "Œrednia:" << ';';
			MyExcelFile << std::endl;


			for ( int i = 0; i < ilosc_war_uczacych; i++ )
			{
				MyExcelFile << wartosci_uczace[i] << ';';
				for ( int j = 0; j < ilosc_war_max; j++ )
				{
					std::cout << wariancja_epok_ad_uni[i][j] << " ";
					MyExcelFile << wariancja_epok_ad_uni[i][j] << ';';
				}
				std::cout << "\n";
				MyExcelFile << "=ŒREDNIA(" << 'B' << 136 + i << ":" << (char) ( 'B' + ilosc_war_max - 1 ) << 136 + i << ");";
				MyExcelFile << std::endl;
			}
			std::cout << "\n";
			MyExcelFile << "Srednia:;";
			for ( int i = 0; i < ilosc_war_max + 1; i++ )
			{
				MyExcelFile << "=ŒREDNIA(" << (char) ( 'B' + i ) << 136 << ":" << (char) ( 'B' + i ) << 135 + ilosc_war_uczacych << ");";
			}
			MyExcelFile << std::endl;

			MyExcelFile << "Perceptron Bipolarny - nie nauczono;" << std::endl;
			MyExcelFile << "ucz/max;";

			for ( int i = 0; i < ilosc_war_max; i++ )
			{
				MyExcelFile << wartosci_max[i] << ';';
			}
			MyExcelFile << "Œrednia:" << ';';
			MyExcelFile << std::endl;

			for ( int i = 0; i < ilosc_war_uczacych; i++ )
			{
				MyExcelFile << wartosci_uczace[i] << ';';
				for ( int j = 0; j < ilosc_war_max; j++ )
				{
					MyExcelFile << nie_naucz_bi[i][j] << ';';
				}
				MyExcelFile << "=ŒREDNIA(" << 'B' << 155 + i << ":" << (char) ( 'B' + ilosc_war_max - 1 ) << 155 + i << ");";
				MyExcelFile << std::endl;
			}
			MyExcelFile << "Srednia:;";
			for ( int i = 0; i < ilosc_war_max + 1; i++ )
			{
				MyExcelFile << "=ŒREDNIA(" << (char) ( 'B' + i ) << 155 << ":" << (char) ( 'B' + i ) << 154 + ilosc_war_uczacych << ");";
			}
			MyExcelFile << std::endl;

			MyExcelFile << "Perceptron Unipolarny - nie nauczono;" << std::endl;
			MyExcelFile << "ucz/max;";

			for ( int i = 0; i < ilosc_war_max; i++ )
			{
				MyExcelFile << wartosci_max[i] << ';';
			}
			MyExcelFile << "Œrednia:" << ';';
			MyExcelFile << std::endl;

			for ( int i = 0; i < ilosc_war_uczacych; i++ )
			{
				MyExcelFile << wartosci_uczace[i] << ';';
				for ( int j = 0; j < ilosc_war_max; j++ )
				{
					MyExcelFile << nie_naucz_uni[i][j] << ';';
				}
				MyExcelFile << "=ŒREDNIA(" << 'B' << 174 + i << ":" << (char) ( 'B' + ilosc_war_max - 1 ) << 174 + i << ");";
				MyExcelFile << std::endl;
			}
			MyExcelFile << "Srednia:;";
			for ( int i = 0; i < ilosc_war_max + 1; i++ )
			{
				MyExcelFile << "=ŒREDNIA(" << (char) ( 'B' + i ) << 174 << ":" << (char) ( 'B' + i ) << 173 + ilosc_war_uczacych << ");";
			}
			MyExcelFile << std::endl;

			MyExcelFile << "Perceptron Adaline Bipolarny - nie nauczono;" << std::endl;
			MyExcelFile << "ucz/max;";

			for ( int i = 0; i < ilosc_war_max; i++ )
			{
				MyExcelFile << wartosci_max[i] << ';';
			}
			MyExcelFile << "Œrednia:" << ';';
			MyExcelFile << std::endl;

			for ( int i = 0; i < ilosc_war_uczacych; i++ )
			{
				MyExcelFile << wartosci_uczace[i] << ';';
				for ( int j = 0; j < ilosc_war_max; j++ )
				{
					MyExcelFile << nie_naucz_abi[i][j] << ';';
				}
				MyExcelFile << "=ŒREDNIA(" << 'B' << 193 + i << ":" << (char) ( 'B' + ilosc_war_max - 1 ) << 193 + i << ");";
				MyExcelFile << std::endl;
			}
			MyExcelFile << "Srednia:;";
			for ( int i = 0; i < ilosc_war_max + 1; i++ )
			{
				MyExcelFile << "=ŒREDNIA(" << (char) ( 'B' + i ) << 193 << ":" << (char) ( 'B' + i ) << 192 + ilosc_war_uczacych << ");";
			}
			MyExcelFile << std::endl;


			MyExcelFile << "Perceptron Adaline unipolarny - nie nauczono;" << std::endl;
			MyExcelFile << "ucz/max;";

			for ( int i = 0; i < ilosc_war_max; i++ )
			{
				MyExcelFile << wartosci_max[i] << ';';
			}
			MyExcelFile << "Œrednia:" << ';';
			MyExcelFile << std::endl;

			for ( int i = 0; i < ilosc_war_uczacych; i++ )
			{
				MyExcelFile << wartosci_uczace[i] << ';';
				for ( int j = 0; j < ilosc_war_max; j++ )
				{
					MyExcelFile << nie_naucz_auni[i][j] << ';';
				}
				MyExcelFile << "=ŒREDNIA(" << 'B' << 212 + i << ":" << (char) ( 'B' + ilosc_war_max - 1 ) << 212 + i << ");";
				MyExcelFile << std::endl;
			}
			MyExcelFile << "Srednia:;";
			for ( int i = 0; i < ilosc_war_max + 1; i++ )
			{
				MyExcelFile << "=ŒREDNIA(" << (char) ( 'B' + i ) << 212 << ":" << (char) ( 'B' + i ) << 211 + ilosc_war_uczacych << ");";
			}
			MyExcelFile << std::endl;

			MyExcelFile.close ();

		}
	}

	system("pause");
	return 1;
}