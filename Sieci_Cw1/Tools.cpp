#include "Tools.h"



Tools::Tools()
{
}


Tools::~Tools()
{
}

/*int z zakresu <min, max)*/
int Tools::r_int(int min, int max)
{
	int f = rand() % max + min;
	return f;
}

/*int z zakresu <0, 32767>*/
int Tools::r_int()
{
	return rand();
}

/*double z zakresu <min,max>*/
double Tools::r_db(double min, double max)
{
	double f = (double)rand() / RAND_MAX;
	return min + f * (max - min);
}

/*double z zakresu <0,1> */
double Tools::r_db()
{
	return (double)rand() / RAND_MAX;
}
