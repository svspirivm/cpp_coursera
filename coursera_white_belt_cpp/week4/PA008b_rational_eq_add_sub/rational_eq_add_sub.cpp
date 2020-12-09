#include<iostream>

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
};


int main() {
	{
		Rational r1(4, 6);
		Rational r2(2, 3);
		bool equal = r1 == r2;
		if (!equal) {
			cout << "4/6 != 2/3" << endl;
			return 1;
		}
	}

	{
		Rational a(2, 3);
		Rational b(4, 3);
		Rational c = a + b;
		bool equal = c == Rational(2, 1);
		if (!equal) {
			cout << "2/3 + 4/3 != 2" << endl;
			return 2;
		}
	}

	{
		Rational a(5, 7);
		Rational b(2, 9);
		Rational c = a - b;
		bool equal = c == Rational(31, 63);
		if (!equal) {
			cout << "5/7 - 2/9 != 31/63" << endl;
			return 3;
		}
	}

	cout << "OK" << endl;
	return 0;
}