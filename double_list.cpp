#include <iostream>
#include <string>
#include "double_node.h"
#include "double_list.h"
#include "double_list_walk.h"

using namespace std;

int main() {
  DoubleList<DoubleNode<string>, string> * dlist = new DoubleList<DoubleNode<string>, string>();
  DoubleListWalk<DoubleNode<string>, DoubleList<DoubleNode<string>, string> > * dlwalk = new DoubleListWalk<DoubleNode<string>, DoubleList<DoubleNode<string>, string> >(dlist);
  DoubleNode<string> * item;
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
  dlist->insert_left("a", "a");
  dlist->insert_left("b", "b");
  dlist->insert_right("c", "c");
  dlist->insert_right("d", "d");
  dlist->insert_right("e", "e");
  delete dlwalk;
  dlist->make_empty();
  delete dlist;
  return 0;
}