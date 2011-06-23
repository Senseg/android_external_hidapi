#include "android/pthread_barrier.h"
#include "hidapi/hidapi.h"

/* Implementation of wcsdup() for Android. */
static inline wchar_t *wcsdup(const wchar_t *s) {
	size_t len = wcslen(s);
	wchar_t *ret = malloc((len+1)*sizeof(wchar_t));
	wcscpy(ret, s);

	return ret;
}


