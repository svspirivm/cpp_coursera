#include<iostream>

using namespace std;

int main() {
	double n; // start price
	double a; //first cost of the good
	double x; //the first discount
	double b; //the second price
	double y; // the second discount
	cin >> n >> a >> b >> x >> y;
	if (n > 0 && a > 0 && x > 0 && b > 0 && y > 0) {
		if (n > b) {
			cout << n * (1 - y / 100);
		}
		else if (n > a) {
			cout << n * (1 - x / 100);
		}
		else if (n <= b && n <= a) {
			cout << n;
		}
	}
	return 0;
}