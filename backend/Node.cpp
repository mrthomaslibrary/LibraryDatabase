#include "Node.hpp"

Node::Node(CallNumber newData) { data = newData; }

Node::~Node() {}

CallNumber Node::getData() { return data; }
