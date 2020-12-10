#pragma once

#include "node.h"

#include <memory>
#include <iostream>

using namespace std;

Date ParseDate(istringstream& stream);

shared_ptr<Node> ParseCondition(istream& is);

void TestParseCondition();
