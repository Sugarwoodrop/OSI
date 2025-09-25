#define _GNU_SOURCE
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#define SUCCESS 0
#define THREAD_COUNT 5

int global_var = 13;

void *mythread(void *arg)
{
    int thread_num = *(int*)arg;

    int local_var = 1;
	static int static_var = 2;
	const int const_var = 3;

    printf("thread %d: PID=%d, PPID=%d, gettid()=%d, pthread_self()=%lu\n",
		thread_num, getpid(), getppid(), gettid(), pthread_self());

    --global_var;
    --local_var;

    printf("thread %d:\n", thread_num);
    printf("  local_var   = %d at %p\n", local_var, (void*)&local_var);
    printf("  static_var  = %d at %p\n", static_var, (void*)&static_var);
    printf("  const_var   = %d at %p\n", const_var, (void*)&const_var);
    printf("  global_var  = %d at %p\n\n", global_var, (void*)&global_var);

    return NULL;
}

int main(){
	pthread_t thread_id[THREAD_COUNT];
    int thread_args[THREAD_COUNT];
	int err;
	printf("main [%d %d %d]: Hello from main!\n", getpid(), getppid(), gettid());
    getchar();
    
	for (int i = 0; i < THREAD_COUNT; i++)
	{
        thread_args[i] = i;
		err = pthread_create(&thread_id[i], NULL, mythread, &thread_args[i]);
		if (err != SUCCESS)
		{
			printf("main: pthread_create() failed: %s\n", strerror(err));
			return EXIT_FAILURE;
		}
        sleep(1);
	}

    printf("main: Press any key to exit...\n");
	getchar();
    pthread_exit(NULL);
}
