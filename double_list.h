template<class Node, typename Type>class DoubleList {
public:
  DoubleList(Type key, Type value):head(NULL), tail(NULL), size(0) {insert_right(key, value);}
  DoubleList():head(NULL), tail(NULL), size(0) {}
  void insert_left(Type key, Type value) {
    // insert to the left side of list
    insert_left(key, value, size, head, tail);
  }
  void insert_right(Type key, Type value) {
    // insert to the right side of list
    insert_right(key, value, size, head, tail);
  }
  void pop_left() {
    // pop left
    pop_left(size, head, tail);
  }
  void pop_right() {
    // pop right
    pop_right(size, head, tail);
  }
  void make_empty() {
    // make the list empty
    make_empty(size, head, tail);
  }
  Node * get_head() {return head;}
  Node * get_tail() {return tail;}
  unsigned int get_size() {return size;}
private:
  Node * head;
  Node * tail;
  unsigned int size;
  void insert_left(Type key, Type value, unsigned int & size, Node * & head, Node * & tail) {
    // insert to the left side of the list
    size++;
    Node * inserted = new Node(key, value);
    if(!head && !tail) {
      head = tail = inserted;
      return;
    }
    head->left = inserted;
    inserted->right = head;
    head = inserted;
  }
  void insert_right(Type key, Type value, unsigned int & size, Node * & head, Node * & tail) {
    // insert to the right side of list
    size++;
    Node * inserted = new Node(key, value);
    if(!head && !tail) {
      head = tail = inserted;
      return;
    }
    tail->right = inserted;
    inserted->left = tail;
    tail = inserted;
  }
  void pop_left(unsigned int & size, Node * & head, Node * & tail) {
    // pop left
    if(!head) {
      size = 0;
      head = tail = NULL;
      return;
    }
    if(!head->right) {
      size = 0;
      delete head;
      head = tail = NULL;
      return;
    }
    size--;
    head = head->right;
    delete head->left;
    head->left = NULL;
  }
  void pop_right(unsigned int & size, Node * & head, Node * & tail) {
    // pop right
    if(!tail) {
      size = 0;
      head = tail = NULL;
      return;
    }
    if(!tail->left) {
      size = 0;
      delete tail;
      head = tail = NULL;
      return;
    }
    size--;
    tail = tail->left;
    delete tail->right;
    tail->right = NULL;
  }
  void make_empty(unsigned int & size, Node * & head, Node * & tail) {
    // make the list empty
    while(head) pop_left(size, head, tail);
  }
};