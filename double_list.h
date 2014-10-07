template<class Node, typename Type>class DoubleList {
public:
  DoubleList(Type key, Type value):head(NULL), tail(NULL) {insert_right(key, value);}
  DoubleList():head(NULL), tail(NULL) {}
  ~DoubleList() {make_empty();}
  void insert_left(Type key, Type value) {
    // insert to the left side of list
    insert_left(key, value, head, tail);
  }
  void insert_right(Type key, Type value) {
    // insert to the right side of list
    insert_right(key, value, head, tail);
  }
  void pop_left() {
    // pop left
    pop_left(head, tail);
  }
  void pop_right() {
    // pop right
    pop_right(head, tail);
  }
  void make_empty() {
    // make the list empty
    make_empty(head, tail);
  }
  Node * get_head() {return head;}
  Node * get_tail() {return tail;}
private:
  Node * head;
  Node * tail;
  void insert_left(Type key, Type value, Node * & head, Node * & tail) {
    // insert to the left side of the list
    Node * inserted = new Node(key, value);
    if(!head && !tail) {
      head = tail = inserted;
      return;
    }
    head->left = inserted;
    inserted->right = head;
    head = inserted;
  }
  void insert_right(Type key, Type value, Node * & head, Node * & tail) {
    // insert to the right side of list
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
  void make_empty(Node * & head, Node * & tail) {
    // make the list empty
    while(head) pop_left(head, tail);
  }
};