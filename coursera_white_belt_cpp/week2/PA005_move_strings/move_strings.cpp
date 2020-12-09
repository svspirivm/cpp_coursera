#include<iostream>
#include<string>
#include<vector>

using namespace std;

void MoveStrings(vector<string>& source, vector<string>& destination) {
	for (auto r : source) {
		destination.push_back(r);
	}
	source.clear();
}

/*int main() {
	vector<string> s{"a", "b", "c"};
	vector<string> d{"z"};
	MoveStrings(s, d);
	for (auto a : d) cout << a << " ";
	cout << " ";
	for (auto x : s) cout << x << " ";
	return 0;
}*/