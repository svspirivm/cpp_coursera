#include<iostream>
#include<string>
#include<iterator>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, const string& prefix) {
	string pr;
	pr = prefix;

	auto it_begin = lower_bound(range_begin, range_end, pr);

	string str = prefix;
	str.pop_back();
	str += prefix[prefix.size() - 1] + 1;
	
	auto it_end = lower_bound(range_begin, range_end, str);
	return make_pair(it_begin, it_end);
}

int main() {
	const vector<string> sorted_strings = { "moscow", "motovilikha", "murmansk" };

	const auto mo_result =
		FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
	for (auto it = mo_result.first; it != mo_result.second; ++it) {
		cout << *it << " ";
	}
	cout << endl;

	const auto mt_result =
		FindStartsWith(begin(sorted_strings), end(sorted_strings), "mt");
	cout << (mt_result.first - begin(sorted_strings)) << " " <<
		(mt_result.second - begin(sorted_strings)) << endl;

	const auto na_result =
		FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
	cout << (na_result.first - begin(sorted_strings)) << " " <<
		(na_result.second - begin(sorted_strings)) << endl;

	return 0;
}