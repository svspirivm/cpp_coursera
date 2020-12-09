#include<iostream>
#include<set>
#include<string>
#include<map>

using namespace std;

map<string, set<string>> VOC;

int main() {
	int number_of_operations;
	cin >> number_of_operations;
	while (number_of_operations > 0) {
		--number_of_operations;
		string operation;
		cin >> operation;
		if (operation == "ADD") {
			string s1, s2;
			cin >> s1 >> s2;
			VOC[s1].insert(s2);
			VOC[s2].insert(s1);
		}
		else if (operation == "COUNT") {
			string word;
			cin >> word;
			cout << VOC[word].size() << "\n";
		}
		else if (operation == "CHECK") {
			string w1, w2;
			cin >> w1 >> w2;
			if (VOC[w1].count(w2) == 1) {
				cout << "YES\n";				
			}
			else cout << "NO\n";
		}
	}
	return 0;
}

