#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024
#define DEBUG

void copy(char *, char *);

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "ERROR: usage: %s, <src> <dst>\n", argv[0]);
        return 1;
    }
    printf("Copying %s to %s\n", argv[1], argv[2]);
    copy(argv[1], argv[2]);
    return 0;
}

void copy(char *src, char *dst)
{
    int sfd, dfd, count;
    char buffer[BUFFER_SIZE];
    mode_t fileMode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    sfd = open(src, O_RDONLY);
    if (!sfd)
    {
        fprintf(stderr, "ERROR: %s doesn't exists\n", src);
        exit(1);
    }
    dfd = open(dst, O_CREAT | O_WRONLY | O_TRUNC, fileMode);
    while ((count = read(sfd, buffer, BUFFER_SIZE)) > 0)
    {
        write(dfd, buffer, count);
    }
    close(sfd);
    close(dfd);
}