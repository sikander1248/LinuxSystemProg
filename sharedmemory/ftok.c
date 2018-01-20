/* ftok - generate key from path and id */

#include <stdio.h>
#include <stdlib.h>
int main()
{
	const char *pwd = getenv("PWD");

	printf("Current Directory = %s \n",pwd);

	key_t key = ftok(pwd,2);

	printf("Key generated = %x \n",key);
}
