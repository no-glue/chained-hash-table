template<typename Type>class Node {
public:
  Type key;
  Type value;
  Node() {}
  Node(Type key, Type value):key(key), value(value) {}
};