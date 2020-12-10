#include<iostream>

#include"phone_number.h"

using namespace std;

int main() {

	PhoneNumber n1("+375-29-coursera-cpp");
	cout << "Country code: " << n1.GetCountryCode() << "\n";
	cout << "City code: " << n1.GetCityCode() << "\n";
	cout << "Local number: " << n1.GetLocalNumber() << "\n";
	cout << "International number: " << n1.GetInternationalNumber() << "\n";
	return 0;
}

