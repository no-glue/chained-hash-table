template<typename Type>class DoubleNode {
public:
  Type key;
  // key for a node
  Type value;
  // type for a node
  DoubleNode * left;
  // left node
  DoubleNode * right;
  // right node
  DoubleNode():left(NULL), right(NULL) {}
  DoubleNode(Type key, Type value):key(key), value(value), left(NULL), right(NULL) {}
  DoubleNode(Type key, Type value, DoubleNode * left, DoubleNode * right):key(key), value(value), left(left), right(right) {}
};