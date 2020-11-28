// Gabriel Toschi de Oliveira - 9763039

#include <dataarray.h>
#include <input.h>

DataArray readArray(char *filename, DataType (*readElement)(FILE *)) {
  FILE *file = fopen(filename, "r");

  DataArray data;
  data.size = getFileLineAmount(file);
  data.array = malloc(sizeof(DataType) * data.size);

  for (int i = 0; i < data.size; i++) {
    data.array[i] = readElement(file);
  }

  fclose(file);

  return data;
}

void freeDataArray(DataArray data, void (*freeElement)(DataType)) {
  if (freeElement) {
    for (int i = 0; i < data.size; i++) freeElement(data.array[i]);
  }

  free(data.array);
}

void swapDataArrayElements(DataType *a, DataType *b) {
  DataType aux = *a;
  *a = *b;
  *b = aux;
}

void printDataArray(DataArray data, void (*printElement)(DataType)) {
  for (int i = 0; i < data.size; i++) {
    printElement(data.array[i]);
  }
}

DataArray copyDataArray(DataArray source) {
  DataArray copy;

  copy.array = malloc(sizeof(DataType) * source.size);
  memcpy(copy.array, source.array, sizeof(DataType) * source.size);

  copy.compare = source.compare;
  copy.size = source.size;

  return copy;
}

void resetDataArray(DataArray data, DataArray base) {
  if (data.size == base.size) {
    memcpy(data.array, base.array, sizeof(DataType) * data.size);
  }
}
