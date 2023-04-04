#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS_COUNT 1000
#define MAX_STRING_LENGTH 1000

int main() {
  char str[] = "6:test6;71:test87;2:tesf12;156:salo;1:ss;";
  char *token = NULL, *saved = NULL;
  int index = 0;
  char *parr[MAX_ELEMENTS_COUNT] = {""};
  token = strtok_s(str, ";", &saved);

  while (token != NULL) {
    if (token != NULL) {
      parr[index] = token;
      index++;
    }
    token = strtok_s(NULL, ";", &saved);
  }

  for (int step = 0; step < index; step++) {
    for (int i = 0; i < index; ++i) {
      char *tok = NULL, *sav = NULL, *nextToken = NULL, *nextSaved = NULL;
      if (i != index - 1) {
        char temp[MAX_STRING_LENGTH] = "";
        char tempNext[MAX_STRING_LENGTH] = "";

        strcpy(temp, parr[i]);
        strcpy(tempNext, parr[i + 1]);

        tok = strtok_s(temp, ":", &sav);
        nextToken = strtok_s(tempNext, ":", &nextSaved);

        if (atoi(tok) > atoi(nextToken)) {
          char *t = parr[i];
          parr[i] = parr[i + 1];
          parr[i + 1] = t;
        }
      }
    }
  }
  for (int i = 0; i < index; ++i) {
    char *tok = NULL, *sav = NULL;
    tok = strtok_s(parr[i], ":", &sav);
    tok = strtok_s(NULL, ":", &sav);
    printf("%s;", tok);
  }
  return 0;
}
