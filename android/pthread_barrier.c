/*
 * Bionic on Froyo doens't have pthread barriers.
 *
 * Copied from http://www.howforge.com/implementing-barrier-in-pthreads
 */

#include <pthread.h>
#include <pthread_barrier.h>

int pthread_barrier_init(pthread_barrier_t *barrier,
			 void *dummy __attribute__((__unused__)),
			 int needed)
{
    barrier->needed = needed;
    barrier->called = 0;
    pthread_mutex_init(&barrier->mutex, NULL);
    pthread_cond_init(&barrier->cond, NULL);
    return 0;
}

int pthread_barrier_destroy(pthread_barrier_t *barrier)
{
    pthread_mutex_destroy(&barrier->mutex);
    pthread_cond_destroy(&barrier->cond);
    return 0;
}

int pthread_barrier_wait(pthread_barrier_t *barrier)
{
    pthread_mutex_lock(&barrier->mutex);
    barrier->called++;
    if (barrier->called == barrier->needed) {
        barrier->called = 0;
        pthread_cond_broadcast(&barrier->cond);
    } else {
        pthread_cond_wait(&barrier->cond, &barrier->mutex);
    }
    pthread_mutex_unlock(&barrier->mutex);
    return 0;
}
