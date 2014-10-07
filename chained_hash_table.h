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
    insert(key, value, table, hash, size);
  }
  void remove(Type key) {
    // remove key from table
    remove(key, table, walk, hash, size);
  }
  void find(Type key, List * & result) {
    // find key and values in table
    find(key, table, walk, hash, size, result);
  }
private:
  unsigned int size;
  List * table;
  Walk * walk;
  Hash * hash;
  void insert(Type key, Type value, List * & table, Hash * & hash, unsigned int size) {
    // insert key and value to table
    // todo keep flag to show if there is collision
    unsigned int position = hash->position(key, size);
    if(!table[position]) table[position] = new List(key, value);
    else table[position]->insert_right(key, value);
  }
  void remove(Type key, Node * & table, Walk * & walk, Node * & hash, unsigned int size) {
    // remove key from table
    unsigned int position = hash->position(key, size);
    if(!table[position]) return;
    walk->set_list(table[position]);
    walk->rewind();
    Node * item;
    List * list = new List();
    while((item = walk->next())) {
      if(item->key != key) list->insert_right(item->key, item->value);
    }
    walk->unset_list();
    table[position]->make_empty();
    delete table[position];
    table[position] = list;
  }
  void find(Type key, Node * & table, Walk * & walk, Hash * & hash, unsigned int size, List * & result) {
    // find key and values in table
    // todo look collision flag
    // if flag is false just set result
    unsigned int position = hash->position(key, size);
    if(!table[position]) return;
    walk->set_list(table[position]);
    walk->rewind();
    Node * item;
    while((item = walk->next())) {
      if(key == item->key) result->insert_right(item->key, item->value);
    }
  }
};