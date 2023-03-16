#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>

int main() {
	char str[] = "121 553 2342 551 11511 2332 2335 11 1";
	int slen = sizeof(str) / sizeof(char),
		thisWordLength=0;
	for (int i = 0; i < slen; i++)
	{		
		char el = str[i];
		if (el == 32 || slen == i + 1)
		{
			int wordStart = i - thisWordLength;
			int isPalindrome = 1;
			int bandera = thisWordLength % 2 == 0 ? wordStart + (thisWordLength) / 2 : wordStart + thisWordLength;
			for (int i2 = wordStart; i2 < bandera; i2++) {
				int rever = ((wordStart + thisWordLength) - i2 - 1) + wordStart;
				if (str[i2] != str[rever])
				{
					isPalindrome = 0;
				}
			}
			if (isPalindrome)
			{
				puts("palindrom");
			}
			else {
				puts("not palindrom");
			}
			thisWordLength =0;
		}
		else {
			thisWordLength++;
		}
	}
	
	return 0;
}
