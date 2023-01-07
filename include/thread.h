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

int run_thread(THREAD* thread, POINTER_TO_FUNCTION);
int close_thread(THREAD* thread);
int wait_thread(THREAD* thread);
int stop_thread(THREAD* thread);
int pause_thread(THREAD* thread);

//separate these below in two distinctive files.

// Conditional compilation.

	#if defined(WIN32) && !defined(UNIX)

typedef struct THREAD_WIN32 {

} THREAD;

int run_thread_win32(THREAD_WIN32* thread, POINTER_TO_FUNCTION);
int close_thread_win32(THREAD_WIN32* thread);
int wait_thread_win32(THREAD_WIN32* thread);
int stop_thread_win32(THREAD_WIN32* thread);
int pause_thread_win32(THREAD_WIN32* thread);

	#elif defined(UNIX) && !defined(WIN32)

typedef struct THREAD_UNIX {

} THREAD;

int run_thread_unix(THREAD_UNIX* thread, POINTER_TO_FUNCTION);
int close_thread_unix(THREAD_UNIX* thread);
int wait_thread_unix(THREAD_UNIX* thread);
int stop_thread_unix(THREAD_UNIX* thread);
int pause_thread_unix(THREAD_UNIX* thread);

	#else
// Unknown platform.

	#endif

#endif
