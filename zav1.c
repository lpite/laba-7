#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>

int main() {
  char Str[] = "s hello11 world sa salo";
  int strLen = sizeof(Str) / sizeof(char);
  int thisWord = 0, minWordStart = 0, maxWordStart = 0, minWordLen = strLen,
      maxWordLen = 0;

  for (int i = 0; i < strLen; i++) {
    if (Str[i] == 32 || strLen == i + 1) {
      if (thisWord < minWordLen) {
        minWordLen = thisWord;
        minWordStart = i - thisWord;
      }
      if (thisWord > maxWordLen) {
        maxWordLen = thisWord;
        maxWordStart = i - thisWord;
      }
      thisWord = 0;
    } else {
      thisWord++;
    }
  }
  printf("min word len = %d\n", minWordLen);
  printf("min word = ");
  for (int i = minWordStart; i < minWordStart + minWordLen; ++i) {
    printf("%c", Str[i]);
  }
  puts("");
  printf("max word len = %d\n", maxWordLen);
  printf("max word = ");
  for (int i = maxWordStart; i < maxWordStart + maxWordLen; ++i) {
    printf("%c", Str[i]);
  }
  
    return 0;
}
