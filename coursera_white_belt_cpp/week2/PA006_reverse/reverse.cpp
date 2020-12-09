#include<iostream>
#include<vector>

using namespace std;

void Reverse(vector<int>& v) {
	vector<int> tmp;
	for (auto x : v) tmp.push_back(x);
	for (int i = tmp.size() - 1; i >= 0; --i) {
		v[v.size() - 1 - i] = tmp[i];
	}
}

/*int main() {
	vector<int> numbers{1, 2, 3, 4, 5};
	Reverse(numbers);
	for (auto z : numbers) cout << z << " ";
	return 0;
}*/