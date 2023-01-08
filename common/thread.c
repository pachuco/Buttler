/*
	Threading library implementation.
*/

#include "thread.h"

THREAD* factory_create_thread() {
    //return malloc.

    return 0;
}

int init_thread(THREAD* thread) {
    return 0;
}

int run_thread(THREAD* thread, int (*thread_ptr)(void*)) {

	#if defined(WIN32) && !defined(UNIX)
		return run_thread_win32(thread, thread_ptr);
	#elif defined(UNIX) && !defined(WIN32)
		return run_thread_unix(thread, thread_ptr);
	#else
		//Unknown platform.
		//throw compiler error.
	#endif
}

int close_thread(THREAD* thread) {

	#if defined(WIN32) && !defined(UNIX)
        return close_thread_win32(thread);
	#elif defined(UNIX) && !defined(WIN32)
        return close_thread_unix(thread);
	#else
        //Unknown platform.
		//throw compiler error.
	#endif
}

int wait_thread(THREAD* thread) {

	#if defined(WIN32) && !defined(UNIX)
        return wait_thread_win32(thread);
	#elif defined(UNIX) && !defined(WIN32)
        return wait_thread_unix(thread);
	#else
        //Unknown platform.
		//throw compiler error.
	#endif
}

int stop_thread(THREAD* thread) {
	#if defined(WIN32) && !defined(UNIX)
        return stop_thread_win32(thread);
    #elif defined(UNIX) && !defined(WIN32)
        return stop_thread_unix(thread);
    #else
        //Unknown platform.
        //throw compiler error.
    #endif
}

int pause_thread(THREAD* thread) {
	#if defined(WIN32) && !defined(UNIX)
        return pause_thread_win32(thread);
    #elif defined(UNIX) && !defined(WIN32)
        return pause_thread_unix(thread);
    #else
        //Unknown platform.
        //throw compiler error.
    #endif
}

//separate these in two distinctive files.

// Win32 Impl. ========================================

#if defined(WIN32) && !defined(UNIX)

THREAD_WIN32* factory_create_thread_win32() {
    //return malloc

    return 0;
}

int init_thread_win32(THREAD_WIN32* thread) {
    return 0;
}

int run_thread_win32(THREAD_WIN32 * thread, int (*thread_ptr)(void*)) {
	//CreateThread(...);

	return 0;
}

int close_thread_win32(THREAD_WIN32 * thread) {
	//CloseHandle?(...)

	return 0;
}

int wait_thread_win32(THREAD_WIN32 * thread) {
	//WaitForSingleObject(...);

	return 0;
}

int stop_thread_win32(THREAD_WIN32 * thread) {
	//TerminateThread(...);

	return 0;
}

int pause_thread_win32(THREAD_WIN32 * thread) {
	//SuspendThread(...);

	return 0;
}

#elif defined(UNIX) && !defined(WIN32)

// Unix Impl. ========================================

THREAD_UNIX* factory_create_thread_unix() {
    //return malloc
}

int init_thread_unix(THREAD_UNIX* thread) {
    return 0;
}

int run_thread_unix(THREAD_UNIX * thread, int (*thread_ptr)(void*)) {
	//pthread_create(...);

	return 0;
}

int close_thread_unix(THREAD_UNIX * thread) {
	//close?(...);

	return 0;
}

int wait_thread_unix(THREAD_UNIX * thread) {
	//pthread_join(...);

	return 0;
}

int stop_thread_unix(THREAD_UNIX * thread) {
	//pthread_exit(...);

	return 0;
}

int pause_thread_unix(THREAD_UNIX * thread) {
	//pthread_suspend(...);

	return 0;
}

#else

#endif
