#include<iostream>
#include<map>
#include<string>

using namespace std;

map<string, string> COUNTRIES;

int main() {
	int number_of_operations;
	cin >> number_of_operations;
	string operation;
	string country;
	string new_capital;
	string new_country_name;
	string old_country_name;
	while (number_of_operations > 0) {
		number_of_operations--;
		cin >> operation;
		if (operation == "CHANGE_CAPITAL") {
			cin >> country >> new_capital;
			if (COUNTRIES[country] == "") {
				COUNTRIES[country] = new_capital;
				cout << "Introduce new country " << country << " with capital " << new_capital << "\n";
			}
			else if (COUNTRIES[country] == new_capital) {
				cout << "Country " << country << " hasn't changed its capital\n";
			}
			else if (COUNTRIES[country] != new_capital) {
				cout << "Country " << country << " has changed its capital from " << COUNTRIES[country] << " to " << new_capital << "\n";
				COUNTRIES[country] = new_capital;
			}
		}
		else if (operation == "RENAME") {
			cin >> old_country_name >> new_country_name;
			if ((old_country_name == new_country_name) || (COUNTRIES.count(old_country_name) == 0) || (COUNTRIES.count(new_country_name) != 0)) {
				cout << "Incorrect rename, skip\n";
			}
			else {
				cout << "Country " << old_country_name << " with capital " << COUNTRIES[old_country_name] << " has been renamed to " << new_country_name << "\n";
				COUNTRIES[new_country_name] = COUNTRIES[old_country_name];
				for (auto it = COUNTRIES.begin(); it != COUNTRIES.end(); ) {
					if (it->first == old_country_name)
						it = COUNTRIES.erase(it);
					else ++it;
				}
			}
		}
		else if (operation == "DUMP") {
			if (COUNTRIES.empty()) cout << "There are no countries in the world\n";
			else {
				for (const auto& item : COUNTRIES) cout << item.first << "/" << item.second << "\n";
			}
		}
		else if (operation == "ABOUT") {
			cin >> country;
			if (COUNTRIES.count(country) == 0) cout << "Country " << country << " doesn't exist\n";
			else cout << "Country " << country << " has capital " << COUNTRIES[country] << "\n";
		}
	}

	return 0;
}