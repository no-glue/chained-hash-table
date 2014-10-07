template<class Node, class List, class Hash, class Walk, typename Type>class ChainedHashTable {
public:
  ChainedHashTable(unsigned int size, Walk * walk, Hash * hash):size(size), walk(walk), hash(hash) {
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
    remove(key, table, walk, hash, size);
  }
  List * find(Type key) {
    // find key and values in table
  }
private:
  unsigned int size;
  List * table;
  Walk * walk;
  Hash * hash;
  void insert(Type key, Type value, List * & table, Hash * & hash) {
    // insert key and value to table
    unsigned int position = hash->position(key, size);
    if(!table[position]) table[position] = new List(key, value);
    else table[position]->insert_right(key, value);
  }
  void remove(Type key, Node * & table, Walk * & walk, Node * & hash, unsigned int size) {
    // remove key from table
    unsigned int position = hash->position(key, size);
    if(!table[position]) return;
  }
};