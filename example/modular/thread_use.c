#include <stdio.h>
#include <stdlib.h>

#include "thread.h"

int thread_runner() {
    printf("Thread is running...\n");

    return 0;
}

int main()
{
    printf("Testing Thread module...\n");

    //requires passing -mwin32 as a flag to mingw/gcc in order to detect WIN32 #ifdef

    THREAD* my_thread = factory_create_thread();
    init_thread(my_thread);

    run_thread(my_thread, &thread_runner);

    wait_thread(my_thread);

    //wait/block or program might end faster than the thread.

    close_thread(my_thread);

    return 0;
}
