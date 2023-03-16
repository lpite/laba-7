#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getLen(char *str, char *del) {
  char *saved==NULL;
  char *token;
  strcpy(idk, str);
  int len = 0;
  while (token != NULL) {
    len++;
    token = strtok_s(NULL, "*", &saved);
  }
  return len;
}

int main() {
  char str[] = "51+52*89+3+8+112*3+4+66";
  char *saved1, *saved2, *el, *el2;
  int mul = 1, last = 1, fir = 1;
  int multLen = getLen(str, "*");

  int index = 1;
  // printf("multLen == %d\n", multLen);
  for (el = strtok_s(str, "*", &saved1); el;
       el = strtok_s(NULL, "*", &saved1)) {

    // for (el2 = strtok_s(el, "+", &saved2); el2;
    //      el2 = strtok_s(NULL, "+", &saved2)) {
    //   // if (index == multLen) {
    //   //   int thLen = getLen(el, "+");
    //   //   printf("thlen = %d",thLen);
    //   // } else {
    //   last = atoi(el2);
    //   // }
    // }
    printf("index = %d\n", index);
	
    index++;
    printf("last: %d\n", last);
  }

  return 0;
}
