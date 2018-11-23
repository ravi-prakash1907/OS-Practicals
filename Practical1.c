#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>

void sameProgramSameCode();
void sameProgramDifferentCode();
void sameProgramWaitForChildToExit();

int main()
{
    int choice;
    while(1)
    {
        printf("1) Same program and same code\n");
        printf("2) Same program different code\n");
        printf("3) before terminating the parent wait for the child to finish it's task\n");
        printf("Enter 0 to exit...\n");
        scanf("%d",&choice);
        switch(choice){
            case 0:
                exit(0);
            case 1:
                sameProgramSameCode();
                break;
            case 2:
                sameProgramDifferentCode();
                break;
            case 3:
                sameProgramWaitForChildToExit();
                break;
            default:
                printf("ERROR: wrong choice try again...\n");
        }
    }
    return 0;
}

void sameProgramSameCode()
{
    system("clear");
    fprintf(stdout,"Now parent and child will execute same code and print pid of themselves and then exit\n");
    fork();
    fprintf(stdout,"pid: %d\n",getpid());
    exit(1);
}  

void sameProgramDifferentCode()
{
    fprintf(stdout,"Now we will execute different code in parent and child\n");
    pid_t pid = fork();
    if(pid==0)
    {
        fprintf(stdout,"Inside child with pid: %d\n",getpid());
        exit(1);
    }
    else if(pid>0)
    {
        fprintf(stdout,"Inside parent with pid: %d\n",getpid());
        exit(1);
    }
    else
    {
        fprintf(stderr,"ERROR: while forking");
        exit(1);
    }
}

void sameProgramWaitForChildToExit()
{
    fprintf(stdout,"Now we will execute different code in parent and child and parent will wait for child\n");
    pid_t pid = fork();
    if(pid==0)
    {
        sleep(1);
        fprintf(stdout,"Inside child with pid: %d\n",getpid());
        fprintf(stdout,"Exiting child\n");
        exit(1);
    }
    else if(pid>0)
    {
        fprintf(stdout,"Inside parent with pid: %d\n",getpid());
        fprintf(stdout,"Parent waiting for child\n");
        wait(NULL);
        fprintf(stdout,"Exiting parent\n");
        exit(1);
    }
    else
    {
        fprintf(stderr,"ERROR: while forking");
        exit(1);
    }
}