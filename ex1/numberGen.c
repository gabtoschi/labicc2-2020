#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef enum Arguments {
  FILENAME,
  QUANTITY_TO_GENERATE,
  ARGUMENT_TOTAL
} Arguments;

int main(int argc, char *argv[]){
  srand(time(NULL));

  if (argc < ARGUMENT_TOTAL) return -1;
  int quantityToGenerate = atoi(argv[QUANTITY_TO_GENERATE]);

  printf("%d\n", quantityToGenerate);
  for (int i = 0; i < quantityToGenerate; i++) {
    printf("%d ", rand());
  }

  printf("\n");

  return 0;
}
