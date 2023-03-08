#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>


int main() {
	char str[] = "121 553 2342 551 11511 2332 2335 11 1";
	int slen = sizeof(str) / sizeof(char),thLen=0;
	for (int i = 0; i < slen; i++)
	{
		char el = str[i];
		if (el == 32 || slen == i + 1)
		{
			int wordStart = i - thLen;
			int isPal = 1;
			int bandera = thLen % 2 == 0 ? wordStart + (thLen) / 2 : wordStart + thLen;
			for (int i2 = wordStart; i2 < bandera; i2++) {
				int rever = ((wordStart + thLen) - i2 - 1) + wordStart;

				if (str[i2] != str[rever])
				{
					isPal = 0;
				}
			}
			if (isPal)
			{
				puts("palindrom");
			}
			else {
				puts("not palindrom");
			}
			thLen=0;
		}
		else {
			thLen++;
		}
	}
	
	return 0;
}
