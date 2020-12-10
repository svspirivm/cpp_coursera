#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

void PrintPermutations(const int& n) {
	vector<int> numbers;
	int i = n;
	while (i > 0) {
		numbers.push_back(i);
		i--;
	}

	int64_t number_of_permutations = 1;
	for (const auto& item : numbers) number_of_permutations *= item;

	set<vector<int>> all_permutations;
	all_permutations.insert(numbers);
	while (all_permutations.size() < number_of_permutations) {
		next_permutation(begin(numbers), end(numbers));
		all_permutations.insert(numbers);
	}

	for (auto it = rbegin(all_permutations); it != rend(all_permutations); it++) {
		for (const auto& item : *it) cout << item << " ";
		cout << "\n";
	}
}

int main() {
	int number = 0;
	cin >> number;
	PrintPermutations(number);

	return 0;
}