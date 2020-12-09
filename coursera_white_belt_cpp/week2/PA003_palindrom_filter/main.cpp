#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool IsPalindrom(string s) {
	for (int i = 0; i < s.size() / 2; ++i) {
		if (s[i] != s[s.size() - 1 - i]) return false;
	}
	return true;
}


vector<string> PalindromFilter(vector<string> words, int minLength) {
	vector<string> result;
	for (auto w : words) {
		if (w.size() >= minLength && IsPalindrom(w)) {
				result.push_back(w);
		}
	}
	return result;
}


int main() {
	int length = 2;
	vector<string> input{ "lol", "k", "pelmen", "" , " " , "madam" };
	PalindromFilter(input, length);
	return 0;
}