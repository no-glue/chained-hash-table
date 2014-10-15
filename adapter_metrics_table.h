template<typename Type, class Wrapper, class Node, class List, class Walk, class Table>class AdapterMetricsTable {
public:
  AdapterMetricsTable() {}
  AdapterMetricsTable(Wrapper * & wrapper, Table * & table, Walk * & walk, Table * & table_visited, Walk * & walk_running):
    wrapper(wrapper), table(table), walk(walk), table_visited(table_visited), walk_running(walk_running) {}
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
    return breadth_first_search(wrapper, table, walk, table_visited, walk_running);
  }
  int find_single_int(Type key) {
    // find single item of type int
    return find_single_int(key, table, walk);
  }
private:
  Wrapper * wrapper;
  Table * table;
  Walk * walk;
  Table * table_visited;
  Walk * walk_running;
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
  double breadth_first_search(Wrapper * & wrapper, Table * & table, Walk * & walk, Table * & table_visited, Walk * & walk_running) {
    Node * current;
    Node * current_running;
    List * running = new List();
      table->find("startnode", running);
    List * depth = new List();
    List * node = new List();
      table->find(running->get_head()->value, node);
      running->make_empty();
      walk->set_list(node);
      walk->rewind();
      table_visited->insert_unique(node->get_head()->key, node->get_head()->key);
      while((current = walk->next())) {
        depth->insert_right("1", "1");
        table_visited->insert_unique(current->value, current->value);
        // todo table_visited
      }
      walk->unset_list();
    while(node->get_head()) {
      walk_running->unset_list();
      // todo walk_running
        running->make_empty();
        table->find(node->get_head()->value, running);
        walk_running->set_list(running);
        walk_running->rewind();
        while((current_running = walk_running->next())) {
          if(table_visited->insert_unique(current_running->value, current_running->value)) {
            node->insert_right(current_running->value, current_running->value);
            depth->insert_right(wrapper->to_string(atoi(depth->get_head()->value) + 1), wrapper->to_string(atoi(depth->get_head()->value) + 1));
          }
        }
      node->pop_left();
      depth->pop_left();
    }
    walk_running->unset_list();
    delete running;
    delete depth;
    walk->unset_list();
    delete node;
    return 1;
  }
};