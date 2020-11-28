// Gabriel Toschi de Oliveira - 9763039

#ifndef _INPUT_H_
#define _INPUT_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

char *readString(FILE *stream, char delim, bool toLower);
int getFileLineAmount(FILE *stream);

#endif
