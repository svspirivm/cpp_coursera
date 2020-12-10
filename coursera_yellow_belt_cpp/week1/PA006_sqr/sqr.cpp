#include<iostream>
#include<vector>
#include<map>

using namespace std;

template <class first, class second>
pair<first, second> operator* (const pair<first, second>& p1, const pair<first, second>& p2);

template <typename key, typename value>
map<key, value> operator * (const map<key, value> t1, const map<key, value> t2);

template<typename T>
vector<T> operator * (const vector<T>& v1, const vector<T>& v2);

template <class T>
auto Sqr(const T& x);


template <class first, class second>
pair<first, second> operator* (const pair<first, second>& p1, const pair<first, second>& p2) {
	first f = p1.first * p1.first;
	second s = p1.second * p1.second;
	return make_pair(f, s);
}
template <typename key, typename value> 
map<key, value> operator * (const map<key, value> t1, const map<key, value> t2) {
	map<key, value> result;
	for (const auto& item : t1) {
		key k = item.first;
		value v = item.second * item.second;
		result[k] = v;
	}
	return result;
}

template<typename T>
vector<T> operator * (const vector<T>& v1, const vector<T>& v2) {
	vector<T> result;
	for (const auto& item : v1) result.push_back(item * item);
	return result;
}

template <class T> 
auto Sqr(const T& x) { return x * x; }

//int main() {
//	vector<int> v = { 1, 2, 3 };
//	cout << "vector:";
//	for (int x : Sqr(v)) {
//		cout << ' ' << x;
//	}
//	cout << endl;
//
//	map<int, pair<int, int>> map_of_pairs = { {4, {2, 2}},  {7, {4, 3}}	};
//	cout << "map of pairs:" << endl;
//	for (const auto& x : Sqr(map_of_pairs)) {
//		cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
//	}
//	return 0;
//}