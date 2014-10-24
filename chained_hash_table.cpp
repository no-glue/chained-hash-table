#define SIZE 4294967295

#include <iostream>
#include <string>
#include <math.h>
#include <iostream>
#include "double_node.h"
#include "double_list.h"
#include "double_list_walk.h"
#include "hash_simple_string.h"
#include "chained_hash_table.h"

using namespace std;

int main() {
  DoubleNode<string> * item;
  DoubleList<DoubleNode<string>, string> * result = new DoubleList<DoubleNode<string>, string>();
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
  >(ceil(SIZE / sizeof(DoubleList<DoubleNode<string>, string>)), walk, hash);
  cout<<"table size: "<<table->get_size()<<endl;
  table->insert("a", "a");
  table->insert("b", "b");
  table->insert("c", "c");
  table->insert("d", "d");
  table->insert("e", "e");
  cout<<"longest chain: "<<table->get_longest_chain()<<endl;
  table->find("a", result);
  table->find("b", result);
  table->find("c", result);
  table->find("d", result);
  table->find("e", result);
  walk->set_list(result);
  walk->rewind();
  while((item = walk->next())) {
    cout<<item->key;
  }
  // should be abcde
  cout<<endl;
  walk->unset_list();
  result->make_empty();
  table->remove("a");
  table->remove("b");
  table->remove("c");
  table->remove("d");
  table->remove("e");
  table->find("a", result);
  table->find("b", result);
  table->find("c", result);
  table->find("d", result);
  table->find("e", result);
  if(!result->get_head()) cout<<"empty"<<endl;
  result->make_empty();
  table->insert("a", "a");
  table->insert("b", "b");
  table->insert("c", "c");
  table->insert("d", "d");
  table->insert("e", "e");
  table->remove("e");
  table->find("a", result);
  table->find("e", result);
  walk->set_list(result);
  walk->rewind();
  while((item = walk->next())) {
    cout<<item->key;
  }
  // should be a
  cout<<endl;
  result->make_empty();
  table->remove("a");
  table->remove("b");
  table->remove("c");
  table->remove("d");
  table->remove("e");
  table->insert_unique("a", "a");
  table->insert_unique("a", "a");
  table->insert_unique("a", "a");
  table->insert_unique("a", "a");
  table->insert_unique("a", "a");
  table->find("a", result);
  walk->set_list(result);
  walk->rewind();
  while((item = walk->next())) {
    cout<<item->key;
  }
  // should be a
  cout<<endl;
  delete result;
  delete walk;
  delete hash;
  delete table;
  return 0;
}