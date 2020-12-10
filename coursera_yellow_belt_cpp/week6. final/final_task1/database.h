#pragma once

#include"date.h"
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<functional>
#include<algorithm>

class Database
{
public:
	void Add(const Date& date, const string& event);
	void Print(ostream& os) const;
	string Last(Date date) const;
	int RemoveIf(const function<bool(const Date&, const string&)>& _pred);
	vector<pair<Date, string>> FindIf(const function<bool(const Date&, const string&)>& _pred) const;
private:
	map<Date, vector<string>> all_events;
	map<Date, set<string>> all_events_set;
};

