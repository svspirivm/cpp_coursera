#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> temperature(n);
	int average = 0;
	for (int j = 0; j < temperature.size(); ++j) {
		cin >> temperature[j];
		average += temperature[j];
	}
	average /= n;
	vector<int> result;
	for (int i = 0; i < temperature.size(); ++i) {
		if (temperature[i] > average) {
			result.push_back(i);
		}
	}
	cout << result.size() << "\n";
	for (auto r : result) {
		cout << r << " ";
	}
	return 0;
}