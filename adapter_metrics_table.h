template<typename Type, class List, class Walk, class Table>class AdapterMetricsTable {
public:
  AdapterMetricsTable() {}
  AdapterMetricsTable(Table * & table, Walk * & walk):table(table), walk(walk) {}
  double density() {
    // density
    double e = (double)edges();
    double n = (double)nodes();
    return (2 * e) / (n * (n - 1));
  }
  double average_degree() {
    // average degree
    double e = (double)edges();
    double n = (double)nodes();
    return (2 * e) / n;
  }
  int nodes() {
    // number of nodes
    return find_single_int("nodes");
  }
  int edges() {
    // number of edges
    return find_single_int("edges");
  }
  double breadth_first_search() {
    return breadth_first_search(table, walk);
  }
  int find_single_int(Type key) {
    // find single item of type int
    return find_single_int(key, table, walk);
  }
private:
  Table * table;
  Walk * walk;
  int find_single_int(Type key, Table * & table, Walk * & walk) {
    // find single item of type int
    List * result = new List();
    table->find(key, result);
    walk->set_list(result);
    walk->rewind();
    int item = atoi(walk->next()->value);
    walk->unset_list();
    delete result;
    return item;
  }
  double breadth_first_search(Table * & table, Walk * & walk) {
    return 1;
  }
};