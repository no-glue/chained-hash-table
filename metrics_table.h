template<class Adapter>class MetricsTable {
public:
    MetricsTable() {}
    MetricsTable(Adapter * & adapter): adapter(adapter) {}
    int nodes() {
        // get number of nodes
        return nodes(adapter);
    }
private:
    Adapter * adapter;
    int nodes(Adapter * & adapter) {
        // get number of nodes
        return adapter->find_single_int("nodes");   
    }
};