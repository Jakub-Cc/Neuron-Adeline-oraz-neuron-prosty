#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <ctime>

class Tools
{
public:
	Tools();
	~Tools();
	int r_int(int min, int max);
	int r_int();
	double r_db(double min, double max);
	double r_db();
};


#endif // !TOOLS_H


