#define BUFFER_SIZE 128
#define BFS(diameter, average_path_lenght, option) return (!option) ? diameter : average_path_length

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
  void breadth_first_search(List * & results) {
    breadth_first_search(wrapper, table, walk, table_visited, walk_running, buffer, results);
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
  char buffer[BUFFER_SIZE];
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
  void breadth_first_search(Wrapper * & wrapper, Table * & table, Walk * & walk, Table * & table_visited, Walk * & walk_running, char * buffer, List * & results) {
    Node * current;
    Node * current_running;
    List * running = new List();
      table->find("startnode", running);
    List * depth = new List();
    double paths = 0;
    double lengths = 0;
    double average_path_length = 0;
    List * node = new List();
      table->find(running->get_head()->value, node);
      running->make_empty();
      walk->set_list(node);
      walk->rewind();
      table_visited->insert_unique(node->get_head()->key, node->get_head()->key);
      while((current = walk->next())) {
        paths++;
        lengths++;
        average_path_length = lengths / paths;
        depth->insert_right("1", "1");
        table_visited->insert_unique(current->value, current->value);
      }
      walk->unset_list();
    int diameter = 0;
    while(node->get_head()) {
      walk_running->unset_list();
        running->make_empty();
        table->find(node->get_head()->value, running);
        walk_running->set_list(running);
        walk_running->rewind();
        while((current_running = walk_running->next())) {
          if(table_visited->insert_unique(current_running->value, current_running->value)) {
            paths++;
            lengths += atoi(depth->get_head()->value);
            average_path_length = lengths / paths;
            node->insert_right(current_running->value, current_running->value);
            diameter = atoi(depth->get_head()->value) + 1;
            wrapper->clear(buffer, BUFFER_SIZE);
            wrapper->int_to_alpha(buffer, diameter);
            depth->insert_right(buffer, buffer);
          }
        }
      node->pop_left();
      depth->pop_left();
    }
    results->insert_right(buffer, buffer);
    wrapper->clear(buffer, BUFFER_SIZE);
    wrapper->float_to_alpha(buffer, average_path_length);
    results->insert_right(buffer, buffer);
    walk_running->unset_list();
    delete running;
    delete depth;
    walk->unset_list();
    delete node;
  }
};