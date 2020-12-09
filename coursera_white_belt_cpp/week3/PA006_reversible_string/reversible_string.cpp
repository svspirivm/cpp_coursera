#include<iostream>
#include<string>

using namespace std;

class ReversibleString {
public:
	ReversibleString() {}
	ReversibleString(const string& new_string) {
		str = new_string;
	}

	void Reverse() {
		string result;
		for (int i = this->str.size() - 1; i >= 0; --i) {
			result += this->str[i];
		}
		this->str = result;
	}

	string ToString() const {
		string result;
		result = this->str;
		return result;
	}
private:
	string str;
};

//int main() {
//	ReversibleString s("live");
//	s.Reverse();
//	cout << s.ToString() << endl;
//
//	s.Reverse();
//	const ReversibleString& s_ref = s;
//	string tmp = s_ref.ToString();
//	cout << tmp << endl;
//
//	ReversibleString empty;
//	cout << '"' << empty.ToString() << '"' << endl;
//
//	return 0;
//}