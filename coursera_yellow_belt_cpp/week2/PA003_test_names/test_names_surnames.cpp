#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

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


class Person {
public:
	void ChangeFirstName(int year, const string& first_name) {
		names[year] = first_name;
	}
	void ChangeLastName(int year, const string& last_name) {
		surnames[year] = last_name;
	}

	string GetFullName(int year) {
		if (names.count(year) != 0) {
			if (surnames.count(year) != 0) {                             //surname and name this year
				return names[year] + " " + surnames[year];
			}
			else if (surnames.size() == 0 || CheckChanges(surnames, year) == "NULL") {
				return names[year] + " with unknown last name";       //name - this year, surname - never
			}
			else {
				return names[year] + " " + CheckChanges(surnames, year); //name - this year, surname - another year
			}
		}
		else {
			if (names.size() == 0 || CheckChanges(names, year) == "NULL") {
				if (surnames.count(year) != 0) {
					return surnames[year] + " with unknown first name"; //surname this year, name - never
				}
				else {
					if (surnames.size() == 0 || CheckChanges(surnames, year) == "NULL") {
						return "Incognito";//surname never name never
					}
					else {
						return CheckChanges(surnames, year) + " with unknown first name";//surname another year name never
					}
				}
			}
			else {
				if (surnames.count(year) != 0) {
					return CheckChanges(names, year) + " " + surnames[year]; //name another, surname this
				}
				else {
					if (surnames.size() == 0 || CheckChanges(surnames, year) == "NULL") {
						return CheckChanges(names, year) + " with unknown last name"; // name another surname never
					}
					else return CheckChanges(names, year) + " " + CheckChanges(surnames, year);// name another surname another
				}
			}
		}
	}

	string CheckChanges(const map<int, string>& m, const int& y) {
		string result = "NULL";
		for (const auto& i : m) {
			if (i.first < y) result = i.second;
		}
		return result;
	}
private:
	map<int, string> names;
	map<int, string> surnames;
};

void Test() {
	Person person;
	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");

	AssertEqual(person.GetFullName(1964), "Incognito");
	AssertEqual(person.GetFullName(1966), "Polina with unknown last name");
	AssertEqual(person.GetFullName(1965), "Polina with unknown last name");
	AssertEqual(person.GetFullName(1968), "Polina Sergeeva");
	AssertEqual(person.GetFullName(1967), "Polina Sergeeva");

	Person p1;
	p1.ChangeLastName(1990, "Petrov");
	p1.ChangeFirstName(2000, "Andrew");
	p1.ChangeLastName(2010, "Ivanov");
	p1.ChangeFirstName(2010, "Sergey");

	AssertEqual(p1.GetFullName(1990), "Petrov with unknown first name");
	AssertEqual(p1.GetFullName(1995), "Petrov with unknown first name");
	AssertEqual(p1.GetFullName(2000), "Andrew Petrov");
	AssertEqual(p1.GetFullName(2010), "Sergey Ivanov");


}

int main() {
	TestRunner tr;
	tr.RunTest(Test, "ChangeName");

	/*Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}*/

	return 0;
}