#pragma once
#include <vector>
#include <string>
using namespace std;

class Expression {

	string compo[3];
	string SingleDerivative(string term);
public:
	Expression();
	Expression(string x, string y, string z);

	string Derivative(string expression);
};

