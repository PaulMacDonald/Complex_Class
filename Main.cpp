#include<iostream>
#include"Complex.h"
using namespace std;

int main()
{
	// Read in all the values

	double realFirst, imaginaryFirst, realSecond, imaginarySecond;

	cout << "Enter the real value for the first complex number: ";
	cin >> realFirst;

	cout << "Enter the coefficient for i for the first complex number: ";
	cin >> imaginaryFirst;

	cout << "Enter the real value for the second complex number: ";
	cin >> realSecond;

	cout << "Enter the coefficient for i for the second complex number: ";
	cin >> imaginarySecond;

	// Create the two complex numbers
	Complex first(realFirst, imaginaryFirst);
	Complex second(realSecond, imaginarySecond);

	// Add the two and print it
	cout << "(" << first.toString() << ") + (" << second.toString() << ") = " << (first + second).toString() << endl;

	// Subtract the two and print it
	cout << "(" << first.toString() << ") - (" << second.toString() << ") = " << (first - second).toString() << endl;

	// Divide the two and print it
	cout << "(" << first.toString() << ") / (" << second.toString() << ") = " << (first / second).toString() << endl;

	// Multiply the two and print it
	cout << "(" << first.toString() << ") * (" << second.toString() << ") = " << (first * second).toString() << endl;

	// Find absolute value of both and print each one
	cout << "abs(" << first.toString() << ") = " << first.abs() << endl;
	cout << "abs(" << second.toString() << ") = " << second.abs() << endl;

	return 0;
}