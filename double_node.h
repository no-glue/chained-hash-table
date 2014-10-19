#include <string.h>

template<typename Type>class DoubleNode {
public:
  char * key;
  // key for a node
  char * value;
  // type for a node
  DoubleNode * left;
  // left node
  DoubleNode * right;
  // right node
  DoubleNode():left(NULL), right(NULL) {}
  DoubleNode(Type node_key, Type node_value):left(NULL), right(NULL) {
    int key_len = node_key.length(), value_len = node_value.length(), i = 0;
    key = new char[key_len];
    strcpy(key, node_key.c_str());
    value = new char[value_len];
    strcpy(value, node_value.c_str());
  }
  DoubleNode(Type node_key, Type node_value, DoubleNode * left, DoubleNode * right):left(left), right(right) {
    int key_len = node_key.length(), value_len = node_value.length(), i = 0;
    key = new char[key_len];
    strcpy(key, node_key.c_str());
    value = new char[value_len];
    strcpy(value, node_value.c_str());
  }
};