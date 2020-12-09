#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int Factorial(int a) {
	int result = a;
	if (a <=0 ) return 1;
	else {
		for (int i = a; i > 1; --i) {
			result *= (i - 1);
		}
	}
	return result;
}


int main() {
	int n;
	cin >> n;
	cout << Factorial(n);
	return 0;
 }
