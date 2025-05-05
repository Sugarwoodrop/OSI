#include <stdio.h>

int *bad_return()
{
    int local = 123;
    int *local_p = &local;
    printf("-- Part d -- returned %p, value %d (неопределено)\n", (void *)local_p, *local_p);
    return local_p;
}

void part_d()
{
    int *local_address = bad_return();
    printf("-- Part d -- returned %p, value %d (неопределено)\n", (void *)local_address, *local_address);
}

int main(void)
{
    part_d();
    return 0;
}
