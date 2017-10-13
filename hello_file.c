#include<stdio.h>

int main()
{
    int a;

    // File descriptor
    FILE* in_fd;

    // Try to open file. If it fails for some reason - print error message and exit.
    if( (in_fd = fopen("input.txt","r")) == NULL ) {
        printf("Can not open file!\n");
        return -1;
    }

    // Read everything from file - continue reading while not EOF.
    while(fscanf(in_fd,"%d",&a) != EOF)
    {
        printf("Read from file: %d\n",a);
    }

    // Close file
    fclose(in_fd);

    return 0;
}
