#include"responses.h"

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