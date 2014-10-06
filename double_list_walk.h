template<class Node, class List>class DoubleListWalk {
public:
  DoubleListWalk():list(NULL) {}
  DoubleListWalk(List * list):list(list) {}
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