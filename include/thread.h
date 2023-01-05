/*
        Threading conditional compilation module.
*/

#ifndef THREAD_H
#define THREAD_H

// Crossplatform.

int run_thread();
int close_thread();
int wait_thread();
int stop_thread();
int pause_thread();

// Conditional compilation.

	#if defined(WIN32) && !defined(UNIX)
int run_thread_win32();
int close_thread_win32();
int wait_thread_win32();
int stop_thread_win32();
int pause_thread_win32();

	#elif defined(UNIX) && !defined(WIN32)
int run_thread_unix();
int close_thread_unix();
int wait_thread_unix();
int stop_thread_unix();
int pause_thread_unix();

	#else
// Unknown platform.

	#endif

#endif
