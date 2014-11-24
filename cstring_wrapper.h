#include <stdlib.h>
#include <stdio.h>
#include <cstring>

using namespace std;

class CstringWrapper {
public:
  void int_to_alpha(char * str, int value) {sprintf(str, "%d", value);}
  void float_to_alpha(char * str, double value) {sprintf(str, "%f", value);}
  void copy(char * destination, char * source) {strcpy(destination, source);}
  void concat(char * destination, char * source) {strcat(destination, source);}
  void clear(char * str, int size) {memset(str, '\0', size);}
  char * token(char * str, char * delimiters) {return strtok(str, delimiters);}
  double alpha_to_float(char * str) {return atof(str);}
  int length(char * str) {return strlen(str);}
  int ncompare(char * source, char * other, int size) {return strncmp(source, other, size);}
  char * exists(char * destination, char * source) {return strstr(destination, source);}
};