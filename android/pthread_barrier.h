/*
 * Bionic on Froyo doens't have pthread barriers.
 *
 * Copied from http://www.howforge.com/implementing-barrier-in-pthreads
 */

#ifndef PTHREAD_BARRIER_H_
#define PTHREAD_BARRIER_H_

typedef struct {
    int needed;
    int called;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
} pthread_barrier_t;

int pthread_barrier_init(pthread_barrier_t *barrier, void *dummy, int needed);
int pthread_barrier_destroy(pthread_barrier_t *barrier);
int pthread_barrier_wait(pthread_barrier_t *barrier);

#endif /* PTHREAD_BARRIER_H_ */
