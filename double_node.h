#define KEY_SIZE 16

template<typename Type>class DoubleNode {
public:
  char key[KEY_SIZE];
  // key for a node
  char value[KEY_SIZE];
  // type for a node
  DoubleNode * left;
  // left node
  DoubleNode * right;
  // right node
  DoubleNode():left(NULL), right(NULL) {}
  DoubleNode(Type node_key, Type node_value):left(NULL), right(NULL) {
    int key_len = node_key.length(), value_len = node_value.length(), i = 0;
    for(; i < key_len; i++) key[i] = node_key.at(i);
    key[key_len] = '\0';
    for(i = 0; i < value_len; i++) value[i] = node_value.at(i);
    value[value_len] = '\0';
  }
  DoubleNode(Type node_key, Type node_value, DoubleNode * left, DoubleNode * right):left(left), right(right) {
    int key_len = node_key.length(), value_len = node_value.length(), i = 0;
    for(; i < key_len; i++) key[i] = node_key.at(i);
    key[key_len] = '\0';
    for(i = 0; i < value_len; i++) value[i] = node_value.at(i);
    value[value_len] = '\0';
  }
};