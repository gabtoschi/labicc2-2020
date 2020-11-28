// Gabriel Toschi de Oliveira - 9763039

#ifndef _STRING_DATA_ARRAY_H_
#define _STRING_DATA_ARRAY_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include <input.h>

char *stringReadElement(FILE *stream);
void stringFreeElement(char *element);
int stringCompareElements(char *a, char *b);
void stringPrintElement(char *element);

#endif
