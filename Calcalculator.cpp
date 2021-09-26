#include <iostream>

#include "Arithmetic.h"

using namespace std;

int main() {

	string x, y, z;
	cout << "Welcome to Vector Derivative Calculator!" << endl << endl;;
	cout << "Enter a 3d vector's components in terms of t." << endl;
	cout << "Separate the terms with + or - signs, without space in between." << endl;
	cout << "Example: t^2-2t+5" << endl << endl;;
	cout << "Enter the x component: ";
	cin >> x;
	cout << "Enter the y component: ";
	cin >> y;
	cout << "Enter the z component: ";
	cin >> z;

	Expression a(x, y, z);
	a.VectorDerivative();

	cout << endl;
	cout << "The result is: ";
	a.Print();

	return 0;
}