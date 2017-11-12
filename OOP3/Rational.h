#pragma once
#include <iostream>
#include <string>

class Rational {
private:
	int ch;
	int zn;
	int sign;
public:
	Rational() {};
	Rational(int ch, int zn, int sign);
	Rational operator +(const Rational& b);
	Rational operator -(const Rational& b);
	Rational operator *(const Rational& b)const;
	Rational operator /(const Rational& b);
	void operator =(const Rational& b);

	bool operator ==(const Rational& b);

	friend std::istream& operator >> (std::istream& os, Rational& ans);
	friend std::ostream& operator<< (std::ostream& os, const Rational& num);
};