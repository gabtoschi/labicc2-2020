#ifndef _SEARCH_H_
#define _SEARCH_H_

#define NOT_FOUND -1

typedef enum SearchType {
  SEQUENTIAL = 1,
  ITERATIVE_BINARY,
  RECURSIVE_BINARY
} SearchType;

int sequentialSearch(int* data, int amount, int searchQuery);
int iterativeBinarySearch(int* data, int amount, int searchQuery);
int recursiveBinarySearch(int *data, int amount, int searchQuery);

#endif
