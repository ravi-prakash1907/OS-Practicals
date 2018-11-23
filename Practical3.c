#include<stdio.h>
#include<stdlib.h>

int main()
{
    printf("### Kernel Information ###\n\n");
    system("cat /proc/version_signature | awk '{printf \"Kernel Version: %s\\n\", $0}'");
    printf("\n### Memory status ###\n");
    system("cat /proc/meminfo | awk '/Mem/ {print}'");
    return 0;
}