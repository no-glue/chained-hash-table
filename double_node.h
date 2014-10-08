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
  bool check_collision;
  // check collision
  DoubleNode():left(NULL), right(NULL), check_collision(false) {}
  DoubleNode(Type key, Type value):key(key), value(value), left(NULL), right(NULL), check_collision(false) {}
  DoubleNode(Type key, Type value, DoubleNode * left, DoubleNode * right):key(key), value(value), left(left), right(right), check_collision(false) {}
};