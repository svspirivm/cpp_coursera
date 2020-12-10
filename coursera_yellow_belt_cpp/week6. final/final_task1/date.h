#pragma once

#include<iostream>
#include<iomanip>
#include<string>
#include<sstream>
#include<algorithm>
#include<stdexcept>

using namespace std;

class Date
{
public:
	Date();
	Date(int y, int m, int d);
	friend Date ParseDate(istringstream& stream);
	friend Date ParseDate(istream& stream);
	friend ostream& operator<< (ostream& stream, const Date& date);
	
	friend bool operator<(const Date& lhs, const Date& rhs);
	friend bool operator==(const Date& lhs, const Date& rhs);
	friend bool operator!=(const Date& lhs, const Date& rhs);
	friend bool operator<=(const Date& lhs, const Date& rhs);
	friend bool operator>(const Date& lhs, const Date& rhs);
	friend bool operator>=(const Date& lhs, const Date& rhs);
private:
	int year;
	int month;
	int day;
};

