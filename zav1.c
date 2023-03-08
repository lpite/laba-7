#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>


int main() {
	char Str[] = "hello world sa";
	int thisWord = 0, minWord = 999,slen = sizeof(Str) / sizeof(char);

	for (int i = 0; i < slen; i++)
	{
		if (Str[i] == 32 || slen == i+1)
		{
			if (thisWord<minWord)
			{
				minWord = thisWord;
			}
			thisWord = 0;
		}
		else {
			thisWord++;
		}
	}

	printf("min str len = %d", minWord);

	return 0;
}
