#include "database.h"

void Database::Add(const Date& date, const string& event) {
	if (all_events.count(date) == 0 || all_events_set[date].find(event) == all_events_set[date].end()) {
		all_events[date].push_back(event);
		all_events_set[date].insert(event);
	} //which means if there's no such date or there's no such event on the given date we add it, otherwise we ignore that command
}

void Database::Print(ostream& os) const {
	for (const auto& ev : all_events) {
		for (const auto& item : ev.second) {
			os << ev.first << " " << item << "\n";
		}
	}
}

string Database::Last(Date date) const {
	stringstream ssresult;
	string result;
	auto it = all_events.upper_bound(date);
	if (it != all_events.begin() && !all_events.empty()) {
		it = prev(it);
		ssresult << (*it).first;
		result = ssresult.str();
		result += " ";
		result += (*it).second[(*it).second.size() - 1];
	}
	else throw invalid_argument("No entries");
	return result;
}

int Database::RemoveIf(const function<bool(const Date&, const string&)>& _pred) {
	int counter = 0;
	if (!all_events.empty()) {               
		auto it = all_events.begin();        //erase from vector
		while (it != all_events.end()) {     
			const auto& date = it->first;     
			auto border = stable_partition(it->second.begin(), it->second.end(), [_pred, date](const string& ev) {
				return !(_pred(date, ev));  
				});
			int sz = it->second.size();

			for (auto it_for_set = border; it_for_set != it->second.end(); it_for_set++) {  //removing from set
				all_events_set[date].erase(*it_for_set);                        //
			}                                                                   //

			it->second.erase(border, it->second.end());
			sz -= it->second.size();
			counter += sz;
			++it;
		}
	}
	for (auto it = all_events.begin(); it != all_events.end(); ) {
		if (it->second.empty()) all_events.erase(it++);
		else it++;
	}
	return counter;
}

vector<pair<Date, string>> Database::FindIf(const function<bool(const Date&, const string&)>& _pred) const {
	map<Date, vector<string>> result1;
	vector<pair<Date, string>> result;
	if (!all_events.empty()) {
		auto it = all_events.begin();
		while (it != all_events.end()) {
			vector<string> tmp;
			const auto& date = it->first;
			copy_if(it->second.begin(), it->second.end(), back_inserter(tmp), [_pred, date](const string& ev) {
				return _pred(date, ev);
				});
			result1[date] = tmp;
			++it;
		}
		if (!result1.empty()) {
			for (const auto& item : result1) {
				for (const auto& ev : item.second) result.push_back(make_pair(item.first, ev));
			}
		}
	}
	return result;
}