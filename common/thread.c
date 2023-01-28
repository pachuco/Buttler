/*
	Threading library implementation.
*/

#include "thread.h"

THREAD *factory_create_thread()
{
	// return malloc.

	return 0;
}

int init_thread(THREAD *thread)
{
	return 0;
}

void *run_thread(THREAD *thread, unsigned long (*thread_ptr)(void *), void *parameter, int param_const)
{

	log_info(global_logger, "[Thread] Running thread, crossplatform...");

#if defined(WIN32) && !defined(UNIX)
	log_info(global_logger, "[Thread] Windows detected...");
	run_thread_win32(NULL, thread_ptr, parameter, param_const);
	// return run_thread_win32(thread->internal_thread, thread_ptr, parameter, param_const);
#elif defined(UNIX) && !defined(WIN32)
	return run_thread_unix(thread->internal_thread, thread_ptr, parameter, param_const);
#else
	// Unknown platform.
	// throw compiler error.
#endif

	return 0;
}

int close_thread(THREAD *thread)
{

#if defined(WIN32) && !defined(UNIX)
	return close_thread_win32(thread->internal_thread);
#elif defined(UNIX) && !defined(WIN32)
	return close_thread_unix(thread->internal_thread);
#else
	// Unknown platform.
	// throw compiler error.
#endif

	return 0;
}

int wait_thread(THREAD *thread)
{

#if defined(WIN32) && !defined(UNIX)
	return wait_thread_win32(thread->internal_thread);
#elif defined(UNIX) && !defined(WIN32)
	return wait_thread_unix(thread->internal_thread);
#else
	// Unknown platform.
	// throw compiler error.
#endif

	return 0;
}

int stop_thread(THREAD *thread)
{
#if defined(WIN32) && !defined(UNIX)
	return stop_thread_win32(thread->internal_thread);
#elif defined(UNIX) && !defined(WIN32)
	return stop_thread_unix(thread->internal_thread);
#else
	// Unknown platform.
	// throw compiler error.
#endif

	return 0;
}

int pause_thread(THREAD *thread)
{
#if defined(WIN32) && !defined(UNIX)
	return pause_thread_win32(thread->internal_thread);
#elif defined(UNIX) && !defined(WIN32)
	return pause_thread_unix(thread->internal_thread);
#else
	// Unknown platform.
	// throw compiler error.
#endif

	return 0;
}

// separate these in two distinctive files.

// Win32 Impl. ========================================

#if defined(WIN32) && !defined(UNIX)

THREAD_WIN32 *factory_create_thread_win32()
{
	// return malloc

	return 0;
}

int init_thread_win32(THREAD_WIN32 *thread)
{
	return 0;
}

void *run_thread_win32(THREAD_WIN32 *thread, unsigned long (*thread_ptr)(void *), void *parameter, int param_const)
{

	log_info(global_logger, "[Thread] Calling CreateThread...");

	return CreateThread(NULL, 0, thread_ptr, parameter, 0, NULL);

	// return 0;
}

int close_thread_win32(THREAD_WIN32 *thread)
{
	// CloseHandle?(...)

	return 0;
}

int wait_thread_win32(THREAD_WIN32 *thread)
{
	// WaitForSingleObject(...);

	return 0;
}

int stop_thread_win32(THREAD_WIN32 *thread)
{
	// TerminateThread(...);

	return 0;
}

int pause_thread_win32(THREAD_WIN32 *thread)
{
	// SuspendThread(...);

	return 0;
}

#elif defined(UNIX) && !defined(WIN32)

// Unix Impl. ========================================

THREAD_UNIX *factory_create_thread_unix()
{
	// return malloc

	return NULL;
}

int init_thread_unix(THREAD_UNIX *thread)
{
	return 0;
}

void *run_thread_unix(THREAD_UNIX *thread, unsigned int (*thread_ptr)(void *), void *parameter, int param_const)
{
	// pthread_create(...);

	return 0;
}

int close_thread_unix(THREAD_UNIX *thread)
{
	// close?(...);

	return 0;
}

int wait_thread_unix(THREAD_UNIX *thread)
{
	// pthread_join(...);

	return 0;
}

int stop_thread_unix(THREAD_UNIX *thread)
{
	// pthread_exit(...);

	return 0;
}

int pause_thread_unix(THREAD_UNIX *thread)
{
	// pthread_suspend(...);

	return 0;
}

#else

#endif
