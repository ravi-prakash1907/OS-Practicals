#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int sum = 0;
void *summer(void *);                               //function to run inside thread

int main(int argc, char *argv[])
{
    pthread_t tid;
    pthread_attr_t attr;

    if (argc != 2)                                  // if 2 arguments are not passed on commandline, show error
    {
        fprintf(stderr, "usage: %s <integer value>\n", argv[0]);
        exit(1);
    }
    else if (atoi(argv[1]) < 0)                     // if a negative value is passed as an argument, show error
    {
        fprintf(stderr, "integer value must be > 0\n");
        exit(1);
    }
    pthread_attr_init(&attr);                       // initializing attributes of the thread
    pthread_create(&tid, &attr, summer, argv[1]);   // creating thread
    pthread_join(tid,NULL);                         // wating for thread to exit
    printf("SUM: %d\n",sum);                        
    return 0;
}

void *summer(void *param)
{
    int n = atoi((char*)param);
    for(int i=0;i<=n;i++)
        sum+=i;
    pthread_exit(0);
}