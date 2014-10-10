template<class List, class Adapter>class MetricsTable {
public:
    MetricsTable() {}
    MetricsTable(Adapter * & adapter): adapter(adapter) {}
    int nodes() {
        // get number of nodes
        return nodes(adapter);
    }
    int edges() {
        // get number of edges
        return edges(adapter);
    }
    double density() {
        // get density
        return density(adapter);
    }
    double average_degree() {
        // average degree
        return average_degree(adapter);
    }
    double breadth_first_search() {
        // breadth first search
        return breadth_first_search(adapter);
    }
private:
    Adapter * adapter;
    int nodes(Adapter * & adapter) {
        // get number of nodes
        return adapter->find_single_int("nodes");   
    }
    int edges(Adapter * & adapter) {
        // get number of edges
        return adapter->find_single_int("edges");   
    }
    double density(Adapter * & adapter) {
        // get density
        double e = (double)edges(adapter);
        double n = (double)nodes(adapter);
        return (2 * e) / (n * (n - 1));
    }
    double average_degree(Adapter * & adapter) {
        // average degree
        double e = (double)edges(adapter);
        double n = (double)nodes(adapter);
        return (2 * e) / n;
    }
    double breadth_first_search(Adapter * & adapter) {
        // breadth first search
        List * node = new List();
        List * depth = new List();
        adapter->find_single_int("nodes");
        delete node;
        delete depth;
        return 1;
    }
};