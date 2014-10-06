#include <iostream>
#include "node.h"
#include "double_list.h"
#include "double_list_walk.h"

using namespace std;

int main() {
  DoubleList<Node<string>, string> * dlist = new DoubleList<Node<string>, string>();
  DoubleListWalk<Node<string>, DoubleList<Node<string>, string> > * dlwalk = new DoubleListWalk<Node<string>, DoubleList<Node<string>, string> >();
  delete dlwalk;
  delete dlist;
  return 0;
}