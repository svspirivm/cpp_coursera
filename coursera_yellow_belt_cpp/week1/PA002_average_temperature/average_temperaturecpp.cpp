#include<iostream>
#include<vector>

using namespace std;

int main() {
	int number_of_days = 0;
	cin >> number_of_days;
	vector<int64_t> temperatures;
	while (number_of_days > 0) {
		number_of_days--;
		int64_t temp;
		cin >> temp;
		temperatures.push_back(temp);
	}
	int64_t average = 0;
	for (int i = 0; i < static_cast<int>(temperatures.size()); ++i) {
		average += temperatures[i];
	}
	average /= static_cast<int64_t>(temperatures.size());

	int counter = 0;
	for (int i = 0; i < static_cast<int>(temperatures.size()); ++i) {
		if (temperatures[i] > average) counter++;
	}
	cout << counter << '\n';
	for (int i = 0; i < static_cast<int>(temperatures.size()); ++i) {
		if (temperatures[i] > average) {
			cout << i;
			if (i != static_cast<int>(temperatures.size()) - 1) cout << " ";
		}
	}
	return 0;
}