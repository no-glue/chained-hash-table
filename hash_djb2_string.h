template<typename Type>class HashDjb2String {
public:
  unsigned int position(Type key, unsigned int size) {
    // simple hash just add up bytes and return
    unsigned int hash = 5381;
    unsigned int length = key.length(), i;
    for(i = 0; i < length; i++) hash = ((hash << 5) + hash) + key.at(i);
    return hash % size;
  }
};