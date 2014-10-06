template<class Node, typename Type>class DoubleList {
public:
  DobuleList():head(NULL), tail(NULL), position(NULL) {}
  void add_left(Type key, Type value) {
    // add to the left side of list
    add_left(key, value, head, tail);
  }
  void add_right(Type key, Type value) {
    // add to the right side of list
    add_right(key, value, head, tail);
  }
  Node * next_from_head() {
    // get next_from_head item
    return next_from_head(position, head);
  }
private:
  Node * head;
  Node * tail;
  Node * position;
  void add_left(Type key, Type value, Node * & head, Node * & tail) {
    // add to the left side of the list
    Node * inserted = new Node(key, value);
    if(!head && !tail) {
      head = tail = inserted;
      return;
    }
    head->left = inserted;
    inserted->right = head;
    head = inserted;
  }
  void add_right(Type key, Type value, Node * & head, Node * & tail) {
    // add to the right side of list
    Node * inserted = new Node(key, value);
    if(!head && !tail) {
      head = tail = inserted;
      return;
    }
    tail->right = inserted;
    inserted->left = tail;
    tail = inserted;
  }
  Node * next_from_head(Node * & position, Node * & head) {
    // get next_from_head item
    if(!position) return position;
    Node * item = position;    
    position = position->right;
    return item;
  }
};