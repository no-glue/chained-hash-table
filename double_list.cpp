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
  dlist->insert_left("a", "a");
  dlist->insert_left("b", "b");
  dlist->insert_right("c", "c");
  dlist->insert_right("d", "d");
  dlist->insert_right("e", "e");
  dlwalk->rewind();
  while((item = dlwalk->next())) {
    cout<<item->key;
  }
  // should be bacde
  cout<<endl;
  while((item = dlist->get_head())) {
    cout<<item->key;
    dlist->pop_left();
  }
  // should be bacde
  cout<<endl;
  dlist->insert_left("a", "a");
  dlist->insert_left("b", "b");
  dlist->insert_right("c", "c");
  dlist->insert_right("d", "d");
  dlist->insert_right("e", "e");
  while((item = dlist->get_tail())) {
    cout<<item->key;
    dlist->pop_right();
  }
  // should be edcab
  cout<<endl;
  delete dlwalk;
  delete dlist;
  return 0;
}