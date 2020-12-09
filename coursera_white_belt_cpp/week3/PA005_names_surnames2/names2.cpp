#include<iostream>
#include<map>
#include<vector>
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



	string GetFullNameWithHistory(int year) {
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

	string CreateResult(const vector<string>& v) {
		string res = v[v.size() - 1];
		if (v[v.size() - 1] != v[v.size() - 2] || (v.size() > 2 && v[v.size() - 2] != v[v.size() - 3])) {
			res += " (";
			int k = v.size() - 2;
			while (k >= 0) {
				if (v[k] != v[k + 1]) res += v[k];
				if (k >= 1 && v[k - 1] != v[k] && v[k+1] != v[k]) res += ", ";
				--k;
			}
			res += ")";
		}
		return res;
	}

	string CheckChanges(const map<int, string>& m, const int& y) {
		string result = "NULL";
		for (const auto& i : m) {
			if (i.first < y) result = i.second;
		}
		return result;
	}

	vector <string> History(const map<int, string>& m, const int& y) {
		vector<string> result;
		for (const auto& i : m) {
			if (i.first <= y) result.push_back(i.second);
		}
		return result;
	}
private:
	map<int, string> names;
	map<int, string> surnames;
};


//int main() {
//	Person person;
//
//	person.ChangeFirstName(1965, "Polina");
//	person.ChangeLastName(1967, "Sergeeva");
//	for (int year : {1900, 1965, 1990}) {
//		cout << person.GetFullNameWithHistory(year) << endl;
//	}
//
//	person.ChangeFirstName(1970, "Appolinaria");
//	for (int year : {1969, 1970}) {
//		cout << person.GetFullNameWithHistory(year) << endl;
//	}
//
//	person.ChangeLastName(1968, "Volkova");
//	for (int year : {1969, 1970}) {
//		cout << person.GetFullNameWithHistory(year) << endl;
//	}
//
//	person.ChangeFirstName(1990, "Polina");
//	person.ChangeLastName(1990, "Volkova-Sergeeva");
//	cout << person.GetFullNameWithHistory(1990) << endl;
//
//	person.ChangeFirstName(1966, "Pauline");
//	cout << person.GetFullNameWithHistory(1966) << endl;
//
//	person.ChangeLastName(1960, "Sergeeva");
//	for (int year : {1960, 1967}) {
//		cout << person.GetFullNameWithHistory(year) << endl;
//	}
//
//	person.ChangeLastName(1961, "Ivanova");
//	cout << person.GetFullNameWithHistory(1967) << endl;
//
//	return 0;
//}

//int main() {
//	Person person;
//
//	person.ChangeFirstName(1900, "Eugene");
//	person.ChangeLastName(1900, "Sokolov");
//	person.ChangeLastName(1910, "Sokolov");
//	person.ChangeFirstName(1920, "Evgeny");
//	person.ChangeLastName(1930, "Sokolov");
//	cout << person.GetFullNameWithHistory(1940) << endl;
//
//	return 0;
//}


//int main() {
//	Person person;
//
//	person.ChangeFirstName(1965, "Polina");
//	person.ChangeLastName(1967, "Sergeeva");
//	for (int year : {1900, 1965, 1990}) {
//		cout << person.GetFullNameWithHistory(year) << endl;
//	}
//
//	person.ChangeFirstName(1970, "Appolinaria");
//	for (int year : {1969, 1970}) {
//		cout << person.GetFullNameWithHistory(year) << endl;
//	}
//
//	person.ChangeLastName(1968, "Volkova");
//	for (int year : {1969, 1970}) {
//		cout << person.GetFullNameWithHistory(year) << endl;
//	}
//
//	person.ChangeFirstName(1990, "Polina");
//	person.ChangeLastName(1990, "Volkova"); //-Sergeeva
//	cout << person.GetFullNameWithHistory(1990) << endl;
//
//	person.ChangeFirstName(1966, "Pauline");
//	cout << person.GetFullNameWithHistory(1966) << endl;
//
//	person.ChangeLastName(1960, "Sergeeva");
//	for (int year : {1960, 1967}) {
//		cout << person.GetFullNameWithHistory(year) << endl;
//	}
//
//  	person.ChangeLastName(1961, "Ivanova");
//	for (int year : {1960, 1967, 1990}) {
//		cout << person.GetFullNameWithHistory(year) << endl;
//	}
//
//	person.ChangeFirstName(1901, "Polina");
//	person.ChangeLastName(1901, "Sergeeva");
//	for (int year : {1900, 1960, 1967, 1990, 1991}) {
//		cout << person.GetFullNameWithHistory(year) << endl;
//	}
//
//
//	return 0;
//}



//int main() {
//	Person person;
//
//	person.ChangeFirstName(1965, "Polina");
//	person.ChangeLastName(1967, "Sergeeva");
//	person.ChangeFirstName(1970, "Appolinaria");
//	person.ChangeLastName(1968, "Volkova");
//	person.ChangeFirstName(1990, "Polina");
//	person.ChangeLastName(1990, "Volkova"); //-Sergeeva
//
//	cout << person.GetFullNameWithHistory(1990) << endl;
//
//	person.ChangeFirstName(1966, "Pauline");
//	person.ChangeLastName(1960, "Sergeeva");
//	person.ChangeLastName(1961, "Ivanova");
//
//	cout << person.GetFullNameWithHistory(1990) << endl;
//
//	person.ChangeFirstName(1901, "Polina");
//	person.ChangeLastName(1901, "Sergeeva");
//
//	for (int year : {1990, 1991}) {
//		cout << person.GetFullNameWithHistory(year) << endl;
//	}
//	return 0;
//}