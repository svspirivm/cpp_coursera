#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
	NewBus,
	BusesForStop,
	StopsForBus,
	AllBuses
};

struct Query {
	QueryType type;
	string bus;
	string stop;
	vector<string> stops;
	void ClearQuery() {
		bus.clear();
		stop.clear();
		stops.clear();
	}
};

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

struct BusesForStopResponse {
	string stop;
	vector<string> buses_to_stop;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
	if (r.buses_to_stop.size() == 0) os << "No stop";
	else {
		for (int i = 0; i < r.buses_to_stop.size(); ++i) {
			os << r.buses_to_stop[i];
			if (i != r.buses_to_stop.size() - 1) os << " ";
		}
	}
	return os;
}

struct StopsForBusResponse {
	string bus;
	vector<BusesForStopResponse> stops_with_buses;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
	if (r.stops_with_buses.size() == 0) os << "No bus";
	else {
		for (int i = 0; i < r.stops_with_buses.size(); ++i) {
			os << "Stop " << r.stops_with_buses[i].stop << ":";
			os << " " << r.stops_with_buses[i];
			if (i != r.stops_with_buses.size() - 1) os << "\n";
		}
	}
	return os;
}

struct AllBusesResponse {
	vector<string> buses_for_output;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
	if (r.buses_for_output.size() > 0) {
		for (int i = 0; i < r.buses_for_output.size(); i++) {
			os << r.buses_for_output[i];
			if (i != r.buses_for_output.size() - 1) os << "\n";
		}
	}
	else os << "No buses";
	return os;
}

class BusManager {
public:
	void AddBus(const string& bus, const vector<string>& stops) {
		stops_to_buses[bus] = stops;
		for (const auto& s : stops) {
			if (buses_to_stops.count(s) > 0) buses_to_stops.at(s).push_back(bus);
			else buses_to_stops[s].push_back(bus);
		}
	}

	BusesForStopResponse GetBusesForStop(const string& stop) const {
		BusesForStopResponse result;
		if (buses_to_stops.count(stop) > 0) {
			result.stop = stop;
			result.buses_to_stop = buses_to_stops.at(stop);
		}
		return result;
	}

	StopsForBusResponse GetStopsForBus(const string& bus) const {
		StopsForBusResponse result;
		if (stops_to_buses.count(bus) > 0) {
			result.bus = bus;
			for (const auto& station : stops_to_buses.at(bus)) {
				BusesForStopResponse s;
				s.stop = station;
				if (buses_to_stops.at(station).size() == 1) s.buses_to_stop.push_back("no interchange");
				else {
					for (const auto& item : buses_to_stops.at(station)) {
						if (item != bus) s.buses_to_stop.push_back(item);
					}
				}
				result.stops_with_buses.push_back(s);
			}
		}
		return result;
	}

	AllBusesResponse GetAllBuses() const {
		AllBusesResponse result;
		for (const auto& item : stops_to_buses) {
			string str;
			str = "Bus " + item.first + ":";
			for (const auto& s : item.second) {
				str += " ";
				str += s;
			}
			result.buses_for_output.push_back(str);
		}
		return result;
	}
private:
	map<string, vector<string>> buses_to_stops;
	map<string, vector<string>> stops_to_buses;
};


int main() {
	int query_count;
	Query q;

	cin >> query_count;

	BusManager bm;
	for (int i = 0; i < query_count; ++i) {
		cin >> q;
		switch (q.type) {
		case QueryType::NewBus:
			bm.AddBus(q.bus, q.stops);
			break;
		case QueryType::BusesForStop:
			cout << bm.GetBusesForStop(q.stop) << endl;
			break;
		case QueryType::StopsForBus:
			cout << bm.GetStopsForBus(q.bus) << endl;
			break;
		case QueryType::AllBuses:
			cout << bm.GetAllBuses() << endl;
			break;
		}
	}

	return 0;
}
