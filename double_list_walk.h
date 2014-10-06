template<class Node, class List>class DoubleListWalk {
public:
  DoubleListWalk():list(NULL), position(NULL) {}
  DoubleListWalk(List * list):list(list), position(NULL) {}
  void rewind() {
    // start from head
    rewind(position, list);
  }
  Node * next() {
    // get next item
    return next(position);
  }
private:
  List * list;
  Node * position;
  void rewind(Node * & position, List * & list) {
    // start from head
    position = list->get_head();
  }
  Node * next(Node * & position) {
    // get next item
    Node * item = position;
    if(position) position = position->right;
    return item;
  }
};