#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void part_e()
{
    char *buf1 = malloc(100);
    if (buf1 == NULL)
    {
        perror("Memory allocation error for buf1");
        exit(EXIT_FAILURE);
    }
    strcpy(buf1, "hello world");
    printf("buf1 before free : %s\n", buf1);
    free(buf1);
    printf("buf1 after free  : %s\n", buf1);

    char *buf2 = malloc(100);
    if (buf2 == NULL)
    {
        perror("Memory allocation error for buf2");
        exit(EXIT_FAILURE);
    }
    strcpy(buf2, "hello again");
    printf("buf2 new alloc   : %s\n", buf2);

    char *mid = buf2 + 50;
    free(mid);
    printf("buf2 after bad free: %s\n", buf2);

    free(buf2);
}

int main(void)
{
    part_e();

    return 0;
}
