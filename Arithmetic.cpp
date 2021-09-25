#include <iostream>
#include "Arithmetic.h"

Expression::Expression(string x, string y, string z)
{
	compo[0] = x;
	compo[1] = y;
	compo[2] = z;
}

//deal with a single term
string Expression::SingleDerivative(string term)
{
	int coef, power;
	if (term.find("t") != string::npos)
	{
		if (term.find("t") == 0)
			coef = 1;
		else
			coef = stoi(term.substr(0, term.find("t")));
		if (term.find("^") != string::npos)
			power = stoi(term.substr(term.find("^") + 1, term.size() - term.find("^")));
		else
			power = 1;
	}
	else
		return "0";
	
	coef *= power;
	power -= 1;
	
	string s;
	if (coef != 1)
		s = to_string(coef);
	if (power == 0)
		return to_string(coef);
	else if (power == 1)
		return s + "t";
	return s + "t^" + to_string(power);
}

//derivative of one expression
string Expression::Derivative(string expression)
{
	vector<string> terms;
	while (expression.find("+") != string::npos)
	{
		int ind = expression.find("+");
		terms.push_back(expression.substr(0, ind));
		expression = expression.substr(ind + 1, expression.size() - ind);
	}
	terms.push_back(expression);

	for (unsigned int i = 0; i < terms.size(); ++i)
		terms[i] = SingleDerivative(terms[i]);

	string s = terms[1] + "+" + terms[2] + "+" + terms[3];

	return s;
}

//derivative of one vector (call Derivative function 3 times)