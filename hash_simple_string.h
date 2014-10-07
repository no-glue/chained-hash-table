template<typename Type>class HashSimpleString {
  unsigned int position(Type key, unsigned int size) {
    // simple hash just add up bytes and return
    char * ch;
    ch = key.toCharArray();
    unsigned int length = key.length(), i, sum;
    for(i = 0, sum = 0; i < length; i++) sum += ch[i];
    return sum % size;
  }
};