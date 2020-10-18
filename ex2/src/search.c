// Gabriel Toschi de Oliveira - 9763039

#include <search.h>

#define BINARY_MEDIUM_INDEX(left, right) (left + right) / 2

int sequentialSearch(int* data, int size, int searchQuery) {  // F
  for (int index = 0; index < size; index++) {                // A+C [1a it], 2A+C [2a it+]
    if (data[index] == searchQuery) {                         // M+C
      return index;                                           // F
    }
  }

  return NOT_FOUND;
}

int iterativeBinarySearch(int* data, int size, int searchQuery) { // F
  int left = 0;                                                   // A
  int right = size - 1;                                           // 2A

  while (left < right) {                                          // C
    int checkingIndex = BINARY_MEDIUM_INDEX(left, right);         // 3A

    if (searchQuery == data[checkingIndex]) {                     // M+C
      return checkingIndex;                                       // F
    }

    if (searchQuery < data[checkingIndex]) {                      // M+C
      right = checkingIndex - 1;                                  // 2A
    } else { // data[checkingIndex] > searchQuery
      left = checkingIndex + 1;                                   // 2A
    }
  }

  return NOT_FOUND;                                               // F
}

int recursiveBinarySearchLoop(int *data, int left, int right, int searchQuery) {      // F
  int checkingIndex = BINARY_MEDIUM_INDEX(left, right);                               // 3A

  if (right >= left) {                                                                // C
    if (data[checkingIndex] == searchQuery) {                                         // M+C
      return checkingIndex;                                                           // F
    }

    if (searchQuery < data[checkingIndex]) {                                          // M+C
      return recursiveBinarySearchLoop(data, left, checkingIndex - 1, searchQuery);   // F+5A
    } else { // data[checkingIndex] > searchQuery
      return recursiveBinarySearchLoop(data, checkingIndex + 1, right, searchQuery);  // F+5A
    }
  }

  return NOT_FOUND;                                                                   // F
}

int recursiveBinarySearch(int *data, int size, int searchQuery) {
  return recursiveBinarySearchLoop(data, 0, size - 1, searchQuery);
}


