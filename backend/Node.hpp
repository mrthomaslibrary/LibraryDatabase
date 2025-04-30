#include "CallNumber.hpp"

class Node {
private:
  CallNumber data;
  public:
  Node(CallNumber newData);
  ~Node();
  Node *frontNode;
  Node *sideNode;
  CallNumber getData();
};
