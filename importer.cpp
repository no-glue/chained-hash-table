#define SIZE 4294967295

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <time.h>
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
  DoubleList<
    DoubleNode<string>, string
  > * result = new DoubleList<
    DoubleNode<string>, string
  >();
  DoubleListWalk<
    DoubleNode<string>, 
    DoubleList<DoubleNode<string>, string>
  > * walk = new DoubleListWalk<
    DoubleNode<string>, 
    DoubleList<DoubleNode<string>, string>
  >();
  HashDjb2String<
    string
  > * hash = new HashDjb2String<
    string
  >();
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
  >(ceil(SIZE / sizeof(DoubleNode<string>)), walk, hash);
  GeneratorFile<
    ifstream, string
  > * files = new GeneratorFile<
    ifstream, string
  >(line);
  DecoratorFileRead<
    ostream, string
  > * file_read = new DecoratorFileRead<
    ostream, string
  >(cout);
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
  AdapterMetricsTable<
    string,
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
    DoubleList<DoubleNode<string>, string>,
    DoubleListWalk<DoubleNode<string>, DoubleList<DoubleNode<string>, string> >,
    ChainedHashTable<
      DoubleNode<string>, 
      DoubleList<DoubleNode<string>, string>, 
      HashDjb2String<string>,
      DoubleListWalk<DoubleNode<string>, DoubleList<DoubleNode<string>, string> >,
      string>
  >(table, result, walk);
  MetricsTable<
    AdapterMetricsTable<
      string,
      DoubleList<DoubleNode<string>, string>,
      DoubleListWalk<DoubleNode<string>, DoubleList<DoubleNode<string>, string> >,
      ChainedHashTable<
        DoubleNode<string>, 
        DoubleList<DoubleNode<string>, string>, 
        HashDjb2String<string>,
        DoubleListWalk<DoubleNode<string>, DoubleList<DoubleNode<string>, string> >,
        string>
    >
  > * metrics = new MetricsTable<
    AdapterMetricsTable<
      string,
      DoubleList<DoubleNode<string>, string>,
      DoubleListWalk<DoubleNode<string>, DoubleList<DoubleNode<string>, string> >,
      ChainedHashTable<
        DoubleNode<string>, 
        DoubleList<DoubleNode<string>, string>, 
        HashDjb2String<string>,
        DoubleListWalk<DoubleNode<string>, DoubleList<DoubleNode<string>, string> >,
        string>
    >
  >(adapter);
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
  delete result;
  delete walk;
  delete hash;
  delete table;
  delete files;
  delete file_read;
  delete importer;
  delete adapter;
  delete metrics;
  return 0;
}