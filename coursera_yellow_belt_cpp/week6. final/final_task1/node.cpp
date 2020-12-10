#include "node.h"

bool EmptyNode::Evaluate(const Date& date, const string& event) const {
	return true;
}

bool DateComparisonNode::Evaluate(const Date& date, const string& event) const {
	switch (comp_) {
	case Comparison::Equal:
		return (date == this->date_);
	case Comparison::Greater:
		return (date > this->date_);
	case Comparison::GreaterOrEqual:
		return (date >= this->date_);
	case Comparison::Less:
		return (date < this->date_);
	case Comparison::LessOrEqual:
		return (date <= this->date_);
	case Comparison::NotEqual:
		return (date != this->date_);
	default:
		return false;
	}
}

bool EventComparisonNode::Evaluate(const Date& date, const string& event) const {
	switch (comp_) {
	case Comparison::Equal:
		return (event == this->event_);
	case Comparison::Greater:
		return (event > this->event_);
	case Comparison::GreaterOrEqual:
		return (event >= this->event_);
	case Comparison::Less:
		return (event < this->event_);
	case Comparison::LessOrEqual:
		return (event <= this->event_);
	case Comparison::NotEqual:
		return (event != this->event_);
	default:
		return false;
	}
}


bool LogicalOperationNode::Evaluate(const Date& date, const string& event) const {
	switch (op_) {
	case LogicalOperation::Or:
		 return (left_->Evaluate(date, event) || right_->Evaluate(date, event));
	case LogicalOperation::And:
		 return (left_->Evaluate(date, event) && right_->Evaluate(date, event));
	}
	return false;
}