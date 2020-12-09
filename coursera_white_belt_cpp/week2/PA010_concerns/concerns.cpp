#include<iostream>
#include<vector>
#include<string>

using namespace std;

const vector<int> DAYS_IN_MONTHS{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main() {
	int number_of_operations;
	cin >> number_of_operations;
	int current_month = 0;
	vector<vector<string>> concerns(DAYS_IN_MONTHS[current_month]);
	for (int i = 0; i < number_of_operations; ++i) {
		string operation_name;
		cin >> operation_name;
		if (operation_name == "ADD") {
			int day;
			string task;
			cin >> day >> task;
			concerns[day - 1].push_back(task);
		}
		else if (operation_name == "NEXT") {
			const int previous_month_length = DAYS_IN_MONTHS[current_month];
			current_month = (current_month + 1) % 12;
			const int next_month_length = DAYS_IN_MONTHS[current_month];
			if (next_month_length < previous_month_length) {
				for (int date = next_month_length; date < previous_month_length; ++date) {
					concerns[next_month_length - 1].insert(end(concerns[next_month_length - 1]), begin(concerns[date]), end(concerns[date]));
				}
			}
			concerns.resize(next_month_length);
		}
		else if (operation_name == "DUMP") {
			int day;
			cin >> day;
			cout << concerns[day - 1].size() << " ";
			for (const string& DoIt : concerns[day - 1]) {
				cout << DoIt << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
