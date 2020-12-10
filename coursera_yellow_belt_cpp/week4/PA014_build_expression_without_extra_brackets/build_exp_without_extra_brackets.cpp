#include<iostream>
#include<deque>
#include<string>

using namespace std;

class Expression {
public:
	void Read() {
		cin >> starting_number;
		cin >> number_of_operations;
		exp.push_back(to_string(starting_number));
		while (number_of_operations > 0) {
			number_of_operations--;
			char op;
			int n;
			cin >> op >> n;
			
			previous_operation = current_operation;
			current_operation = op;

			BuildExpression(op, n);
		}
		Print();
	}
private:
	int starting_number;
	int number_of_operations;

	char current_operation;
	char previous_operation;
	deque<string> exp;

	void BuildExpression(const char& operation, const int& number) {
		if (BracketsNeeded()) {
			exp.push_front("(");
			exp.push_back(")");
		}
		exp.push_back(" ");
		string op;
		op += operation;
		exp.push_back(op);
		exp.push_back(" ");
		exp.push_back(to_string(number));
	}

	void Print() {
		for (const auto& i : exp) cout << i;
	}

	bool BracketsNeeded() {
		if ((current_operation == '*' || current_operation == '/') && (previous_operation == '+' || previous_operation == '-')) return true;
		return false;
	}

};


int main() {
	Expression e;
	e.Read();

	return 0;
}