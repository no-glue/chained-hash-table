template<class Node, typename Type>class DoubleList {
public:
  DoubleList(Type key, Type value):head(NULL), tail(NULL) {add_right(key, value);}
  DoubleList():head(NULL), tail(NULL) {}
  void add_left(Type key, Type value) {
    // add to the left side of list
    add_left(key, value, head, tail);
  }
  void add_right(Type key, Type value) {
    // add to the right side of list
    add_right(key, value, head, tail);
  }
  void pop_left() {
    // pop left
    pop_left(head, tail);
  }
  void pop_right() {
    // pop right
    pop_right(head, tail);
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
  void pop_left(Node * & head, Node * & tail) {
    // pop left
    if(!head) {
      head = tail = NULL;
      return;
    }
    if(!head->right) {
      delete head;
      head = tail = NULL;
      return;
    }
    head = head->right;
    delete head->left;
    head->left = NULL;
  }
  void pop_right(Node * & head, Node * & tail) {
    // pop right
    if(!tail) {
      head = tail = NULL;
      return;
    }
    if(!tail->left) {
      delete tail;
      head = tail = NULL;
      return;
    }
    tail = tail->left;
    delete tail->right;
    tail->right = NULL;
  }
};