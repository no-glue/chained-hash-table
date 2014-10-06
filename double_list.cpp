#include <iostream>
#include <string>
#include "node.h"
#include "double_list.h"
#include "double_list_walk.h"

using namespace std;

int main() {
  DoubleList<Node<string>, string> * dlist = new DoubleList<Node<string>, string>();
  DoubleListWalk<Node<string>, DoubleList<Node<string>, string> > * dlwalk = new DoubleListWalk<Node<string>, DoubleList<Node<string>, string> >(dlist);
  Node<string> * item;
  dlist->add_left("a", "a");
  dlist->add_left("b", "b");
  dlist->add_right("c", "c");
  dlist->add_right("d", "d");
  dlist->add_right("e", "e");
  // should be bacde
  dlwalk->rewind();
  while((item = dlwalk->next())) {
    cout<<item->key;
  }
  cout<<endl;
  delete dlwalk;
  delete dlist;
  return 0;
}