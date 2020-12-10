#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
	if (range_end - range_begin < 2) return;
	else {
		vector<typename RandomIt::value_type> first(range_begin, (range_end - range_begin) / 3 + range_begin);
		vector<typename RandomIt::value_type> second((range_end - range_begin) / 3 + range_begin, 2 * (range_end - range_begin) / 3 + range_begin);
		vector<typename RandomIt::value_type> third(2 * (range_end - range_begin) / 3 + range_begin, range_end);
		MergeSort(begin(first), end(first));
		MergeSort(begin(second), end(second));
		MergeSort(begin(third), end(third));

		vector<typename RandomIt::value_type> tmp;
		merge(begin(first), end(first), begin(second), end(second), back_inserter(tmp));
		merge(begin(tmp), end(tmp), begin(third), end(third), range_begin);
	}
}

int main() {
	vector<int> v = { 6, 4, 7, 6, 4, 4, 0, 1, 5 };
	MergeSort(begin(v), end(v));
	for (int x : v) {
		cout << x << " ";
	}
	cout << endl;
	return 0;
}