#include<iostream>
#include<map>
#include<string>

using namespace std;

map<char, int> BuildCharCounters(const string& s) {
	map <char, int> result;
	for (const char& symbol : s) {
		++result[symbol];
	}
	return result;
}

int main() {
	int number_of_pairs;
	cin >> number_of_pairs;
	string s1, s2;
	while (number_of_pairs > 0) {
		cin >> s1 >> s2;
		if (BuildCharCounters(s1) == BuildCharCounters(s2)) cout << "YES\n";
		else cout << "NO\n";
		--number_of_pairs;
	}

	return 0;
}