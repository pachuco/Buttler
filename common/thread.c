/*
	Threading library implementation.
*/

#include "thread.h"

int run_thread() {

	#if defined(WIN32) && !defined(UNIX)
		return run_thread_win32();
	#elif defined(UNIX) && !defined(WIN32)
		return run_thread_unix();
	#else
		//Unknown platform.
		//throw compiler error.
	#endif
}

int close_thread() {

	#if defined(WIN32) && !defined(UNIX)
        	return close_win32();
	#elif defined(UNIX) && !defined(WIN32)
        	return close_thread_unix();
	#else
        	//Unknown platform.
		//throw compiler error.
	#endif
}

int wait_thread() {

	#if defined(WIN32) && !defined(UNIX)
        	return wait_thread_win32();
	#elif defined(UNIX) && !defined(WIN32)
        	return wait_thread_unix();
	#else
        	//Unknown platform.
		//throw compiler error.
	#endif
}

int stop_thread() {
	#if defined(WIN32) && !defined(UNIX)
                return stop_thread_win32();
        #elif defined(UNIX) && !defined(WIN32)
                return stop_thread_unix();
        #else
                //Unknown platform.
		//throw compiler error.
        #endif
}

int pause_thread() {
	#if defined(WIN32) && !defined(UNIX)
                return pause_thread_win32();
        #elif defined(UNIX) && !defined(WIN32)
                return pause_thread_unix();
        #else
                //Unknown platform.
		//throw compiler error.
        #endif

}

// Win32 Impl. ========================================

int run_thread_win32() {
	CreateThread(...);
}

int close_thread_win32() {
	CloseHandle?(...)
}

int wait_thread_win32() {
	WaitForSingleObject(...);
}

int stop_thread_win32() {
	TerminateThread(...);
}

int pause_thread_win32() {
	SuspendThread(...);
}

// Unix Impl. ========================================

int run_thread_unix() {
	pthread_create(...);
}

int close_thread_unix() {
	close?(...);
}

int wait_thread_unix() {
	pthread_join(...);
}

int stop_thread_unix() {
	pthread_exit(...);
}

int pause_thread_unix() {
	pthread_suspend(...);
}
