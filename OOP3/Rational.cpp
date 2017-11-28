#include "Rational.h"
#include <math.h>

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
		ans.ch /= abs(g);
		ans.zn /= abs(g);
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

Rational Rational::operator -()const {
	Rational ans = *this;
	ans.sign = (-1)*(*this).sign;
	return ans;
}

Rational Rational::add_module(const Rational& b) {
	Rational res;
	res.zn = (zn / gcd((*this).zn, b.zn))*b.zn;
	res.ch = ((res.zn / (*this).zn)*(*this).ch) + ((res.zn / b.zn)*b.ch);
	res = res.reduction();
	return res;
}

Rational Rational::sub_module(const Rational& b) {
	Rational res;
	res.zn = (zn / gcd((*this).zn, b.zn))*b.zn;
	res.ch = ((res.zn / (*this).zn)*(*this).ch) - ((res.zn / b.zn)*b.ch);
	res = res.reduction();
	return res;
}

int Rational::cmp_module(const Rational& b) {
	Rational res;
	res.zn = (zn / gcd((*this).zn, b.zn))*b.zn;
	int cmp1 = (res.zn / (*this).zn)*(*this).ch;
	int cmp2 = (res.zn / b.zn)*b.ch;
	if (cmp1 > cmp2)
		return 1;
	if (cmp1 == cmp2)
		return 0;
	if (cmp1 < cmp2)
		return -1;
}

Rational Rational::operator +(const Rational& b) {
	Rational res;
	if (sign == b.sign) {
		res = (*this).add_module(b);
		res.sign = (*this).sign;
	}
	else{
		Rational a(b);
		if ((*this).cmp_module(b) == 1) {
			res = (*this).sub_module(b);
			res.sign = sign;
		}
		else
			if ((*this).cmp_module(b) == -1) {
				res = a.sub_module((*this));
				res.sign = b.sign;
			}
			else
				res.ch = 0;
	}
	return res;
}

Rational Rational::operator -(const Rational& b) {
	return *this + (-b); 
}

Rational Rational::operator *(const Rational& b) {
	Rational res;
	Rational f = (*this);
	Rational s = b;
	f = reduction_((*this).ch, b.zn);
	s = reduction_(b.ch, (*this).zn);
	res.ch = f.ch*s.ch;
	res.zn = f.zn*s.zn;
	res.sign = (*this).sign*b.sign;
	res = res.reduction();
	return res;
}

Rational Rational::operator /(const Rational& b){
	Rational rev = b;
	long long tmp = rev.ch;
	rev.ch = rev.zn;
	rev.zn = tmp;
	return rev*(*this);
}

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
	if (num.ch == 0)
		os << "0";
	else {
		if (num.sign == -1 && num.ch > 0)
			os << "-";
		os << num.ch << "/" << num.zn;
	}
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
	r = r1 / r2;
	std::cout << r << std::endl; 	
	std::cout << r1 + r2 << std::endl;
	std::cout << r1 - r2 << std::endl;

	std::system("pause");
}