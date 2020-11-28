// Gabriel Toschi de Oliveira - 9763039

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include <input.h>
#include <dataarray.h>
#include <sort.h>
#include <string-dataarray.h>

#define TIME_EXECUTIONS 10
#define GET_EXECUTION_TIME(start, end) (end - start) / (double) CLOCKS_PER_SEC
#define DEFAULT_SORT_TIME DESCENDING_SORT

enum Arguments {
  FILENAME,
  OUTPUT_TYPE,
  ARGUMENT_TOTAL,
};

typedef enum e_OutputType {
  TIME_OUTPUT = 't',
  RESULT_OUTPUT = 'r',
} OutputType;

enum Algorithm {
  BUBBLE_SORT = 1,
  INSERTION_SORT,
  MERGE_SORT,
};

typedef DataArray (*MeasuredFunction)(DataArray data, SortType type);

double measureTime(MeasuredFunction function, DataArray originalData, SortType type) {
  double timeSum = 0.0;
  DataArray data = copyDataArray(originalData);

  for (int execution = 0; execution < TIME_EXECUTIONS; execution++) {
    if (execution != 0) resetDataArray(data, originalData);

    clock_t startTime = clock();
    function(data, type);
    clock_t endTime = clock();

    timeSum += GET_EXECUTION_TIME(startTime, endTime);
  }

  freeDataArray(data, NULL);
  return timeSum /= (double) TIME_EXECUTIONS;
}

int main(int argc, char *argv[]) {

  if (argc < ARGUMENT_TOTAL) return -1;

  OutputType outputType = argv[OUTPUT_TYPE][0];
  if (outputType != TIME_OUTPUT && outputType != RESULT_OUTPUT) return -1;

  char *filename = readString(stdin, ' ', false);

  int algorithmType;
  scanf("%d", &algorithmType);

  MeasuredFunction sortFunction;
  switch (algorithmType) {
    case BUBBLE_SORT:
      sortFunction = bubbleSort;
      break;

    case INSERTION_SORT:
      sortFunction = insertionSort;
      break;

    case MERGE_SORT:
      sortFunction = mergeSort;
      break;
  }

  DataArray data = readArray(filename, stringReadElement);
  data.compare = stringCompareElements;

  if (outputType == RESULT_OUTPUT) {
    data = sortFunction(data, DEFAULT_SORT_TIME);
    printDataArray(data, stringPrintElement);
  } else { // TIME_OUTPUT
    double averageTime = measureTime(sortFunction, data, DEFAULT_SORT_TIME);
    printf("%lf\t%lf\n", (double) data.size, averageTime);
  }

  freeDataArray(data, stringFreeElement);
  return 0;
}
