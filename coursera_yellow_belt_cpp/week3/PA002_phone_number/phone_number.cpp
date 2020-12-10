#include"phone_number.h"

#include<stdexcept>

PhoneNumber::PhoneNumber(const string& international_number) {
	if (international_number[0] != '+') throw invalid_argument("wrong number");
	else {
		int country_end_index = 0;
		string country_code;
		for (int i = 1; i < international_number.size(); ++i) {
			if (international_number[i] == '-') {
				country_end_index = i;
				break;
			}
			else country_code += international_number[i];
		}
		if (country_end_index == 0) throw invalid_argument("wrong number");
		else {
			country_code_ = country_code;
			int city_end_index = country_end_index + 1;
			string city_code;
			for (int i = city_end_index; i < international_number.size(); ++i) {
				if (international_number[i] == '-') {
					city_end_index = i;
					break;
				}
				else city_code += international_number[i];
			}
			if (city_end_index == country_end_index + 1) throw invalid_argument("wrong number");
			else {
				city_code_ = city_code;
				int rest_index = city_end_index + 1;
				string local;
				for (int i = rest_index; i < international_number.size(); ++i) {
					local += international_number[i];
				}
				local_number_ = local;
			}
		}
	}
}

string PhoneNumber::GetCountryCode() const {
	return country_code_;
}

string PhoneNumber::GetCityCode() const {
	return city_code_;
}

string PhoneNumber::GetLocalNumber() const {
	return local_number_;
}

string PhoneNumber::GetInternationalNumber() const {
	return "+" + country_code_ + "-" + city_code_ + "-" + local_number_;
}