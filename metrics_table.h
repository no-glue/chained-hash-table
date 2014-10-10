template<class Adapter>class MetricsTable {
public:
    MetricsTable() {}
    MetricsTable(Adapter * & adapter): adapter(adapter) {}
    int nodes() {
        // get number of nodes
        return nodes(adapter);
    }
    int edges() {
        // get number of edges
        return nodes(adapter);
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
};