#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char str[] = "hello world,how are you today?";
  char *saved1, *saved2;

  char *ptr1, *ptr2;
  for (ptr1 = strtok_s(str, ",", &saved1); ptr1;
       ptr1 = strtok_s(NULL, ",", &saved1)) {
    printf("Token 1: %s\n", ptr1);
    for (ptr2 = strtok_s(ptr1, " ", &saved2); ptr2;
         ptr2 = strtok_s(NULL, " ", &saved2)) {
      printf("Token 2: %s\n", ptr2);
    }
  }
  // while (ptr1 != NULL) {
  //   printf("Token 1: %s\n", ptr1);
  //   char *ptr2 = strtok_r(ptr1, " ", &saved2);
  //   while (ptr2 != NULL) {
  //     printf("Token 2: %s\n", ptr2);
  //     ptr2 = strtok_r(NULL, " ", &saved2);
  //   }
  //   ptr1 = strtok_r(NULL, ",", &saved1);
  // }
  return 0;
}
