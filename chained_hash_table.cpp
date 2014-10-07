#define SIZE 4294967295

#include <iostream>
#include <string>
#include "double_node.h"
#include "double_list.h"
#include "double_list_walk.h"
#include "hash_simple_string.h"
#include "chained_hash_table.h"

using namespace std;

int main() {
  DoubleListWalk<DoubleNode<string>, DoubleList<DoubleNode<string>, string> > * walk = new DoubleListWalk<DoubleNode<string>, DoubleList<DoubleNode<string>, string> >();
  HashSimpleString<string> * hash = new HashSimpleString<string>();
  ChainedHashTable<
  DoubleNode<string>, 
  DoubleList<DoubleNode<string>, string>, 
  HashSimpleString<string>,
  DoubleListWalk<DoubleNode<string>, DoubleList<DoubleNode<string>, string> >,
  string> * table = new ChainedHashTable<
  DoubleNode<string>, 
  DoubleList<DoubleNode<string>, string>, 
  HashSimpleString<string>,
  DoubleListWalk<DoubleNode<string>, DoubleList<DoubleNode<string>, string> >,
  string
  >(SIZE, walk, hash);
  delete table;
  delete hash;
  delete walk;
  return 0;
}