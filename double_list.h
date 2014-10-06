template<class Node, typename Type>class DoubleList {
public:
  DoubleList():head(NULL), tail(NULL) {}
  void add_left(Type key, Type value) {
    // add to the left side of list
    add_left(key, value, head, tail);
  }
  void add_right(Type key, Type value) {
    // add to the right side of list
    add_right(key, value, head, tail);
  }
  Node * get_head() {return head;}
  Node * get_tail() {return tail;}
private:
  Node * head;
  Node * tail;
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
};