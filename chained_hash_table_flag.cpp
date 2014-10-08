#define SIZE 4294967295

#include <iostream>
#include <string>
#include <math.h>
#include <iostream>
#include "double_node_flag.h"
#include "double_list.h"
#include "double_list_walk.h"
#include "hash_djb2_string.h"
#include "chained_hash_table.h"

using namespace std;

int main() {
  DoubleNodeFlag<string> * item;
  DoubleList<DoubleNodeFlag<string>, string> * result = new DoubleList<DoubleNodeFlag<string>, string>();
  DoubleListWalk<DoubleNodeFlag<string>, DoubleList<DoubleNodeFlag<string>, string> > * walk = new DoubleListWalk<DoubleNodeFlag<string>, DoubleList<DoubleNodeFlag<string>, string> >();
  HashDjb2String<string> * hash = new HashDjb2String<string>();
  ChainedHashTable<
  DoubleNodeFlag<string>, 
  DoubleList<DoubleNodeFlag<string>, string>, 
  HashDjb2String<string>,
  DoubleListWalk<DoubleNodeFlag<string>, DoubleList<DoubleNodeFlag<string>, string> >,
  string> * table = new ChainedHashTable<
  DoubleNodeFlag<string>, 
  DoubleList<DoubleNodeFlag<string>, string>, 
  HashDjb2String<string>,
  DoubleListWalk<DoubleNodeFlag<string>, DoubleList<DoubleNodeFlag<string>, string> >,
  string
  >(ceil(SIZE / sizeof(DoubleList<DoubleNodeFlag<string>, string>)), walk, hash);
  cout<<"table size: "<<table->get_size()<<endl;
  table->insert("a", "a");
  table->insert("b", "b");
  table->insert("c", "c");
  table->insert("d", "d");
  table->insert("e", "e");
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
  delete result;
  delete walk;
  delete hash;
  delete table;
  return 0;
}