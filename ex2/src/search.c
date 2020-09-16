#include <search.h>

#define BINARY_MEDIUM_INDEX(left, right) (left + right) / 2

int sequentialSearch(int* data, int amount, int searchQuery) {
  for (int index = 0; index < amount; index++) {
    if (data[index] == searchQuery) {
      return index;
    }
  }

  return NOT_FOUND;
}

int iterativeBinarySearch(int* data, int amount, int searchQuery) {
  int leftLimit = 0;
  int rightLimit = amount - 1;

  while (leftLimit < rightLimit) {
    int checkingIndex = BINARY_MEDIUM_INDEX(leftLimit, rightLimit);

    if (searchQuery == data[checkingIndex]) {
      return checkingIndex;
    }

    if (searchQuery < data[checkingIndex]) {
      rightLimit = checkingIndex - 1;
    } else { // data[checkingIndex] > searchQuery
      leftLimit = checkingIndex + 1;
    }
  }

  return NOT_FOUND;
}

int recursiveBinarySearchLoop(int *data, int leftLimit, int rightLimit, int searchQuery) {
  int checkingIndex = BINARY_MEDIUM_INDEX(leftLimit, rightLimit);

  if (rightLimit >= leftLimit) {
    if (data[checkingIndex] == searchQuery) {
      return checkingIndex;
    }

    if (searchQuery < data[checkingIndex]) {
      return recursiveBinarySearchLoop(data, leftLimit, checkingIndex - 1, searchQuery);
    } else { // data[checkingIndex] > searchQuery
      return recursiveBinarySearchLoop(data, checkingIndex + 1, rightLimit, searchQuery);
    }
  }

  return NOT_FOUND;
}

int recursiveBinarySearch(int *data, int amount, int searchQuery) {
  return recursiveBinarySearchLoop(data, 0, amount - 1, searchQuery);
}


