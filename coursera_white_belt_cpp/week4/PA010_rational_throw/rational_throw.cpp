#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <exception>
#include<stdexcept>
using namespace std;

class Rational {
private:
	int numerator;
	int denominator;
	void Reduction() {
		if (numerator == 0) denominator = 1;
		else if ((numerator > 0 && denominator < 0) || (numerator < 0 && denominator < 0)) {
			numerator *= (-1);
			denominator *= (-1);
		}
		int i = denominator;
		while (i > 1) {
			if (denominator % i == 0 && numerator % i == 0) {
				numerator /= i;
				denominator /= i;
			}
			--i;
		}

	}
	void CheckDenominator() {
		if (denominator == 0) {
			throw invalid_argument("Invalid argument");
		}
	}

public:
	Rational() {
		numerator = 0;
		denominator = 1;
	}
	Rational(int num, int denom) {
		numerator = num;
		denominator = denom;
		CheckDenominator();
		Reduction();
	}
	int Numerator() const {
		return numerator;
	}
	int Denominator() const {
		return denominator;
	}
	bool operator== (const Rational& f) const {
		return (this->numerator == f.numerator && this->denominator == f.denominator);
	}
	Rational operator+ (const Rational& f) const {
		Rational result;
		result.numerator = this->numerator * f.denominator + f.numerator * this->denominator;
		result.denominator = this->denominator * f.denominator;
		result.Reduction();
		return result;
	}
	Rational operator- (const Rational& f) const {
		Rational result;
		result.numerator = this->numerator * f.denominator - f.numerator * this->denominator;
		result.denominator = this->denominator * f.denominator;
		result.Reduction();
		return result;
	}
	Rational operator* (const Rational& f) const {
		Rational result;
		result.numerator = this->numerator * f.numerator;
		result.denominator = this->denominator * f.denominator;
		result.Reduction();
		return result;
	}
	Rational operator/ (const Rational& f) const {
		if (f.numerator == 0) {
			throw domain_error("Division by zero");
		}
		Rational result;
		result.numerator = this->numerator * f.denominator;
		result.denominator = this->denominator * f.numerator;
		result.Reduction();
		return result;
	}
	bool operator< (const Rational& f) const {
		int one = this->numerator * f.denominator;
		int another = this->denominator * f.numerator;
		if (one < another) return true;
		else return false;
	}
	friend istream& operator>> (istream& stream, Rational& f);
	friend ostream& operator<< (ostream& stream, const Rational& f);
};

istream& operator>>(istream& stream, Rational& f) {
	stream >> f.numerator;
	stream.ignore(1);
	stream >> f.denominator;
	f.Reduction();
	return stream;
}

ostream& operator<< (ostream& stream, const Rational& f) {
	stream << f.numerator << "/" << f.denominator;
	return stream;
}


int main() {
	try {
		Rational r(1, 0);
		cout << "Doesn't throw in case of zero denominator" << endl;
		return 1;
	}
	catch (invalid_argument&) {
	}

	try {
		auto x = Rational(1, 2) / Rational(0, 1);
		cout << "Doesn't throw in case of division by zero" << endl;
		return 2;
	}
	catch (domain_error&) {
	}

	cout << "OK" << endl;
	return 0;
}