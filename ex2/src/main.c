// Gabriel Toschi de Oliveira - 9763039

#include <stdlib.h>
#include <stdio.h>

#include <search.h>

int main(int argc, char *argv[]){

  int dataAmount, queryAmount;
  int *data;

  int currentSearchType, currentQuery;

  scanf("%d %d", &dataAmount, &queryAmount);
  data = malloc(sizeof(int) * dataAmount);

  for (int i = 0; i < dataAmount; i++) {
    scanf("%d", &data[i]);
  }

  for (int i = 0; i < queryAmount; i++) {
    scanf("%d %d", &currentSearchType, &currentQuery);
    int searchResult;

    switch (currentSearchType) {
      case SEQUENTIAL:
        searchResult = sequentialSearch(data, dataAmount, currentQuery);
        break;

      case ITERATIVE_BINARY:
        searchResult = iterativeBinarySearch(data, dataAmount, currentQuery);
        break;

      case RECURSIVE_BINARY:
        searchResult = recursiveBinarySearch(data, dataAmount, currentQuery);
        break;
    }

    // for specification reasons, the position is one-based indexing
    printf("%d\n", searchResult == NOT_FOUND ? searchResult : searchResult + 1);
  }

  free(data);

  return 0;
}
