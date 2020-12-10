#include"query.h"

void Query::ClearQuery() {
	bus.clear();
	stop.clear();
	stops.clear();
}

istream& operator >> (istream& is, Query& q) {
	q.ClearQuery();
	string operation;
	is >> operation;
	if (operation == "NEW_BUS") {
		q.type = QueryType::NewBus;
		is >> q.bus;
		int number_of_stops = 0;
		is >> number_of_stops;
		while (number_of_stops > 0) {
			number_of_stops--;
			string s;
			is >> s;
			q.stops.push_back(s);
		}
	}
	else if (operation == "BUSES_FOR_STOP") {
		q.type = QueryType::BusesForStop;
		is >> q.stop;
	}
	else if (operation == "STOPS_FOR_BUS") {
		q.type = QueryType::StopsForBus;
		is >> q.bus;
	}
	else if (operation == "ALL_BUSES") q.type = QueryType::AllBuses;
	return is;
}