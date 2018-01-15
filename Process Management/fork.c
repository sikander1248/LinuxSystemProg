#include <unistd.h>
#include <stdio.h>

int main()
{
	printf("Hello \n");

	fork();

	printf("World \n");
	
	return 0;
}

