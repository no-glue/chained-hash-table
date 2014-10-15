#define SIZE 4294967295

#include <iostream>
#include <fstream>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include "cstring_wrapper.h"
#include "double_node.h"
#include "double_list.h"
#include "double_list_walk.h"
#include "hash_djb2_string.h"
#include "chained_hash_table.h"
#include "decorator_file_read.h"
#include "generator_file.h"
#include "importer.h"
#include "adapter_metrics_table.h"
#include "metrics_table.h"

using namespace std;

int main() {
  string line;
  getline(cin, line);
  CstringWrapper * str = new CstringWrapper();
  // get str
  DoubleList<DoubleNode<string>, string> * results = new DoubleList<DoubleNode<string>, string>;
  // get results
  DoubleListWalk<
    DoubleNode<string>, 
    DoubleList<DoubleNode<string>, string>
  > * table_walk = new DoubleListWalk<
    DoubleNode<string>, 
    DoubleList<DoubleNode<string>, string>
  >(), 
  * adapter_walk = new DoubleListWalk<
    DoubleNode<string>, 
    DoubleList<DoubleNode<string>, string>
  >(), 
  * table_visited_walk = new DoubleListWalk<
    DoubleNode<string>, 
    DoubleList<DoubleNode<string>, string>
  >(), 
  * running_walk = new DoubleListWalk<
    DoubleNode<string>, 
    DoubleList<DoubleNode<string>, string>
  >();
  // get walks
  HashDjb2String<
    string
  > * hash = new HashDjb2String<
    string
  >(), 
  * hash_table_visited = new HashDjb2String<
    string
  >();
  // get hashes
  ChainedHashTable<
    DoubleNode<string>, 
    DoubleList<DoubleNode<string>, string>, 
    HashDjb2String<string>,
    DoubleListWalk<DoubleNode<string>, DoubleList<DoubleNode<string>, string> >,
    string
  > * table = new ChainedHashTable<
    DoubleNode<string>, 
    DoubleList<DoubleNode<string>, string>, 
    HashDjb2String<string>,
    DoubleListWalk<DoubleNode<string>, DoubleList<DoubleNode<string>, string> >,
    string
  >(ceil(SIZE / sizeof(DoubleNode<string>)), table_walk, hash),
  * table_visited = new ChainedHashTable<
    DoubleNode<string>, 
    DoubleList<DoubleNode<string>, string>, 
    HashDjb2String<string>,
    DoubleListWalk<DoubleNode<string>, DoubleList<DoubleNode<string>, string> >,
    string
  >(ceil(SIZE / sizeof(DoubleNode<string>)), table_visited_walk, hash_table_visited);
  // get tables
  GeneratorFile<
    ifstream, string
  > * files = new GeneratorFile<
    ifstream, string
  >(line);
  // get file generator
  DecoratorFileRead<
    ostream, string
  > * file_read = new DecoratorFileRead<
    ostream, string
  >(cout);
  // get file read messages
  Importer<
    GeneratorFile<ifstream, string>, 
    ChainedHashTable<
      DoubleNode<string>, 
      DoubleList<DoubleNode<string>, string>, 
      HashDjb2String<string>,
      DoubleListWalk<DoubleNode<string>, DoubleList<DoubleNode<string>, string> >,
      string>, 
    DecoratorFileRead<ostream, string>, 
    string, 
    ifstream> * importer = new Importer<
      GeneratorFile<ifstream, string>, 
      ChainedHashTable<
        DoubleNode<string>, 
        DoubleList<DoubleNode<string>, string>, 
        HashDjb2String<string>,
        DoubleListWalk<DoubleNode<string>, DoubleList<DoubleNode<string>, string> >,
        string>, 
      DecoratorFileRead<ostream, string>, 
      string, 
      ifstream>();
  // get file reader
  AdapterMetricsTable<
    string,
    CstringWrapper,
    DoubleNode<string>,
    DoubleList<DoubleNode<string>, string>,
    DoubleListWalk<DoubleNode<string>, DoubleList<DoubleNode<string>, string> >,
    ChainedHashTable<
      DoubleNode<string>, 
      DoubleList<DoubleNode<string>, string>, 
      HashDjb2String<string>,
      DoubleListWalk<DoubleNode<string>, DoubleList<DoubleNode<string>, string> >,
      string>
  > * adapter = new AdapterMetricsTable<
    string,
    CstringWrapper,
    DoubleNode<string>,
    DoubleList<DoubleNode<string>, string>,
    DoubleListWalk<DoubleNode<string>, DoubleList<DoubleNode<string>, string> >,
    ChainedHashTable<
      DoubleNode<string>, 
      DoubleList<DoubleNode<string>, string>, 
      HashDjb2String<string>,
      DoubleListWalk<DoubleNode<string>, DoubleList<DoubleNode<string>, string> >,
      string>
  >(str, table, adapter_walk, table_visited, running_walk);
  // get table adapter
  // todo put walk in front
  MetricsTable<
    // start template list
    DoubleList<DoubleNode<string>, string>,
    // list to use for q
    AdapterMetricsTable<
      string,
      CstringWrapper,
      DoubleNode<string>,
      DoubleList<DoubleNode<string>, string>,
      DoubleListWalk<DoubleNode<string>, DoubleList<DoubleNode<string>, string> >,
      ChainedHashTable<
        DoubleNode<string>, 
        DoubleList<DoubleNode<string>, string>, 
        HashDjb2String<string>,
        DoubleListWalk<DoubleNode<string>, DoubleList<DoubleNode<string>, string> >,
        string>
    >
    // adapter for index (table here)
  > * metrics = new MetricsTable<
    // start template list
    DoubleList<DoubleNode<string>, string>,
    // list to use for q
    AdapterMetricsTable<
      string,
      CstringWrapper,
      DoubleNode<string>,
      DoubleList<DoubleNode<string>, string>,
      DoubleListWalk<DoubleNode<string>, DoubleList<DoubleNode<string>, string> >,
      ChainedHashTable<
        DoubleNode<string>, 
        DoubleList<DoubleNode<string>, string>, 
        HashDjb2String<string>,
        DoubleListWalk<DoubleNode<string>, DoubleList<DoubleNode<string>, string> >,
        string>
    >
    // adapter for index (table here)
  >(adapter);
  // get metrics
  // todo make single metrics
  time_t now = time(NULL), then;
  importer->import(files, table, file_read);
  then = time(NULL);
  cout<<"table size "<<table->get_size()<<endl;
  cout<<"indexing "<<difftime(then, now)<<" seconds"<<endl;
  cout<<"nodes "<<metrics->nodes()<<endl;
  cout<<"edges "<<metrics->edges()<<endl;
  cout<<"density "<<metrics->density()<<endl;
  cout<<"average degree "<<metrics->average_degree()<<endl;
  now = time(NULL);
  metrics->breadth_first_search(results);
  cout<<"network diameter "<<results->get_head()->value<<endl;
  results->pop_left();
  cout<<"average path length "<<results->get_head()->value<<endl;
  results->pop_left();
  then = time(NULL);
  cout<<"bfs "<<difftime(then, now)<<" seconds"<<endl;
  delete str;
  delete results;
  delete table_walk;
  delete table_visited_walk;
  delete running_walk;
  delete adapter_walk;
  delete hash;
  delete hash_table_visited;
  delete table;
  delete table_visited;
  delete files;
  delete file_read;
  delete importer;
  delete adapter;
  delete metrics;
  return 0;
}