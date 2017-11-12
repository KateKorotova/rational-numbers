#include "Rational.h"

Rational::Rational(){
	(*this).sign = 1;
}
Rational::Rational(const Rational& other) {
	(*this).sign = other.sign;
	(*this).ch = other.ch;
	(*this).zn = other.zn;
}


Rational::Rational(long long ch, long long zn, int sign) {
	(*this).zn = zn;
	(*this).ch = ch; 
	(*this).sign = sign;
}

long long Rational::gcd(long long a, long long b) {
	while (a != 0 && b != 0) {
		if (a > b)
			a = a%b;
		else
			b = b%a;
	}
	return a + b;
}

Rational Rational::reduction() {
	Rational ans = (*this);
	long long g = gcd(ans.ch, ans.zn);
	if (g != 1) {
		ans.ch /= g;
		ans.zn /= g;
	}
	return ans; 
}
Rational Rational::reduction_(const long long &a, const long long &b) {
	Rational ans; 
	ans.ch = a;
	ans.zn = b;
	long long g = gcd(a, b);
	if (g != 1) {
		ans.ch = a / g;
		ans.zn = b / g;
	}
	return ans; 
}

//Rational Rational::operator +(const Rational& b) {
//	Rational res;
//	if ((*this).sign == b.sign) {
//		res.zn = gcd((*this).zn, b.zn);
//		res.ch = (*this).ch*res.zn + b.ch*res.zn;
//		res.sign = (*this).sign;
//		res = res.reduction();
//		return res;
//	}
//
//}
//Rational Rational::operator -(const Rational& b) {
//	Rational res;
//
//}

Rational Rational::operator *(const Rational& b) {
	Rational res;
	Rational f;
	f = (*this);
	Rational s;
	s = b;
	f = reduction_((*this).ch, b.zn);
	s = reduction_(b.ch, (*this).zn);
	res.ch = f.ch*s.ch;
	res.zn = f.zn*s.zn;
	res.sign = (*this).sign*b.sign;
	res = res.reduction();
	return res;
}
//Rational Rational::operator /(const Rational& b) {
//
//}

bool Rational::operator ==(const Rational& b) {
	return ((*this).zn == b.zn && (*this).ch == b.ch && (*this).sign == b.sign);
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
	ans = ans.reduction();
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
	std::cout << r1*r2 << std::endl;

	std::system("pause");
}