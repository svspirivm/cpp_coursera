#include"database.h"
#include"node.h"
#include"test_runner.h"
#include"condition_parser.h"

Date ParseDate(istringstream& stream);
Date ParseDate(istream& stream);

string ParseEvent(istream& is) {
	string event;
	getline(is, event);
	while (event[0] == ' ') event.erase(event.begin());
	return event;
}

ostream& operator<< (ostream& stream, const pair<Date, string>& pr) {
	stream << pr.first << " " << pr.second;
	return stream;
}

ostream& operator<< (ostream& stream, const vector<pair<Date, string>>& pr) {
	for (const auto& item : pr) {
		stream << item;
		if (item != pr[pr.size() - 1]) stream << "\n";
	}
	return stream;
}

ostream& operator<<(ostream& stream, const vector<string>& v) {
	for (const auto& item : v) {
		stream << item << " ";
	}
	stream << "\n";
	return stream;
}

ostream& operator<< (ostream& stream, const map<Date, vector<string>>& m) {
	for (const auto& date : m) {
		for (const auto& ev : date.second) {
			stream << date.first << " " << ev << "\n";
		}
	}
	return stream;
}

//void TestAll();

int main() {
	//TestAll();

	Database db;

	for (string line; getline(cin, line); ) {
		istringstream is(line);

		string command;
		is >> command;
		if (command == "Add") {
			const Date date = ParseDate(is);
			const string event = ParseEvent(is);
			db.Add(date, event);
		}
		else if (command == "Print") {
			db.Print(cout);
		}
		else if (command == "Del") {
			shared_ptr<Node> condition = ParseCondition(is);
			auto predicate = [condition](const Date& date, const string& event) {
				return condition->Evaluate(date, event);
			};
			int count = db.RemoveIf(predicate);
			cout << "Removed " << count << " entries" << endl;
		}
		else if (command == "Find") {
			shared_ptr<Node> condition = ParseCondition(is);
			auto predicate = [condition](const Date& date, const string& event) {
				return condition->Evaluate(date, event);
			};

			const auto entries = db.FindIf(predicate);
			for (const auto& entry : entries) {
				cout << entry << endl;
			}
			cout << "Found " << entries.size() << " entries" << endl;
		}
		else if (command == "Last") {
			try {
				cout << db.Last(ParseDate(is)) << endl;
			}
			catch (invalid_argument&) {
				cout << "No entries" << endl;
			}
		}
		else if (command.empty()) {
			continue;
		}
		else {
			throw logic_error("Unknown command: " + command);
		}
	}

	return 0;
}

//void TestParseEvent() {
//	{
//		istringstream is("event");
//		AssertEqual(ParseEvent(is), "event", "Parse event without leading spaces");
//	}
//	{
//		istringstream is("   sport event ");
//		AssertEqual(ParseEvent(is), "sport event ", "Parse event with leading spaces");
//	}
//	{
//		istringstream is("  first event  \n  second event");
//		vector<string> events;
//		events.push_back(ParseEvent(is));
//		events.push_back(ParseEvent(is));
//		AssertEqual(events, vector<string>{"first event  ", "second event"}, "Parse multiple events");
//	}
//}
//
//void TestAll() {
//	TestRunner tr;
//	tr.RunTest(TestParseEvent, "TestParseEvent");
//	tr.RunTest(TestParseCondition, "TestParseCondition");
//}
//
