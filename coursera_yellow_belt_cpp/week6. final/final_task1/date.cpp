#include "date.h"

Date::Date() {
	year = 0;
	month = 0;
	day = 0;
}

Date::Date(int y, int m, int d) {
	year = y;
	month = m;
	day = d;
}

Date ParseDate(istringstream& stream) {
	Date d;
	bool flag = true;
	flag = flag && (stream >> d.year);
	flag = flag && (stream.peek() == '-');
	stream.ignore(1);

	flag = flag && (stream >> d.month);

	flag = flag && (stream.peek() == '-');
	stream.ignore(1);

	flag = flag && (stream >> d.day);

	if (!flag)
	{
		stringstream ex_ss;
		ex_ss << "Wrong date format" << stream.rdbuf();
		throw logic_error(ex_ss.str());
	}
	return d;
}

Date ParseDate(istream& stream) {
	Date d;
	bool flag = true;
	flag = flag && (stream >> d.year);
	flag = flag && (stream.peek() == '-');
	stream.ignore(1);

	flag = flag && (stream >> d.month);

	flag = flag && (stream.peek() == '-');
	stream.ignore(1);

	flag = flag && (stream >> d.day);

	if (!flag)
	{
		stringstream ex_ss;
		ex_ss << "Wrong date format" << stream.rdbuf();
		throw logic_error(ex_ss.str());
	}
	return d;
}

bool operator< (const Date& lhs, const Date& rhs) {
	if (lhs.year < rhs.year) return true;
	else if (lhs.year > rhs.year) return false;
	else {
		if (lhs.month < rhs.month) return true;
		else if (lhs.month > rhs.month) return false;
		else {
			if (lhs.day < rhs.day) return true;
			else return false;
		}
	}
	return false;
}

bool operator==(const Date& lhs, const Date& rhs) {
	if (lhs.year == rhs.year && lhs.month == rhs.month && lhs.day == rhs.day) return true;
	return false;
}

bool operator!=(const Date& lhs, const Date& rhs) {
	if (lhs == rhs) return false;
	return true;
}

bool operator<=(const Date& lhs, const Date& rhs) {
	if (lhs < rhs || lhs == rhs) return true;
	return false;
}

bool operator>(const Date& lhs, const Date& rhs) {
	if (!(lhs < rhs || lhs == rhs)) return true;
	return false;
}

bool operator>=(const Date& lhs, const Date& rhs) {
	if (lhs > rhs || lhs == rhs) return true;
	return false;
}

ostream& operator<< (ostream& stream, const Date& date) {
	stream << setw(4) << setfill('0') << date.year << '-'
		<< setw(2) << setfill('0') << date.month << '-'
		<< setw(2) << setfill('0') << date.day;
	return stream;
}