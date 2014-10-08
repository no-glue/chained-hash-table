#define SIZE 4294967295

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include "double_node_flag.h"
#include "double_list.h"
#include "double_list_walk.h"
#include "hash_djb2_string.h"
#include "chained_hash_table.h"
#include "decorator_file_read.h"
#include "generator_file.h"
#include "importer.h"

using namespace std;

int main() {
  string line;
  getline(cin, line);
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
  GeneratorFile<ifstream, string> * files = new GeneratorFile<ifstream, string>(line);
  DecoratorFileRead<ostream, string> * file_read = new DecoratorFileRead<ostream, string>(cout);
  Importer<
    GeneratorFile<ifstream, string>, 
    ChainedHashTable<
      DoubleNodeFlag<string>, 
      DoubleList<DoubleNodeFlag<string>, string>, 
      HashDjb2String<string>,
      DoubleListWalk<DoubleNodeFlag<string>, DoubleList<DoubleNodeFlag<string>, string> >,
      string>, 
    DecoratorFileRead<ostream, string>, 
    string, 
    ifstream> * importer = new Importer<
      GeneratorFile<ifstream, string>, 
      ChainedHashTable<
        DoubleNodeFlag<string>, 
        DoubleList<DoubleNodeFlag<string>, string>, 
        HashDjb2String<string>,
        DoubleListWalk<DoubleNodeFlag<string>, DoubleList<DoubleNodeFlag<string>, string> >,
        string>, 
      DecoratorFileRead<ostream, string>, 
      string, 
      ifstream>();
  importer->import(files, table, file_read);
  delete walk;
  delete hash;
  delete table;
  delete files;
  delete file_read;
  delete importer;
  return 0;
}