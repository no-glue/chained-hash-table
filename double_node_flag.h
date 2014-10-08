template<typename Type>class DoubleNodeFlag {
public:
  Type key;
  // key for a node
  Type value;
  // type for a node
  DoubleNodeFlag * left;
  // left node
  DoubleNodeFlag * right;
  // right node
  bool collision;
  // did collision happen
  bool check_collision;
  // check collision
  DoubleNodeFlag():left(NULL), right(NULL), collision(false), check_collision(true) {}
  DoubleNodeFlag(Type key, Type value):key(key), value(value), left(NULL), right(NULL), collision(false), check_collision(true) {}
  DoubleNodeFlag(Type key, Type value, bool collision):key(key), value(value), left(NULL), right(NULL), collision(collision), check_collision(true) {}
  DoubleNodeFlag(Type key, Type value, DoubleNodeFlag * left, DoubleNodeFlag * right, bool collision):key(key), value(value), left(left), right(right), collision(collision), check_collision(true) {}
};