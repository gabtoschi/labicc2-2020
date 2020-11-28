#ifndef _SORT_H_
#define _SORT_H_

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include <dataarray.h>

typedef enum e_SortType {
  ASCENDING_SORT,
  DESCENDING_SORT
} SortType;

DataArray bubbleSort(DataArray data, SortType type);
DataArray insertionSort(DataArray data, SortType type);
DataArray mergeSort(DataArray data, SortType type);

#endif
