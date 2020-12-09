#include<iostream>
#include<string>

using namespace std;

int main() {
	string str;
	cin >> str;
	int number = 0;
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == 'f') {
			number++;
			if (number == 2) {
				cout << i;
				break;
			}
		}
	}
	if (number == 1) cout << -1;
	else if (number == 0) cout << -2;
	return 0;
}
