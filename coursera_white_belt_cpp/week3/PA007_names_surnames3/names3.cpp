#include<iostream>
#include<map>
#include<vector>
using namespace std;

class Person {
public:
	Person(const string& n, const string& s, const int& b) {
		birth_date = b;
		names[birth_date] = n;
		surnames[birth_date] = s;
	}
	void ChangeFirstName(const int& year, const string& first_name) {
		if (year >= birth_date) {
			names[year] = first_name;
		}
	}
	void ChangeLastName(const int& year, const string& last_name) {
		if (year >= birth_date) {
			surnames[year] = last_name;
		}
	}

	string GetFullName(const int& year) const {
		if (year < birth_date) return "No person";
		else {
			if (names.count(year) != 0) {
				if (surnames.count(year) != 0) {                             //surname and name this year
					return names.at(year) + " " + surnames.at(year);
				}
				else if (surnames.size() == 0 || CheckChanges(surnames, year) == "NULL") {
					return names.at(year) + " with unknown last name";       //name - this year, surname - never
				}
				else {
					return names.at(year) + " " + CheckChanges(surnames, year); //name - this year, surname - another year
				}
			}
			else {
				if (names.size() == 0 || CheckChanges(names, year) == "NULL") {
					if (surnames.count(year) != 0) {
						return surnames.at(year) + " with unknown first name"; //surname this year, name - never
					}
					else {
						if (surnames.size() == 0 || CheckChanges(surnames, year) == "NULL") {
							return "Incognito";                 //surname never name never
						}
						else {
							return CheckChanges(surnames, year) + " with unknown first name";//surname another year name never
						}
					}
				}
				else {
					if (surnames.count(year) != 0) {
						return CheckChanges(names, year) + " " + surnames.at(year); //name another, surname this
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
	}

	string GetFullNameWithHistory(const int& year) const {
		if (year < birth_date) return "No person";
		else {
			vector<string> n = History(names, year);
			vector<string> s = History(surnames, year);
			int n_size = n.size();
			int s_size = s.size();
			if (n_size == 0 && s_size == 0) return "Incognito";
			else if (n_size == 1 && s_size == 1) return n[0] + " " + s[0];
			else if (n_size == 0 && s_size == 1) return s[0] + " with unknown first name";
			else if (n_size == 1 && s_size == 0) return n[0] + " with unknown last name";
			else if (n_size > 1 && s_size == 0) return CreateResult(n) + " with unknown last name";
			else if (n_size == 0 && s_size > 1) return CreateResult(s) + " with unknown first name";
			else if (n_size > 1 && s_size == 1) return CreateResult(n) + " " + s[0];
			else if (n_size == 1 && s_size > 1) return n[0] + " " + CreateResult(s);
			else return CreateResult(n) + " " + CreateResult(s);
		}
	}

	string CreateResult(const vector<string>& v) const {
		string res = v[v.size() - 1];
		if (v[v.size() - 1] != v[v.size() - 2] || (v.size() > 2 && v[v.size() - 2] != v[v.size() - 3])) {
			res += " (";
			int k = v.size() - 2;
			while (k >= 0) {
				if (v[k] != v[k + 1]) res += v[k];
				if (k >= 1 && v[k - 1] != v[k] && v[k + 1] != v[k]) res += ", ";
				--k;
			}
			res += ")";
		}
		return res;
	}

	string CheckChanges(const map<int, string>& m, const int& y) const {
		string result = "NULL";
		for (const auto& i : m) {
			if (i.first < y) result = i.second;
		}
		return result;
	}

	vector <string> History(const map<int, string>& m, const int& y) const  {
		vector<string> result;
		for (const auto& i : m) {
			if (i.first <= y) result.push_back(i.second);
		}
		return result;
	}
private:
	map<int, string> names;
	map<int, string> surnames;
	int birth_date;
};


//int main() {
//	Person person("Polina", "Sergeeva", 1960);
//	for (int year : {1959, 1960}) {
//		cout << person.GetFullNameWithHistory(year) << endl;
//	}
//
//	person.ChangeFirstName(1965, "Appolinaria");
//	person.ChangeLastName(1967, "Ivanova");
//	for (int year : {1965, 1967}) {
//		cout << person.GetFullNameWithHistory(year) << endl;
//	}
//
//	return 0;
//}