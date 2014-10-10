template<class Adapter>class MetricsTable {
public:
    int nodes(Adapter * & adapter) {
        // get number of nodes
        return adapter->find_single_int("nodes");
    }
};