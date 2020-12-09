#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cctype>

using namespace std;

int main() {
	int number;
	cin >> number;
	if (number < 0 || number > 1000) abort();
	else {
		vector<string> v;
		for (int i = 0; i < number; ++i) {
			string x;
			cin >> x;
			v.push_back(x);
		}
		sort(begin(v), end(v), [](string l, string r) {
			string L;
			for (const auto& i1 : l) {
				L += tolower(i1);
			}
			string R;
			for (const auto& i2 : r) {
				R += tolower(i2);
			}
			return L < R;
			});
		for (const auto& i : v) cout << i << " ";
	}
	return 0;
}