// Gabriel Toschi de Oliveira - 9763039

#ifndef _DATAARRAY_H_
#define _DATAARRAY_H_

#include <stdio.h>
#include <string.h>

typedef char * DataType;
typedef int (*DataTypeCompareFunction)(DataType, DataType);

typedef struct s_DataArray {
  DataType *array;
  int size;
  DataTypeCompareFunction compare;
} DataArray;


DataArray readArray(char *filename, DataType (*readElement)(FILE *));
void freeDataArray(DataArray data, void (*freeElement)(DataType));
void swapDataArrayElements(DataType *a, DataType *b);
void printDataArray(DataArray data, void (*printElement)(DataType));
DataArray copyDataArray(DataArray source);
void resetDataArray(DataArray data, DataArray base);

#endif
