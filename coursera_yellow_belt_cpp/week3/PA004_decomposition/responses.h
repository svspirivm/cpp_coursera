#pragma once

#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct BusesForStopResponse {
	string stop;
	vector<string> buses_to_stop;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse {
	string bus;
	vector<BusesForStopResponse> stops_with_buses;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse {
	vector<string> buses_for_output;
};

ostream& operator << (ostream& os, const AllBusesResponse& r);