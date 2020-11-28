// Gabriel Toschi de Oliveira - 9763039

#include <input.h>

char *readString(FILE *stream, char delim, bool toLower){
	char *str = NULL;
	int counter = 0;
	char c;

	do {
		c = fgetc(stream);
		str = realloc(str, sizeof(char)*(counter+1));
		str[counter++] = toLower ? tolower(c) : c;
	} while (c != delim && c != EOF);

	str[--counter] = '\0';
	return str;
}

int getFileLineAmount(FILE *stream) {
  long currentFilePosition = ftell(stream);
  rewind(stream);

  int lineAmount = 0;
  char c;

  do {
    c = fgetc(stream);
    if (c == '\n') lineAmount++;
  } while (c != EOF);

  fseek(stream, currentFilePosition, SEEK_SET);

  return lineAmount;
}
