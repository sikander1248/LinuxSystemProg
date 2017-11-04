#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc,char *argv[])
{
        int fdr = open(argv[1] , O_RDONLY);
        int fdw = open(argv[1] , O_WRONLY);

        char str1[20] = "";
        int x;
        x = write(fdr , "SIKANDER" , 8);
        printf("x = %d\n",x);
        if(x != 8)
                printf("Unable to write using fdr \n");

        x = read(fdr , str1 , 8);
        printf("x = %d\n",x);
        if(x <= 0)
                printf("Unable to read using fdr \n");
        else
                printf("Data read using fdr = %s \n" , str1);

        char str2[20] = "";
        if(write(fdw , "CRANES" , 6) != 6)
                printf("Unable to write using fdw \n");
        x = read(fdw , str2 , 8);        
        printf("x = %d\n",x);
        if(x <= 0)
                printf("Unable to read using fdw \n");
        else
                printf("Data read using fdw = %s \n" , str2);

}
