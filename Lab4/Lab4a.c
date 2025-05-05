#include <stdio.h>
#include <unistd.h>

int global_init = 42;
int global_uninit;
const int global_const = 100;

void part_a()
{
    int local = 0;
    static int static_local = 1;
    const int const_local = 2;

    printf("-- Part a: Addresses --\n");
    printf("local          : %p (stack)\n", (void *)&local);
    printf("static_local   : %p (.data)\n", (void *)&static_local);
    printf("const_local    : %p (stack)\n", (void *)&const_local);
    printf("global_init    : %p (.data)\n", (void *)&global_init);
    printf("global_uninit  : %p (.bss)\n", (void *)&global_uninit);
    printf("global_const   : %p (.rodata)\n", (void *)&global_const);
}

int main(void)
{
    part_a();
    int process_pid = getpid();
    printf("\nPID: %d\n", process_pid);
    printf("Write any character to continue: ");
    getchar();
    return 0;
}
