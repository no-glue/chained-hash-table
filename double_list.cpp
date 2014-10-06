#include "node.h"
#include "double_list.h"
#include "double_list_walk.h"
#include <iostream>

using namespace std;

int main() {
  DoubleList<Node<string>, string> * dlist = new DoubleList<Node<string>, string>();
  DoubleListWalk<Node<string>, List<Node<string>, string> > * dlwalk = new DoubleListWalk<Node<string>, List<Node<string>, string> >();
  delete dlwalk;
  delete dlist;
  return 0;
}