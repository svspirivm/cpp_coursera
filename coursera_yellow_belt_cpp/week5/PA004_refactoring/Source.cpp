#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
public:
	Person(const string& t = "human", const string& n = "") : type_(t), name_(n) { };

	virtual void Walk(const string& destination) const {
		Who();
		cout << " walks to: " << destination << endl;
	}

	const string type_;
	const string name_;
protected:
	void Who() const {
		cout << type_ << ": " << name_;
	}
};

class Student : public Person {
public:
	Student(const string& name, const string& favouriteSong) : Person("Student", name), FavouriteSong(favouriteSong) { }

	void Learn() {
		Who();
		cout << " learns" << endl;
	}

	void Walk(const string& destination) const override {
		Who();
		cout << " walks to: " << destination << endl;
		SingSong();
	}

	void SingSong() const {
		Who();
		cout << " sings a song: " << FavouriteSong << endl;
	}

private:
	const string FavouriteSong;
};


class Teacher : public Person {
public:
	Teacher(const string& name, const string& subject) : Person("Teacher", name), Subject(subject) { }

	void Teach() const {
		Who();
		cout << " teaches: " << Subject << endl;
	}

private:
	const string Subject;
};


class Policeman : public Person {
public:
	Policeman(const string& name) : Person("Policeman", name) { }

	void Check(const Person& p) const {
		Who();
		cout << " checks " << p.type_ << ". " << p.type_ << "'s name is: " << p.name_ << endl;
	}
};


void VisitPlaces(Person& person, const vector<string>& places) {
	for (auto p : places) {
		person.Walk(p);
	}
}


int main() {
	Teacher t("Jim", "Math");
	Student s("Ann", "We will rock you");
	Policeman p("Bob");

	VisitPlaces(t, { "Moscow", "London" });
	p.Check(s);
	VisitPlaces(s, { "Moscow", "London" });
	return 0;
}






