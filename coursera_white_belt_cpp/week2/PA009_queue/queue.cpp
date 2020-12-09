#include<iostream>      //quiet - false
#include<vector>	//worry - true
#include<string>
#include<cmath>

using namespace std;

vector<bool> queue(false);
vector<int> result;

void Check(string ops, int k) {
	if (ops == "COME") {
		if (k > 0) {
			while (k > 0) {
				queue.push_back(false);
				k--;
			}
		}
		else if (k < 0) {
			while (k < 0) {
				queue.pop_back();
				k++;
			}
		}
	}
	else if (ops == "WORRY") {
		queue[k] = true;
	}
	else if (ops == "QUIET") {
		queue[k] = false;
	}
	else if (ops == "WORRY_COUNT") {
		int amount = 0;
		for (auto i : queue) {
			if (i == true) ++amount;
		}
		result.push_back(amount);
	}
}



int main() {
	int number_of_operations;
	cin >> number_of_operations;
	string operation;
	int x;
	while (number_of_operations > 0) {
		number_of_operations--;
		cin >> operation;
		if (operation == "WORRY_COUNT") x = 0;
		else cin >> x;
		Check(operation, x);
	}
	for (auto r : result) cout << r << "\n";
	return 0;
}