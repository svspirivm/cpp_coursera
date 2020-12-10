#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>


using namespace std;

enum class Gender {
	FEMALE,
	MALE
};


struct Person {
	int age; 
	Gender gender; 
	bool is_employed;  
};

template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
	if (range_begin == range_end) {
		return 0;
	}
	vector<typename InputIt::value_type> range_copy(range_begin, range_end);
	auto middle = begin(range_copy) + range_copy.size() / 2;
	nth_element(
		begin(range_copy), middle, end(range_copy),
		[](const Person& lhs, const Person& rhs) {
			return lhs.age < rhs.age;
		}
	);
	return middle->age;
}

void PrintStats(vector<Person> persons) {
	cout << "Median age = " << ComputeMedianAge(begin(persons), end(persons)) << "\n";

	auto it_sex = partition(begin(persons), end(persons),
		[](Person p) {return p.gender == Gender::FEMALE;
		});
	cout << "Median age for females = " << ComputeMedianAge(begin(persons), it_sex) << "\n";

	cout << "Median age for males = " << ComputeMedianAge(it_sex, end(persons)) << "\n";

	auto it_employed_female = partition(begin(persons), end(persons),
		[](Person p) {return p.gender == Gender::FEMALE && p.is_employed == true;
		});
	cout << "Median age for employed females = " << ComputeMedianAge(begin(persons), it_employed_female) << "\n";
		
	cout << "Median age for unemployed females = " << ComputeMedianAge(it_employed_female, it_sex) << "\n";;


	auto it_employed_male = partition(it_sex, end(persons), 
		[](Person p) {return p.is_employed == true;
		});
	cout << "Median age for employed males = " << ComputeMedianAge(it_sex, it_employed_male) << "\n";

	cout << "Median age for unemployed males = " << ComputeMedianAge(it_employed_male, end(persons)) << "\n";
}

int main() {
	vector<Person> persons = {
		{31, Gender::MALE, false},
		{40, Gender::FEMALE, true},
		{24, Gender::MALE, true},
		{20, Gender::FEMALE, true},
		{80, Gender::FEMALE, false},
		{78, Gender::MALE, false},
		{10, Gender::FEMALE, false},
		{55, Gender::MALE, true},
	};
	PrintStats(persons);
	return 0;
}