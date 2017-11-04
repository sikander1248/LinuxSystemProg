#include <stdio.h>
#include <fcntl.h>

int compare(const void *a,const void *b)
{
        return *(const int *)a - *(const int *)b;
}
int main(int argc, char *argv[])
{
        int fdr = open(argv[1] , O_RDONLY);
        int fdw = open(argv[2] , O_WRONLY | O_TRUNC | O_CREAT , 0600);

        dup2(fdr , 0);
        dup2(fdw , 1);

        int n;
        scanf(" %d",&n);
        int arr[n] , i;
        for(i = 0 ; i < n ; i++)
                scanf(" %d", &arr[i]);

        qsort(arr , n , sizeof(int) , compare);

        for(i = 0 ; i < n ; i++)
                printf("%d\n", arr[i]);

}
