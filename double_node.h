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
    value = new char[value_len];
    if(key_len == value_len) {
      // key len same as value len
      for(; i < key_len; i++) {
        key[i] = node_key.at(i);
        value[i] = node_value.at(i);
      }
      key[key_len] = value[value_len] = '\0';
    } else if(key_len < value_len) {
      // key len less than value len
      for(; i < key_len; i++) {
        key[i] = node_key.at(i);
        value[i] = node_value.at(i);
      }
      key[key_len] = '\0';
      for(i = key_len; i < value_len; i++) value[i] = node_value.at(i);
      value[value_len] = '\0';
    } else {
      // key len longer than value len
      for(; i < value_len; i++) {
        key[i] = node_key.at(i);
        value[i] = node_value.at(i);
      }
      value[value_len] = '\0';
      for(i = value_len; i < key_len; i++) key[i] = node_key.at(i);
      key[key_len] = '\0';
    }
  }
  DoubleNode(Type node_key, Type node_value, DoubleNode * left, DoubleNode * right):left(left), right(right) {
    int key_len = node_key.length(), value_len = node_value.length(), i = 0;
    key = new char[key_len];
    value = new char[value_len];
    if(key_len == value_len) {
      for(; i < key_len; i++) {
        key[i] = node_key.at(i);
        value[i] = node_value.at(i);
      }
      key[key_len] = value[value_len] = '\0';
    } else if(key_len < value_len) {
      for(; i < key_len; i++) {
        key[i] = node_key.at(i);
        value[i] = node_value.at(i);
      }
      key[key_len] = '\0';
      for(i = key_len; i < value_len; i++) value[i] = node_value.at(i);
      value[value_len] = '\0';
    } else {
      for(; i < value_len; i++) {
        key[i] = node_key.at(i);
        value[i] = node_value.at(i);
      }
      value[value_len] = '\0';
      for(i = value_len; i < key_len; i++) key[i] = node_key.at(i);
      key[key_len] = '\0';
    }
  }
};