#include<iostream>
#include<map>
#include<set>
#include<string>
#include<sstream>
#include<iomanip>
#include<stdexcept>

using namespace std;

class Date {
public:
	int GetYear() const {
		return year;
	}
	int GetMonth() const {
		return month;
	}
	int GetDay() const {
		return day;
	}
	friend Date ParseDate(const string& date);
	bool operator<(const Date& date) const {
		if (this->year < date.year) return true;
		else if (this->year > date.year) return false;
		else {
			if (this->month < date.month) return true;
			else if (this->month > date.month) return false;
			else {
				if (this->day < date.day) return true;
				else return false;
			}
		}
	}
	friend ostream& operator<< (ostream& stream, const Date& f);
private:
	int year = 0;
	int month = 0;
	int day = 0;
};

ostream& operator<< (ostream& stream, const Date& date) {
	stream << setw(4) << setfill('0') << date.year << '-'
		<< setw(2) << setfill('0') << date.month << '-'
		<< setw(2) << setfill('0') << date.day;
	return stream;
}

Date ParseDate(const string& date) {
	Date d;
	stringstream stream;
	stream << date;
	bool flag = true;
	flag = flag && (stream >> d.year);
	flag = flag && (stream.peek() == '-');
	stream.ignore(1);

	flag = flag && (stream >> d.month);
	
	flag = flag && (stream.peek() == '-');
	stream.ignore(1);

	flag = flag && (stream >> d.day);

	flag = flag && stream.eof();

	if (!flag)
	{
		stringstream ex_ss;
		ex_ss << "Wrong date format: " << date;
		throw logic_error(ex_ss.str());
	}
	return d;
}

void CheckDate(const Date& date) {
	if (date.GetMonth() > 12 || date.GetMonth() < 1) {
		stringstream ex_ss;
		ex_ss << "Month value is invalid: " << date.GetMonth();
		throw out_of_range(ex_ss.str());
	}
	if (date.GetDay() > 31 || date.GetDay() < 1) {
		stringstream ex_ss;
		ex_ss << "Day value is invalid: " << date.GetDay();
		throw out_of_range(ex_ss.str());
	}

}

class Database {
public:
	void AddEvent(const Date& date, const string& event) {
		if (EVENTS.count(date) != 0) {
			EVENTS.at(date).insert(event);
		}
		else {
			EVENTS[date] = {};
			EVENTS[date].insert(event);
		}
	}
	bool DeleteEvent(const Date& date, const string& event) {
		if (EVENTS.count(date) == 0) {
			cout << "Event not found\n";
			return false;
		} 
		else {
			if (EVENTS[date].count(event) != 0) {
				EVENTS[date].erase(event);
				cout << "Deleted successfully\n";
				return true;
			}
			else {
				cout << "Event not found\n";
				return false;
			}
		}
	}
	int  DeleteDate(const Date& date) {
		int n = EVENTS[date].size();
		EVENTS.erase(date);
		cout << "Deleted " << n << " events\n";
		return n;
	}
	Date Find(const Date& date) const {
		if (EVENTS.count(date) != 0) {
			for (const auto& i : EVENTS.at(date)) {
				cout << i << '\n';
			}
		}
		return date;
	}
	void Print() const {
		for (const auto& element : EVENTS) {
			for (const auto event : element.second) {
				cout << element.first << " " << event << "\n";
			}
		}
	}
private:
	map <Date, set<string>> EVENTS;
};



int main() {
	Database db;
	string command;	
	try {
		while (getline(cin, command)) {
			if (command == "") continue;
			stringstream ss;
			ss << command;
			string operation;
			string date;
			string ev;
			ss >> operation >> date;
			if (operation != "") {
				if (operation == "Add") {
					ss >> ev;
						Date d = ParseDate(date);
						CheckDate(d);
						db.AddEvent(d, ev);
				}
				else if (operation == "Del") {
					Date d = ParseDate(date);
					CheckDate(d);
					if (!ss.eof()) {
						ss >> ev;
						if (!ev.empty()) db.DeleteEvent(d, ev);
						else db.DeleteDate(d);
					}
					else db.DeleteDate(d);
				}
				else if (operation == "Find") {
					Date d = ParseDate(date);
					CheckDate(d);
					db.Find(d);
				}
				else if (operation == "Print") {
					db.Print();
				}
				else {
					stringstream ex_ss;
					ex_ss << "Unknown command: " << operation << '\n';
					throw invalid_argument(ex_ss.str());
				}
			}

		}
	}
	catch (exception & ex) {
		cout << ex.what();
	}
	return 0;
}