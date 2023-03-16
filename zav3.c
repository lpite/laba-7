#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMBER_LENGTH 100

void slice(const char *str, char *result, size_t start, size_t end) {
  strncpy(result, str + start, end - start);
}

int main() {
  char str[] = "77+8*6";
  int strLen = sizeof(str) / sizeof(char) - 1;
  printf("str = %s\nstrLen = %d\n", str, strLen);
  int result = 0;

  // 1 - *
  // 0 - +
  // -1 - nothing
  int prevChar = -1;
  int numLength = 0;
  int lastMult = 1;

  for (int i = 0; i < strLen; ++i) {
    // елемент масиву
    int el = str[i];
    if (el == 42) {
      char temp[MAX_NUMBER_LENGTH] = "";
      slice(str, temp, i - numLength, i);
      lastMult *= atoi(temp);
      prevChar = 1;
      numLength = 0;
    } else if (el == 43) {
      if (prevChar == 1) {
        char temp[MAX_NUMBER_LENGTH] = "";
        if (i - (i - numLength) == 1) {
          slice(str, temp, i - numLength, i + 1);
        } else {
          slice(str, temp, i - numLength, i);
        }
        lastMult *= atoi(temp);
        result += lastMult;
        lastMult = 1;
      } else if (prevChar == 0) {
        char temp[MAX_NUMBER_LENGTH] = "";
        slice(str, temp, i - numLength, i);
        result += atoi(temp);
      } else {
        char temp[MAX_NUMBER_LENGTH] = "";
        slice(str, temp, i - numLength, i);
        result += atoi(temp);
      }
      prevChar = 0;
      numLength = 0;
    } else if (i == strLen - 1) {
      if (prevChar == 1) {
        char temp[MAX_NUMBER_LENGTH] = "";
        slice(str, temp, i - numLength, i + 1);
        lastMult *= atoi(temp);
        result += lastMult;
        lastMult = 1;
      } else if (prevChar == 0) {
        char temp[MAX_NUMBER_LENGTH] = "";
        slice(str, temp, i - numLength, i + 1);
        result += atoi(temp);
      }
    } else {
      numLength++;
    }
  }
  printf("result = %d", result);
  return 0;
}
