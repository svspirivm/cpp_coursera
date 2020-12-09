#include<iostream>
#include<string>
#include<vector>
#include<set>

using namespace std;

class SortedStrings {
public:
	void AddString(const string& s) {
		s_strings.insert(s);
	}
	vector<string> GetSortedStrings() {
		vector<string> result;
		for (const string& s : s_strings) {
			result.push_back(s);
		}
		return result;
	}
private:
	multiset<string> s_strings;
};

//void PrintSortedStrings(SortedStrings& strings) {
//	for (const string& s : strings.GetSortedStrings()) {
//		cout << s << " ";
//	}
//	cout << endl;
//}
//
//int main() {
//	SortedStrings strings;
//
//	strings.AddString("first");
//	strings.AddString("third");
//	strings.AddString("second");
//	PrintSortedStrings(strings);
//
//	strings.AddString("second");
//	PrintSortedStrings(strings);
//
//	return 0;
//}