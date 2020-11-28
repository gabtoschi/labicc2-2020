// Gabriel Toschi de Oliveira - 9763039

#include <string-dataarray.h>

char *stringReadElement(FILE *stream) {
  return readString(stream, '\n', true);
}

void stringFreeElement(char *element) {
  free(element);
}

int stringCompareElements(char *a, char *b) {
  return strcmp(a, b);
}

void stringPrintElement(char *element) {
  printf("%s\n", element);
}
