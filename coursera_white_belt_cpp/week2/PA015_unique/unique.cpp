#include<iostream>
#include<string>
#include<vector>
#include<set>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<string> strings;
	while (n > 0) {
		string s;
		cin >> s;
		strings.push_back(s);
		--n;
	}
	set<string> unique_strings(begin(strings), end(strings));
	cout << unique_strings.size();
	return 0;
}