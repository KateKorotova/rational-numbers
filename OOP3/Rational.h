#pragma once
#include <iostream>
#include <string>

class Rational {
private:
	long long ch;
	long long zn;
	long long sign;
	Rational reduction();
	Rational reduction_(const long long &a, const long long &b);
	long long gcd(long long a,long long b);
public:
	Rational();
	Rational(const Rational& other);
	Rational(long long ch, long long zn, int sign);
	Rational operator +(const Rational& b);
	Rational operator -(const Rational& b);
	Rational operator *(const Rational& b);
	Rational operator /(const Rational& b);
	bool operator ==(const Rational& b);

	friend std::istream& operator >> (std::istream& os, Rational& ans);
	friend std::ostream& operator<< (std::ostream& os, const Rational& num);
};