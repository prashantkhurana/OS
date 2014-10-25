typedef struct pthread_t {
}pthread_t;

int pthread_create(pthread_t *thread, const void *attr,
                          void *(*start_routine) (void *), void *arg);
//int thread_join(void);
//int thread_create(void *(*start_routine)(void*), void *arg);
// typedef struct _lock_t{
// uint flag;
// }lock_t;
// void lock_init(lock_t *);
// void lock_acquire(lock_t *);
// void lock_release(lock_t *)