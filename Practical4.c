#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char command[1024];
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(0);
    }
    sprintf(command,"stat %s",argv[1]);
    system(command);
    return 0;
}