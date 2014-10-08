template<typename Type>class HashSimpleString {
public:
  unsigned int position(Type key, unsigned int size) {
    // simple hash just add up bytes and return
    unsigned int length = key.length(), i, sum;
    for(i = 0, sum = 0; i < length; i++) sum += key.at(i);
    return sum % size;
  }
};