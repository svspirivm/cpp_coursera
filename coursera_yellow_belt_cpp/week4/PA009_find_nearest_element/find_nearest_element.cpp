#include<iostream>
#include<set>
#include<algorithm>

using namespace std;

set<int>::const_iterator FindNearestElement(const set<int>& numbers, int border) {
	if (numbers.empty()) return numbers.end();     //if set is empty
	
	auto greater = numbers.upper_bound(border);
	auto greater_or_equal = numbers.lower_bound(border);

	if (greater_or_equal != greater) return greater_or_equal;  //if element exists
	else if (greater == greater_or_equal && greater == numbers.end()) return prev(greater); //if larger than the last one
	else if (greater == numbers.begin()) return greater;  // if less than the first one
	else {
		return (border - *prev(greater) <= *greater - border) ? prev(greater) : greater; //if somewhere in the middle
	}
 }


int main() {
	set<int> numbers = { 1, 4, 6 };
	cout <<
		*FindNearestElement(numbers, 0) << " " <<
		*FindNearestElement(numbers, 3) << " " <<
		*FindNearestElement(numbers, 5) << " " <<
		*FindNearestElement(numbers, 6) << " " <<
		*FindNearestElement(numbers, 100) << endl;

	set<int> empty_set;

	cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
	return 0;
}