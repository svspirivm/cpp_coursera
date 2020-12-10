#pragma once

#include"date.h"
#include<memory>

class Node {
public:
	Node() { }
	virtual bool Evaluate(const Date& date, const string& event) const = 0;
};

class EmptyNode : public Node {
public:
	EmptyNode() { }
	bool Evaluate(const Date& date, const string& event) const override;
};

enum class LogicalOperation {
	Or,
	And
};

enum class Comparison {
	Less,
	LessOrEqual,
	Greater,
	GreaterOrEqual,
	Equal,
	NotEqual
};

class DateComparisonNode : public Node {
public:
	DateComparisonNode(const Comparison& c, const Date& d) 
		: comp_(c), date_(d) { }
	bool Evaluate(const Date& date, const string& event) const override;
private:
	const Comparison comp_;
	const Date date_;
};

class EventComparisonNode : public Node {
public:
	EventComparisonNode(const Comparison& c, const string& v) 
		: comp_(c), event_(v) { }
	bool Evaluate(const Date& date, const string& event) const override;
private:
	const Comparison comp_;
	const string event_;
};

class LogicalOperationNode : public Node {
public:
	LogicalOperationNode(const LogicalOperation& op, shared_ptr<Node> left, shared_ptr<Node> right)
		: op_(op), left_(left), right_(right) { }
	bool Evaluate(const Date& date, const string& event) const override;
private:
	const LogicalOperation op_;
	const shared_ptr<Node> left_;
	const shared_ptr<Node> right_;
};

