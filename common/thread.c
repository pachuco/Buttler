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

//separate these in two distinctive files.

// Win32 Impl. ========================================

int run_thread_win32(THREAD_WIN32 * thread, POINTER_TO_FUNCTION) {
	CreateThread(...);
}

int close_thread_win32(THREAD_WIN32 * thread) {
	CloseHandle?(...)
}

int wait_thread_win32(THREAD_WIN32 * thread) {
	WaitForSingleObject(...);
}

int stop_thread_win32(THREAD_WIN32 * thread) {
	TerminateThread(...);
}

int pause_thread_win32(THREAD_WIN32 * thread) {
	SuspendThread(...);
}

// Unix Impl. ========================================

int run_thread_unix(THREAD_UNIX * thread, POINTER_TO_FUNCTION) {
	pthread_create(...);
}

int close_thread_unix(THREAD_UNIX * thread) {
	close?(...);
}

int wait_thread_unix(THREAD_UNIX * thread) {
	pthread_join(...);
}

int stop_thread_unix(THREAD_UNIX * thread) {
	pthread_exit(...);
}

int pause_thread_unix(THREAD_UNIX * thread) {
	pthread_suspend(...);
}
