template<class Node, class List, class Hash, typename Type>class ChainedHashTable {
public:
  ChainedHashTable(unsigned int size, Hash * hash):hash(hash) {
    // make table
    table = new List[size];
  }
  ~ChainedHashTable() {
    // delete table
    delete table;
  }
  void add(Type key, Type value) {
    // add key and value to table
    void add(key, value, table, hash);
  }
  List * find(Type key) {
    // find key and values in table
  }
private:
  List * table;
  Hash * hash;
  void add(Type key, Type value, List * & table, Hash * & hash) {
    // add key and value to table
    unsigned int position = hash->position(key);
    if(!table[position]) table[position] = new List(key, value);
    else table[position]->add_right(key, value);
  }
};