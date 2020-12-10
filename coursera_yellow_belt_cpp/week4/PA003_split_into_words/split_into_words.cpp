#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

vector<string> SplitIntoWords(const string& s) {
	vector<string> result;
	auto beginning = begin(s);
	for (auto it = begin(s); it != end(s); ++it) {
		if (*it == ' ') {
			string str(beginning, it);
			result.push_back(str);
			beginning = it + 1;
		}
		else if (it == end(s) - 1) {
			string str(beginning, it + 1);
			result.push_back(str);
		}
	}
	return result;
}

int main() {
	string s = "C Cpp Java Python";

	vector<string> words = SplitIntoWords(s);
	cout << words.size() << " ";
	for (auto it = begin(words); it != end(words); ++it) {
		if (it != begin(words)) {
			cout << "/";
		}
		cout << *it;
	}
	cout << endl;

	return 0;
}