#include<iostream>
#include <sstream>

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

public:
	Rational() {
		numerator = 0;
		denominator = 1;
	}
	Rational(int num, int denom) {
		numerator = num;
		denominator = denom;
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
		Rational result;
		result.numerator = this->numerator * f.denominator;
		result.denominator = this->denominator * f.numerator;
		result.Reduction();
		return result;
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
	{
		ostringstream output;
		output << Rational(-6, 8);
		if (output.str() != "-3/4") {
			cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
			return 1;
		}
	}

	{
		istringstream input("5/7");
		Rational r;
		input >> r;
		bool equal = r == Rational(5, 7);
		if (!equal) {
			cout << "5/7 is incorrectly read as " << r << endl;
			return 2;
		}
	}

	{
		istringstream input("5/7 10/8");
		Rational r1, r2;
		input >> r1 >> r2;
		bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
		if (!correct) {
			cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
			return 3;
		}

		input >> r1;
		input >> r2;
		correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
		if (!correct) {
			cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
			return 4;
		}
	}

	cout << "OK" << endl;
	return 0;
}