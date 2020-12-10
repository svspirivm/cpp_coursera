#include<iostream>
#include<vector>
#include<memory>
#include<string>
#include<sstream>
#include<iomanip>
#include<cmath>

using namespace std;

class Figure {
public:
	Figure() { }
	virtual string Name() const = 0;
	virtual double Perimeter() const = 0;
	virtual double Area() const = 0;
private:
};


class Rect : public Figure {
public:
	Rect(const double& width, const double& height) {
		width_ = width;
		height_ = height;
	}
	virtual string Name() const override {
		return "RECT";
	}
	virtual double Perimeter() const override {
		return 2 * (width_ + height_);
	}
	virtual double Area() const override {
		return width_ * height_;
	}
private:
	double width_;
	double height_;
};


class Triangle : public Figure {
public:
	Triangle(const double& a, const double& b, const double& c) { 
		a_ = a;
		b_ = b;
		c_ = c;
	}
	virtual string Name() const override {
		return "TRIANGLE";
	}
	virtual double Perimeter() const override {
		return a_ + b_ + c_;
	}
	virtual double Area() const override {
		double p = this->Perimeter() / 2;
		return pow(p * (p - a_) * (p - b_) * (p - c_), 0.5);
	}
private:
	double a_;
	double b_;
	double c_;
};


class Circle : public Figure {
public:
	Circle(const double& radius) {
		radius_ = radius;
	}
	virtual string Name() const override {
		return "CIRCLE";
	}
	virtual double Perimeter() const override {
		return 2 * 3.14 * radius_;
	}
	virtual double Area() const override {
		return 3.14 * radius_ * radius_;
	}
private:
	double radius_;
};

shared_ptr<Figure> CreateFigure(istringstream& input) {
	string type;
	input >> type;
	if (type == "RECT") {
		double width = 0, height = 0;
		input >> width >> height;
		return make_shared<Rect>(width, height);
	}
	else if (type == "TRIANGLE") {
		double a = 0, b = 0, c = 0;
		input >> a >> b >> c;
		return make_shared<Triangle>(a, b, c);
	}
	else if (type == "CIRCLE") {
		double radius;
		input >> radius;
		return make_shared<Circle>(radius);
	}
}

int main() {
	vector<shared_ptr<Figure>> figures;
	for (string line; getline(cin, line); ) {
		istringstream is(line);

		string command;
		is >> command;
		if (command == "ADD") {
			is >> ws;
			figures.push_back(CreateFigure(is));
		}
		else if (command == "PRINT") {
			for (const auto& current_figure : figures) {
				cout << fixed << setprecision(3)
					<< current_figure->Name() << " "
					<< current_figure->Perimeter() << " "
					<< current_figure->Area() << endl;
			}
		}
	}
	return 0;
}