template<class Node, class List, class Hash, typename Type>class ChainedHashTable {
public:
  ChainedHashTable(unsigned int size, Hash * hash):size(size), hash(hash) {
    // make table
    table = new List[size];
  }
  ~ChainedHashTable() {
    // delete table
    delete table;
  }
  void insert(Type key, Type value) {
    // insert key and value to table
    void insert(key, value, table, hash);
  }
  void remove(Type key) {
    // remove key from table
    remove(key, table, hash, size);
  }
  List * find(Type key) {
    // find key and values in table
  }
private:
  unsigned int size;
  List * table;
  Hash * hash;
  void insert(Type key, Type value, List * & table, Hash * & hash) {
    // insert key and value to table
    unsigned int position = hash->position(key, size);
    if(!table[position]) table[position] = new List(key, value);
    else table[position]->insert_right(key, value);
  }
  void remove(Type key, Node * & table, Node * & hash, unsigned int size) {
    // remove key from table
    unsigned int position = hash->position(key, size);
    if(!table[position]) return;
  }
};