template<class Node, class List, class Hash, class Walk, typename Type>class ChainedHashTable {
public:
  ChainedHashTable(unsigned int size, Walk * walk, Hash * hash):size(size), walk(walk), hash(hash), inserts(0) {
    // make table
    table = new List*[size];
  }
  ~ChainedHashTable() {
    // delete table
    make_empty();
  }
  void insert(Type key, Type value) {
    // insert key and value to table
    insert(key, value, table, hash, size, inserts);
  }
  void insert_unique(Type key, Type value) {
    // insert unique key and value
    insert_unique(key, value, table, hash, size, inserts);
  }
  void remove(Type key) {
    // remove key from table
    remove(key, table, walk, hash, size);
  }
  void find(Type key, List * & result) {
    // find key and values in table
    find(key, table, walk, hash, size, result);
  }
  void make_empty() {make_empty(table, size);}
  unsigned int get_size() {return size;}
  unsigned int get_inserts() {return inserts;}
private:
  unsigned int size;
  List ** table;
  Walk * walk;
  Hash * hash;
  unsigned int inserts;
  void insert(Type key, Type value, List ** & table, Hash * & hash, unsigned int size, unsigned int & inserts) {
    // insert key and value to table
    // todo keep flag to show if there is collision
    unsigned int position = hash->position(key, size);
    if(!table[position]) table[position] = new List(key, value);
    else table[position]->insert_right(key, value);
    inserts++;
  }
  void insert_unique(Type key, Type value, List ** & table, Hash * & hash, unsigned int size, unsigned int & inserts) {
    // insert unique key to table
    Node * item;
    unsigned int position = hash->position(key, size);
    if(!table[position]) table[position] = new List(key, value);
    else {
      walk->set_list(table[position]);
      walk->rewind();
      while((item = walk->next())) {
        if(!key.compare(item->key)) {walk->unset_list(); return;}
      }
      table[position]->insert_right(key, value);
    }
    inserts++;
  }
  void remove(Type key, List ** & table, Walk * & walk, Hash * & hash, unsigned int size) {
    // remove key from table
    // unsigned int position = hash->position(key, size);
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
  void find(Type key, List ** & table, Walk * & walk, Hash * & hash, unsigned int size, List * & result) {
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
  void make_empty(List ** & table, unsigned int size) {
    for(unsigned int i = 0; i < size; i++) {
      if(table[i]) {
        table[i]->make_empty();
        delete table[i];
        table[i] = NULL;
      }
    }
    delete[] table;
  }
};