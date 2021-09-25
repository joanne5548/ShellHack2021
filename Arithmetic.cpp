#include "Arithmetic.h"

Arithmetic::Arithmetic(string s)
{
	x = s;
}

//first deal with a single term
string Arithmetic::Derivative()
{
	if (x == "0")
		return 0;
	int coef = stoi(x.substr(0, x.find("t")));
	int power = stoi(x.substr(x.find("^") + 1, x.size() - x.find("^")));

	coef *= power;
	power -= 1;
	
	string s;
	if (coef != 1)
		s = to_string(coef);
	if (power == 0)
		return s;
	else if (power == 1)
		return s + "t";
	return s + "t^" + to_string(power);
}