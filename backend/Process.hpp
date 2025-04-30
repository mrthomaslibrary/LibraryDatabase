#include "Node.hpp"
//#include "CallNumber.hpp"

class Process {
private:
  Node *headNode;
public:
  Process();
  ~Process();
  void addNode(CallNumber cn);
  void deleteNode(CallNumber cn);
};
