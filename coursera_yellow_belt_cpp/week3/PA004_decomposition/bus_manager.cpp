#include"bus_manager.h"

void BusManager::AddBus(const string& bus, const vector<string>& stops) {
	stops_to_buses[bus] = stops;
	for (const auto& s : stops) {
		if (buses_to_stops.count(s) > 0) buses_to_stops.at(s).push_back(bus);
		else buses_to_stops[s].push_back(bus);
	}
}

BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const {
	BusesForStopResponse result;
	if (buses_to_stops.count(stop) > 0) {
		result.stop = stop;
		result.buses_to_stop = buses_to_stops.at(stop);
	}
	return result;
}

StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const {
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

AllBusesResponse BusManager::GetAllBuses() const {
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