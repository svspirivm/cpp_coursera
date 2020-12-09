#include<iostream>
#include<cmath>

using namespace std;

int GCD(int x, int y) {
	if (fabs(x) > fabs(y)) {
		if (y == 0) return x;
		else return GCD(y, x % y);
	}
	else {
		if (x == 0) return y;
		else return GCD(x, y % x);
	}
}

int main() {
	int a, b;
	cin >> a >> b; 
	cout << GCD(a, b);
	return 0;
}