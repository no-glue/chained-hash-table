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
private:
    Adapter * adapter;
    int nodes(Adapter * & adapter) {
        // get number of nodes
        return adapter->nodes();
    }
    int edges(Adapter * & adapter) {
        // get number of edges
        return adapter->edges();
    }
    double density(Adapter * & adapter) {
        // get density
        return adapter->density();
    }
    double average_degree(Adapter * & adapter) {
        // average degree
        return adapter->average_degree();
    }
};