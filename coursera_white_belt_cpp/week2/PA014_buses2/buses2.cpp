#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

map<vector<string>, int> BUSES;

int main() {
	int number_of_operations;
	cin >> number_of_operations;
	int route = 1;
	while (number_of_operations > 0) {
		--number_of_operations;
		int number_of_stops;
		cin >> number_of_stops;
		vector<string> stops;
		while (number_of_stops > 0) {
			string stop;
			cin >> stop;
			stops.push_back(stop);
			--number_of_stops;
		}
		if (BUSES.size() == 0 || BUSES.count(stops) == 0) {
			BUSES[stops] = route;
			cout << "New bus " << BUSES[stops] << "\n";
			++route;
		}
		else {
			cout << "Already exists for " << BUSES[stops] << "\n";
		}
	}
	return 0;
}



