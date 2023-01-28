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
// Unknown platform.
#endif

// separate these below in two distinctive files.

// Conditional compilation.

#if defined(WIN32) && !defined(UNIX)

#include "logger.h"

#include "globals.h"

typedef struct THREAD_WIN32
{

} THREAD_WIN32;

THREAD_WIN32 *factory_create_thread_win32();
int init_thread_win32(THREAD_WIN32 *thread);

void *run_thread_win32(THREAD_WIN32 *thread, unsigned long (*thread_ptr)(void *), void *parameter, int param_const);
int close_thread_win32(THREAD_WIN32 *thread);
int wait_thread_win32(THREAD_WIN32 *thread);
int stop_thread_win32(THREAD_WIN32 *thread);
int pause_thread_win32(THREAD_WIN32 *thread);

#elif defined(UNIX) && !defined(WIN32)

typedef struct THREAD_UNIX
{

} THREAD_UNIX;

THREAD_UNIX *factory_create_thread_unix();
int init_thread_unix(THREAD_UNIX *thread);

void *run_thread_unix(THREAD_UNIX *thread, unsigned long (*thread_ptr)(void *), void *parameter, int param_const);
int close_thread_unix(THREAD_UNIX *thread);
int wait_thread_unix(THREAD_UNIX *thread);
int stop_thread_unix(THREAD_UNIX *thread);
int pause_thread_unix(THREAD_UNIX *thread);

#else
// Unknown platform.

#endif

/////////////////////////////////////////////////////

// Generic crssplatform.

typedef struct THREAD
{

#if defined(WIN32) && !defined(UNIX)
        THREAD_WIN32 *internal_thread;
#elif defined(UNIX) && !defined(WIN32)
        THREAD_UNIX *internal_thread;
#else
        // Unknown platform.
#endif
} THREAD;

// Crossplatform.

THREAD *factory_create_thread();
int init_thread(THREAD *thread);

void *run_thread(THREAD *thread, unsigned long (*thread_ptr)(void *), void *parameter, int param_const);
int close_thread(THREAD *thread);
int wait_thread(THREAD *thread);
int stop_thread(THREAD *thread);
int pause_thread(THREAD *thread);

#endif
