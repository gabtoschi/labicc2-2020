// Gabriel Toschi de Oliveira - 9763039

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define COPY_INT_ARRAY(dest, source, quantity) memcpy(dest, source, sizeof(int)*quantity)
#define GET_EXECUTION_TIME(start, end) (end - start) / (double) CLOCKS_PER_SEC

typedef enum Arguments {
  FILENAME,
  GENERATED_NUMBERS_FILENAME,
  EXECUTION_QUANTITY,
  ARGUMENT_TOTAL
} Arguments;

int* readGeneratedNumbers(char *filename, int* quantity) {
  FILE* filePointer = fopen(filename, "r");

  fscanf(filePointer, "%d", quantity);

  int *data = malloc(sizeof(int) * (*quantity));
  for (int i = 0; i < *quantity; i++) {
    fscanf(filePointer, "%d", &data[i]);
  }

  fclose(filePointer);
  return data;
}

void swap(int *a, int *b) {
  int aux = *a;
  *a = *b;
  *b = aux;
}

void reverseArray(int *array, int size) {
  for (int i = 0; i < size / 2; i++) {
    swap(&array[i], &array[size - 1 - i]);
  }
}

void bubbleSort(int *array, int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (array[j] > array[j+1]) swap(&array[j], &array[j+1]);
    }
  }
}

double executeAndMeasure(void (*function)(int *, int), int* source, int* data, int size) {
  COPY_INT_ARRAY(data, source, size);

  clock_t startTime = clock();
  function(data, size);
  clock_t endTime = clock();

  return GET_EXECUTION_TIME(startTime, endTime);
}

int main(int argc, char *argv[]){

  if (argc < ARGUMENT_TOTAL) return -1;

  int numberQuantity;
  int *dataSource = readGeneratedNumbers(argv[GENERATED_NUMBERS_FILENAME], &numberQuantity);
  int *data = malloc(sizeof(int) * numberQuantity);

  int executions = atoi(argv[EXECUTION_QUANTITY]);

  double reverseAverageTime = 0.0;
  double bubbleAverageTime = 0.0;

  for (int currentExecution = 0; currentExecution < executions; currentExecution++) {
    reverseAverageTime += executeAndMeasure(reverseArray, dataSource, data, numberQuantity);
    bubbleAverageTime += executeAndMeasure(bubbleSort, dataSource, data, numberQuantity);
  }

  reverseAverageTime /= (double) executions;
  bubbleAverageTime /= (double) executions;

  // print pattern to plot: # Array Size \t Inverse \t Bubble
  printf("%lf\t%lf\t%lf\n", (double) numberQuantity, reverseAverageTime, bubbleAverageTime);

  free(data);
  free(dataSource);

  return 0;
}

