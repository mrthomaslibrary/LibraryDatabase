template <typename T> class Node {
private:
  T data;
  public:
  Node(T newData);
  ~Node();
  Node *frontNode;
  Node *sideNode;
  T getData();
};
