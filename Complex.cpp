#include"Complex.h"
#include<iomanip>
#include<cmath>
#include<sstream>
#include<exception>

// Default constructor
Complex::Complex()
{
	real = 0.0;
	imaginary = 0.0;
}

// Constructor without imaginary part (b = 0)
Complex::Complex(double theA)
{
	real = theA;
	imaginary = 0;
}

// Constructor with two parameters (a and b)
Complex::Complex(double theA, double theB)
{
	real = theA;
	imaginary = theB;
}

// Returns real element of complex number
double Complex::getRealPart() const
{
	return real;
}

// Returns imaginary element of complex number
double Complex::getImaginaryPart() const
{
	return imaginary;
}

// Returns absolute value of complex number (special formula!)
double Complex::abs()
{
	return sqrt(pow(real, 2) + pow(imaginary, 2));
}

// Converts complex number to string
string Complex::toString()
{
	stringstream ss;
	ss << setprecision(4) << real;

	if (imaginary != 0.0)
		ss << " + " << setprecision(4) << imaginary << "i";

	return ss.str();
}

// OPERATOR OVERLOADS

Complex operator+(const Complex &n1, const Complex &n2)
{
	double realSum = n1.getRealPart() + n2.getRealPart();
	double imaginarySum = n1.getImaginaryPart() + n2.getImaginaryPart();

	Complex sum(realSum, imaginarySum);

	return sum;
}
Complex operator-(const Complex &n1, const Complex &n2)
{
	double realDifference = n1.getRealPart() - n2.getRealPart();
	double imaginaryDifference = n1.getImaginaryPart() - n2.getImaginaryPart();

	Complex difference(realDifference, imaginaryDifference);

	return difference;
}
Complex operator*(const Complex &n1, const Complex &n2)
{
	double realProduct = (n1.getRealPart() * n2.getRealPart()) - (n1.getImaginaryPart() * n2.getImaginaryPart());
	double imaginaryProduct = (n1.getImaginaryPart() * n2.getRealPart()) + (n1.getRealPart() * n2.getImaginaryPart());

	Complex product(realProduct, imaginaryProduct);

	return product;
}
Complex operator/(const Complex &n1, const Complex &n2)
{
	double denominator = (pow(n2.getRealPart(), 2) + pow(n2.getImaginaryPart(), 2));

	double realQuotient = ((n1.getRealPart() * n2.getRealPart()) + (n1.getImaginaryPart() * n2.getImaginaryPart())) / denominator;
	double imaginaryQuotient = ((n1.getImaginaryPart() * n2.getRealPart()) - (n1.getRealPart() * n2.getImaginaryPart())) / denominator;

	Complex quotient(realQuotient, imaginaryQuotient);

	return quotient;
}
Complex& Complex::operator+=(const Complex &n2)
{
	this->real = this->getRealPart() + n2.getRealPart();
	this->imaginary = this->getImaginaryPart() + n2.getImaginaryPart();

	return *this;
}
Complex& Complex::operator-=(const Complex &n2)
{
	this->real = this->getRealPart() - n2.getRealPart();
	this->imaginary = this->getImaginaryPart() - n2.getImaginaryPart();

	return *this;
}
Complex& Complex::operator*=(const Complex &n2)
{
	real = (this->getRealPart() * n2.getRealPart()) - (this->getImaginaryPart() * n2.getImaginaryPart());
	imaginary = (this->getImaginaryPart() * n2.getRealPart()) + (this->getRealPart() * n2.getImaginaryPart());

	return *this;
}
Complex& Complex::operator/=(const Complex &n2)
{
	double denominator = (pow(n2.getRealPart(), 2) + pow(n2.getImaginaryPart(), 2));

	real = ((this->getRealPart() * n2.getRealPart()) + (this->getImaginaryPart() * n2.getImaginaryPart())) / denominator;
	imaginary = ((this->getImaginaryPart() * n2.getRealPart()) - (this->getRealPart() * n2.getImaginaryPart())) / denominator;

	return *this;
}

// Prefix ++
Complex& Complex::operator++()
{
	real++;
	return *this;
}

// Prefix --
Complex& Complex::operator--()
{
	real--;
	return *this;
}

// Postfix ++
Complex Complex::operator++(int c)
{
	Complex temp(this->real, this->imaginary);

	this->real++;
	return temp;
}

// Postfix --
Complex Complex::operator--(int c)
{
	Complex temp(this->real, this->imaginary);

	this->real--;
	return temp;
}

double Complex::operator[](int index)
{
	if (index == 0)
		return this->real;

	if (index == 1)
		return this->imaginary;

	throw out_of_range("Index must be either 0 or 1.");
}

// Unary +
Complex& Complex::operator+()
{
	if (this->real < 0)
		this->real = -(this->real);

	if (this->imaginary < 0)
		this->imaginary = -(this->imaginary);

	return *this;
}

// Unary -
Complex& Complex::operator-()
{
	this->real = -(this->real);
	this->imaginary = -(this->imaginary);

	return *this;
}