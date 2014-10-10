template<class Table, class List, class Walk>class AdapterMetricsTable {
public:
  AdapterMetricsTable(Table * & table, List * & result, Walk * & walk):table(table), result(result), walk(walk) {}
  int find_single_int(Type key) {
    // find single item of type int
    return find_single_int(key, table, result, walk);
  }
private:
  Table * table;
  List * result;
  Walk * walk;
  int find_single_int(Type key, Table * & table, List * & result, Walk * & walk) {
    // find single item of type int
    table->find(key, result);
    walk->set_list(result);
    walk->rewind();
    int item = atoi(walk->next()->value);
    walk->unset_list();
    result->make_empty();
    return item;
  }
};