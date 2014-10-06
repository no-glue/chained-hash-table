template<typename Type>class Node {
public:
  Type key;
  // key for a node
  Type value;
  // type for a node
  Node * left;
  // left node
  Node * right;
  // right node
  Node():left(NULL), right(NULL) {}
  Node(Type key, Type value):key(key), value(value), left(NULL), right(NULL) {}
  Node(Type key, Type value, Node * left, Node * right):key(key), value(value), left(left), right(right) {}
};