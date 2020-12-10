#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

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
		string result;
		if(m.upper_bound(y) != m.begin()) result = (*prev(m.upper_bound(y))).second;
		/*for (const auto& i : m) {
			if (i.first < y) result = i.second;
		}*/
		return result;
	}
private:
	map<int, string> names;
	map<int, string> surnames;
};

int main() {
	Person person;

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
	}

	return 0;
}