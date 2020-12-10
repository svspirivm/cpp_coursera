#include <iostream>

using namespace std;

class Animal {
public:
	Animal(const string& n = "animal") : Name(n) { }
	const string Name;
};


class Dog : public Animal {
public:
	Dog(const string& s) : Animal(s) {

	}

	void Bark() {
		cout << Name << " barks: woof!" << endl;
	}
};

int main() {
	Dog d("doggie");
	return 0;
}