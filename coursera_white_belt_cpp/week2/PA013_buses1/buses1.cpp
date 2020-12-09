#include<iostream>
#include<map>
#include<string>
#include<vector>

using namespace std;

map<string, vector<string>> BUS;
vector<string> BUSES_IN_ORDER;

vector<string> WhatBuses(const string& s) {
	vector<string> buses_match;
	for (const auto& bus : BUSES_IN_ORDER) {
		for (int i = 0; i < BUS[bus].size(); ++i) {
			if (BUS[bus][i] == s) buses_match.push_back(bus);
		}
	}
	return buses_match;
}



int main() {
	int number_of_operations;
	cin >> number_of_operations;
	string operation;
	while (number_of_operations > 0) {
		cin >> operation;
		--number_of_operations;
		if (operation == "NEW_BUS") {
			string bus;
			int stop_count;
			cin >> bus >> stop_count;
			vector <string> stops;
			while (stop_count > 0) {
				string stop;
				cin >> stop;
				stops.push_back(stop);
				--stop_count;
			}
			BUS[bus] = stops;
			BUSES_IN_ORDER.push_back(bus);
		}
		else if (operation == "ALL_BUSES") {
			if (BUS.empty()) {
				cout << "No buses\n";
			}
			else {
				for (const auto& item : BUS) {
					cout << "Bus " << item.first << ": ";
					for (const auto& s : item.second) {
						cout << s << " ";
					}
					cout << "\n";
				}
			}
		}
		else if (operation == "BUSES_FOR_STOP") {
			string stop;
			cin >> stop;
			if (WhatBuses(stop).size() == 0) cout << "No stop\n";
			else {
				for (const auto& b : WhatBuses(stop)) {
					cout << b << " ";
				}
				cout << "\n";
			}
		}
		else if (operation == "STOPS_FOR_BUS") {
			string bus;
			cin >> bus;
			if (BUS.count(bus) == 0) cout << "No bus\n";
			else {
				for (const auto& item : BUS[bus]) {
					cout << "Stop " << item << ":";
					if ((WhatBuses(item).size() == 1) && (WhatBuses(item)[0] == bus)) cout << " no interchange\n";
					else {
						for (const auto& b : WhatBuses(item)) {
							if (b != bus) cout << " " << b;
						}
						cout << "\n";
					}
				}
			}
		}
	}
	
	return 0;
}