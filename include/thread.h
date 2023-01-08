/*
        Threading conditional compilation module.
*/

#ifndef THREAD_H
#define THREAD_H

        #if defined(WIN32) && !defined(UNIX)
#include <windows.h>
// Include only the header for threads and define lean and mean win32
        #elif defined(UNIX) && !defined(WIN32)
#include <pthread.h>
        #else
//Unknown platform.
        #endif

typedef struct THREAD {

} THREAD;

// Crossplatform.

THREAD* factory_create_thread();
int init_thread(THREAD* thread);

int run_thread(THREAD* thread, int (*thread_ptr)(void*));
int close_thread(THREAD* thread);
int wait_thread(THREAD* thread);
int stop_thread(THREAD* thread);
int pause_thread(THREAD* thread);

//separate these below in two distinctive files.

// Conditional compilation.

	#if defined(WIN32) && !defined(UNIX)

typedef struct THREAD_WIN32 {

} THREAD_WIN32;

THREAD_WIN32* factory_create_thread_win32();
int init_thread_win32(THREAD_WIN32* thread);

int run_thread_win32(THREAD_WIN32* thread, int (*thread_ptr)(void*));
int close_thread_win32(THREAD_WIN32* thread);
int wait_thread_win32(THREAD_WIN32* thread);
int stop_thread_win32(THREAD_WIN32* thread);
int pause_thread_win32(THREAD_WIN32* thread);

	#elif defined(UNIX) && !defined(WIN32)

typedef struct THREAD_UNIX {

} THREAD_UNIX;

THREAD_UNIX* factory_create_thread_unix();
int init_thread_unix(THREAD_UNIX* thread);

int run_thread_unix(THREAD_UNIX* thread, int (*thread_ptr)(void*));
int close_thread_unix(THREAD_UNIX* thread);
int wait_thread_unix(THREAD_UNIX* thread);
int stop_thread_unix(THREAD_UNIX* thread);
int pause_thread_unix(THREAD_UNIX* thread);

	#else
// Unknown platform.

	#endif

#endif
