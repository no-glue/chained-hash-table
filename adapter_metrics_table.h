template<typename Type, class Node, class List, class Walk, class Table>class AdapterMetricsTable {
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
    Node * current;
    Node * current_running;
    Node * current_depth;
    List * running = new List();
      table->find("startnode", running);
    List * depth = new List();
      walk_depth->set_list(depth);
      // todo walk_depth
      walk_depth->rewind();
    List * node = new List();
      table->find(running->get_head()->value, node);
      running->make_empty();
      walk->set_list(node);
      walk->rewind();
      while((current = walk->next())) {
        depth->insert_right("1", "1");
        table_visited->insert_unique(current->key, current->value);
        // todo table_visited
      }
      walk->rewind();
    while((current = walk->next())) {
      current_depth = walk_depth->next();
      walk_running->unset_list();
      // todo walk_running
        running->make_empty();
        table->find(current->value, running);
        walk_running->set_list(running);
        walk_running->rewind();
        while((current_running = walk_running->next())) {
          if(table_visited->insert_unique(current_running->key, current_running->value)) {
            node->insert_right(current_running->key, current_running->value);
            depth->insert_right(itoa(atoi(current_depth->value) + 1), itoa(atoi(current_depth->value) + 1));
          }
        }
    }
    walk_running->unset_list();
    delete running;
    walk_depth->unset_list();
    delete depth;
    walk->unset_list();
    delete node;
    return 1;
  }
};