#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc,char *argv[])
{
        if(argc < 2)
        {
                printf("Missing argument : ./a.out file \n");
                exit(EXIT_FAILURE);
        }

        int fdr = open(argv[1] , O_RDONLY);

        if(fdr == -1)
        {
                printf("Unable to open file \n");
                exit(EXIT_FAILURE);
        }

        char str[21] = "";
        int len;

        while( (len = read(fdr , str , 20)) != 0)
        {
                str[len] = '\0';
                write(1 , str , len);
                printf(" - Position = %d \n" , lseek(fdr , 0 , SEEK_CUR));
        }
        printf("\n Repeating the contents of file \n");
        lseek(fdr , 0 , SEEK_SET);
        while( (len = read(fdr , str , 20)) != 0)
        {
                str[len] = '\0';
                write(1 , str , len);
        }

        close(fdr);
}
