#include "Process.hpp"

Process::Process() { headNode = nullptr; }

Process::~Process() {}

void Process::addNode(CallNumber cn) {
  Node *newNode = new Node(cn);
  if (headNode) {
    headNode = newNode;
  }
  else {
    Node *currentNode = headNode;
    while (currentNode->getData().getClass() > cn.getClass()) {
      currentNode = currentNode->frontNode;
    }
    if (currentNode->getData().getSubject() < cn.getSubject()) {

    }
  }
}
