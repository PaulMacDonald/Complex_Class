#include<cmath>
#include<string>

#ifndef COMPLEX_H
#define COMPLEX_H
using namespace std;

class Complex
{
private:
	double real;
	double imaginary;

public:
	Complex();
	Complex(double theA);
	Complex(double theA, double theB);

	double getRealPart() const;
	double getImaginaryPart() const;

	double abs();
	string toString();

	Complex& operator++();
	Complex& operator--();
	Complex operator++(int c);
	Complex operator--(int c);
	double operator[](int index);
	Complex& operator+();
	Complex& operator-();

	Complex& operator+=(const Complex &n2);
	Complex& operator-=(const Complex &n2);
	Complex& operator*=(const Complex &n2);
	Complex& operator/=(const Complex &n2);

};

Complex operator+(const Complex &n1, const Complex &n2);
Complex operator-(const Complex &n1, const Complex &n2);
Complex operator*(const Complex &n1, const Complex &n2);
Complex operator/(const Complex &n1, const Complex &n2);

#endif
