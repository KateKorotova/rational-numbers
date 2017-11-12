#include "Rational.h"

Rational::Rational(int ch, int zn, int sign) {
	(*this).zn = zn;
	(*this).ch = ch; 
	(*this).sign = sign;
}

void Rational::operator =(const Rational& b) {
	(*this).sign = b.sign;
	(*this).ch = b.ch;
	(*this).zn = b.zn;
}


Rational Rational::operator +(const Rational& b) {

}
Rational Rational::operator -(const Rational& b) {
	
}
Rational Rational::operator *(const Rational& b)const {
	 
}
Rational Rational::operator /(const Rational& b) {

}

bool Rational::operator ==(const Rational& b) {
	if ((*this).zn == b.zn && (*this).ch == b.ch && (*this).sign == b.sign)
		return true;
	if (b.sign == (*this).sign) {
		if (b.ch > (*this).ch) {
			int del = b.ch / (*this).ch;
			int del1 = b.zn / (*this).zn;
			if (del == del1)
				return true;
		}
		else {
			int del = (*this).ch / b.ch;
			int del1 = (*this).zn / b.zn;
			if (del == del1)
				return true;
		}
	}
	return false;
}

std::istream& operator >> (std::istream& os, Rational& ans) {
	std::string num;
	std::cin >> num;
	if (num[0] == '-') {
		ans.sign = -1;
		num.erase(0, 1);
	}
	else
		ans.sign = 1;
	ans.ch = stoi(num.substr(0, num.find("/")));
	ans.zn = stoi(num.substr(num.find("/")+1, num.length()-1));
	return os;
}

std::ostream& operator<< (std::ostream& os, const Rational& num) {
	if (num.sign == -1)
		os << "-";
	os << num.ch << "/" << num.zn;
	return os; 
}


int main() {
	Rational r;
	Rational r1;
	Rational r2;
	std::cin >> r1;
	std::cin >> r2;

	std::cout << r1 << std::endl;
	std::cout << r2 << std::endl;
	if (r1 == r2)
		std::cout << "yes" << std::endl;
	else
		std::cout << "no" << std::endl;


	std::system("pause");
}