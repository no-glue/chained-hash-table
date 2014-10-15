#include <stdlib.h>
#include <stdio.h>
#include <cstring>

using namespace std;

class CstringWrapper {
public:
  void int_to_alpha(char * str, int value) {sprintf(str, "%d", value);}
  void clear(char * str, int size) {memset(str, '\0', size);}
};