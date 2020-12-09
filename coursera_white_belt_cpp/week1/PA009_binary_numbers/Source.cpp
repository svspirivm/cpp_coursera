#include<iostream>
#include<vector>

using namespace std;

int main() {
	vector<int> result;
	int n; 
	cin >> n;
	if (n > 0) {
		while (n > 0) {
			int x = n % 2;
			n /= 2;
			result.push_back(x);
		}
	}
	for (int i = result.size() - 1; i >= 0; --i) {
		cout << result[i];
	}
	return 0;
}