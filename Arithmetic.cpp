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
			power = stoi(term.substr(term.find("^") + 1, term.size() - term.find("^") - 1));
		else
			power = 1;
	}
	else
		return ""; //constant
	if (power == 0) //t^0
		return "";
	
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
	vector<string> signs;
	bool a = expression.find("+") != string::npos;
	bool b = expression.find("-") != string::npos;

	while (a || b)
	{
		string sign = "";
		if (a && b)
		{
			if (expression.find("+") < expression.find("-"))
			{
				sign = "+";
				signs.push_back("+");
			}
			else
			{
				sign = "-";
				signs.push_back("-");
			}
		}
		else if (a)
		{
			sign = "+";
			signs.push_back("+");
		}
		else
		{
			sign = "-";
			signs.push_back("-");
		}

		int ind = expression.find(sign);
		terms.push_back(expression.substr(0, ind));
		expression = expression.substr(ind + 1, expression.size() - ind);

		a = expression.find("+") != string::npos;
		b = expression.find("-") != string::npos;
	}
	terms.push_back(expression); //deal with last term

	string s = "";
	for (unsigned int i = 0; i < terms.size(); ++i)
	{
		terms[i] = SingleDerivative(terms[i]);

		if (terms[i] == "")
		{
			s = s.substr(0, s.size() - 1);
			if (!(i == 0 && signs[i] == "+") && i != terms.size() - 1) // second condition b/c we're not taking the first term's sign
				s += signs[i];
		}
		else
		{
			if (i != terms.size() - 1)
			{
				s = s + terms[i] + signs[i];
			}
			else //last term
				s += terms[i];
		}
	}
	return s;
}

void Expression::VectorDerivative()
{
	compo[0] = Derivative(compo[0]);
	compo[1] = Derivative(compo[1]);
	compo[2] = Derivative(compo[2]);
}

void Expression::Print()
{
	cout << "<" << compo[0] << ", " << compo[1] << ", ";
	cout << compo[2] << ">" << endl;
}