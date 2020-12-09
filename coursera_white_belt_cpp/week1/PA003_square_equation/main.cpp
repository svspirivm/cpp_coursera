#include<iostream>
#include<cmath>

using namespace std;

int main() {
	double a, b, c;
	cin >> a >> b >> c;
	double x1, x2;
	double D = b * b - 4 * a * c;
	if (a != 0) {
		if (D == 0) cout << -b / (2 * a);
		else {
			if (D > 0) {
				x1 = (-b + sqrt(D)) / (2 * a);
				x2 = (-b - sqrt(D)) / (2 * a);
				cout << x1 << ' ' << x2;
			}
		}
	}
	else if (a == 0 && b != 0) cout << -c / b;
	return 0;
}