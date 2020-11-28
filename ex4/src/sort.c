#include <sort.h>

bool compareByType(SortType type, int compResult) {
  return type == ASCENDING_SORT ? compResult > 0 : compResult < 0;
}

DataArray bubbleSort(DataArray data, SortType type) {
  for (int i = 0; i < data.size - 1; i++) {
    for (int j = 0; j < data.size - i - 1; j++) {
      if (compareByType(type, data.compare(data.array[j], data.array[j+1]))) {
        swapDataArrayElements(&data.array[j], &data.array[j+1]);
      }
    }
  }

  return data;
}

DataArray insertionSort(DataArray data, SortType type) {
  DataType pivot;
  int j;

  for (int i = 1; i < data.size; i++) {
    pivot = data.array[i];
    j = i - 1;

    while (j >= 0 && compareByType(type, data.compare(data.array[j], pivot))) {
      data.array[j + 1] = data.array[j];
      j--;
    }

    data.array[j + 1] = pivot;
  }

  return data;
}

int mergeSortFinish(DataType *mergedArray, DataType *tempArray, int amountToFinish) {
  if (!amountToFinish) return 0; // no elements were added

  memcpy(mergedArray, tempArray, amountToFinish * sizeof(DataType));
  return amountToFinish;
}

void mergeSortMerge(DataArray data, SortType type, int l, int m, int r) {
  int lSize = m - l + 1;
  int rSize = r - m;

  DataType *lTemp = malloc(lSize * sizeof(DataType));
  memcpy(lTemp, data.array + l, lSize * sizeof(DataType));

  DataType *rTemp = malloc(rSize * sizeof(DataType));
  memcpy(rTemp, data.array + m + 1, rSize * sizeof(DataType));

  int lIndex = 0, rIndex = 0, mergeIndex = l;

  while (lIndex < lSize && rIndex < rSize) {
    if (compareByType(type, data.compare(rTemp[rIndex], lTemp[lIndex]))) { // L < R
      data.array[mergeIndex] = lTemp[lIndex++];
    } else {
      data.array[mergeIndex] = rTemp[rIndex++];
    }

    mergeIndex++;
  }

  mergeIndex += mergeSortFinish(data.array + mergeIndex, lTemp + lIndex, lSize - lIndex);
  mergeIndex += mergeSortFinish(data.array + mergeIndex, rTemp + rIndex, rSize - rIndex);

  free(lTemp);
  free(rTemp);
}

void mergeSortDivide(DataArray data, SortType type, int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;

    mergeSortDivide(data, type, l, m);
    mergeSortDivide(data, type, m + 1, r);

    mergeSortMerge(data, type, l, m, r);
  }
}

DataArray mergeSort(DataArray data, SortType type) {
  mergeSortDivide(data, type, 0, data.size - 1);
  return data;
}

