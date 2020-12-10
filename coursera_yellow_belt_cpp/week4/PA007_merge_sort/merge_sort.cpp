#include<iostream>
#include<iterator>
#include<algorithm>
#include<vector>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
	if (range_end - range_begin < 2) return;
	else {
		vector<typename RandomIt::value_type> first (range_begin, (range_end - range_begin) / 2 + range_begin);
		vector<typename RandomIt::value_type> second((range_end - range_begin) / 2 + range_begin, range_end);
		MergeSort(begin(first), end(first));
		MergeSort(begin(second), end(second));
		merge(begin(first), end(first), begin(second), end(second), range_begin);
	}
}

int main() {
	vector<int> v = { 6, 4, 7, 6, 4, 4, 0, 1 };
	MergeSort(begin(v), end(v));
	for (int x : v) {
		cout << x << " ";
	}
	cout << endl;
	return 0;
}