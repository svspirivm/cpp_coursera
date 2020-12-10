#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <exception>
#include<stdexcept>
#include<iomanip>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
	os << "{";
	bool first = true;
	for (const auto& x : s) {
		if (!first) {
			os << ", ";
		}
		first = false;
		os << x;
	}
	return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
	os << "{";
	bool first = true;
	for (const auto& x : s) {
		if (!first) {
			os << ", ";
		}
		first = false;
		os << x;
	}
	return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
	os << "{";
	bool first = true;
	for (const auto& kv : m) {
		if (!first) {
			os << ", ";
		}
		first = false;
		os << kv.first << ": " << kv.second;
	}
	return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
	if (t != u) {
		ostringstream os;
		os << "Assertion failed: " << t << " != " << u;
		if (!hint.empty()) {
			os << " hint: " << hint;
		}
		throw runtime_error(os.str());
	}
}

void Assert(bool b, const string& hint) {
	AssertEqual(b, true, hint);
}

class TestRunner {
public:
	template <class TestFunc>
	void RunTest(TestFunc func, const string& test_name) {
		try {
			func();
			cerr << test_name << " OK" << endl;
		}
		catch (exception & e) {
			++fail_count;
			cerr << test_name << " fail: " << e.what() << endl;
		}
		catch (...) {
			++fail_count;
			cerr << "Unknown exception caught" << endl;
		}
	}

	~TestRunner() {
		if (fail_count > 0) {
			cerr << fail_count << " unit tests failed. Terminate" << endl;
			exit(1);
		}
	}

private:
	int fail_count = 0;
};

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

Rational Input() {
	int a, b;
	cin >> a;
	cin.ignore(1);
	cin >> b;
	return Rational{ a, b };
}

void Test() {
	Rational r;
	AssertEqual(r.Numerator(), 0);
	AssertEqual(r.Denominator(), 1);

	Rational r1(4, 6);
	AssertEqual(r1.Numerator(), 2);
	AssertEqual(r1.Denominator(), 3);

	Rational r2(4, -6);
	AssertEqual(r2.Numerator(), -2);
	AssertEqual(r2.Denominator(), 3);

	Rational r3(-5, -6);
	AssertEqual(r3.Numerator(), 5);
	AssertEqual(r3.Denominator(), 6);

	Rational r4(0, -6);
	AssertEqual(r4.Numerator(), 0);
	AssertEqual(r4.Denominator(), 1);
}

int main() {
	TestRunner runner;
	runner.RunTest(Test, "Test");
	return 0;
}
