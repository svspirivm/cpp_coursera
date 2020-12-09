#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main() {
	int number;
	cin >> number;
	if (number < 0 || number > 1000) abort();
	else {
		vector<int> v;
		for (int i = 0; i < number; ++i) {
			int x;
			cin >> x;
			if (x >= -1000000 && x <= 1000000) {
				v.push_back(x);
			}
			else abort();
		}
		sort(begin(v), end(v), [](int l, int r) {
			return abs(l) < abs(r);
			});
		for (const auto& i : v) cout << i << " ";
	}
	
	return 0;
}