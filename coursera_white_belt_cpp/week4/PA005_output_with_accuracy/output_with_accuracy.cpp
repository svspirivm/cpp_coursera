#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

int main() {
	ifstream input("input.txt");
	double number = 0;
	cout << fixed << setprecision(3);
	if (input) {
		while (input >> number) {
			cout << number << '\n';
		}
	}
	return 0;
}