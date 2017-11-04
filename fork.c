#include <stdio.h>
#include <unistd.h>

int main()
{
        printf("HELLO \n");

        fork();

        printf("WORLD \n");
}
