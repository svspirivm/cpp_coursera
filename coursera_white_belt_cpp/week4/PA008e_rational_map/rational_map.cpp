#include <iostream>
#include <map>
#include <set>
#include <vector>
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
	{
		const set<Rational> rs = { {1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2} };
		if (rs.size() != 3) {
			cout << "Wrong amount of items in the set" << endl;
			return 1;
		}

		vector<Rational> v;
		for (auto x : rs) {
			v.push_back(x);
		}
		if (v != vector<Rational>{ {1, 25}, { 1, 2 }, { 3, 4 }}) {
			cout << "Rationals comparison works incorrectly" << endl;
			return 2;
		}
	}

	{
		map<Rational, int> count;
		++count[{1, 2}];
		++count[{1, 2}];

		++count[{2, 3}];

		if (count.size() != 2) {
			cout << "Wrong amount of items in the map" << endl;
			return 3;
		}
	}

	cout << "OK" << endl;
	return 0;
}