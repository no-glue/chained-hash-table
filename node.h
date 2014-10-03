template<typename Type>class Node {
public:
  Type key;
  // key for a node
  Type value;
  // type for a node
  Node * prev;
  // prev node
  Node * next;
  // next node
  Node():prev(NULL), next(NULL) {}
  Node(Type key, Type value):key(key), value(value), prev(NULL), next(NULL) {}
  Node(Type key, Type value, Node * prev, Node * next):key(key), value(value), prev(prev), next(next) {}
};