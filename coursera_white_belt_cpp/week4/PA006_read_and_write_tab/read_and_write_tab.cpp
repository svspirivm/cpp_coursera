#include<iostream>
#include<fstream>
#include<iomanip>
#include<vector>

using namespace std;

int main() {
	int number_of_strings;
	int number_of_columns;
	ifstream input("input.txt");
	if (input) {
		input >> number_of_strings;
		input.ignore(1);
		input >> number_of_columns;
		input.ignore(1);
		while (number_of_strings > 0) {
			--number_of_strings;
			vector<int> values;
			int n = number_of_columns;
			while (n > 0) {
				--n;
				int number;
				input >> number;
				values.push_back(number);
				input.ignore(1);
			}
			for (int i = 0; i < number_of_columns; ++i) {
				cout << setw(10) << values[i];
				if (i != number_of_columns - 1) cout << " ";
			}
			cout << '\n';
		}
	}
	return 0;
}