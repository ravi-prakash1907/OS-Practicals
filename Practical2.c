#include<stdio.h>
#include<stdlib.h>

int main()
{
    printf("### Kernel Information ###\n\n");
    system("cat /proc/version_signature | awk '{printf \"Kernel Version: %s\\n\", $0}'");
    printf("\n### CPU Information ###\n\n");
    system("cat /proc/cpuinfo | awk '/processor|model/{print}'");
    return 0;
}