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
    double network_diameter() {
        // network diameter
        return network_diameter(adapter);
    }
    double average_path_length() {
        // average path length
        return average_path_length(adapter);
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
    double network_diameter(Adapter * & adapter) {
        // network diameter
        return adapter->network_diameter();
    }
    double average_path_length(Adapter * & adapter) {
        // average path length
        return adapter->average_path_length();
    }
};