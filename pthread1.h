//  typedef unsigned long int pthread_t;
// 
// 
// typedef struct mutex{
// int flag;
// int id;
// } pthread_mutex_t;
// 
// 
// 
// int pthread_create(pthread_t *thread, const void *attr,
//                           void (*func)(void*), void *arg);
// 
// //void *(*start_routine) (void *)
// int pthread_mutex_init(pthread_mutex_t *mutex,
// 			const void *attr);
// 
// int pthread_join(pthread_t thread, void **value_ptr);
// 
// int pthread_mutex_lock(pthread_mutex_t *mutex);
// 
// int pthread_mutex_unlock(pthread_mutex_t *mutex);
// 
// 
// //int thread_join(void);
// //int thread_create(void *(*start_routine)(void*), void *arg);
// // typedef struct _lock_t{
// // uint flag;
// // }lock_t;
// // void lock_init(lock_t *);
// // void lock_acquire(lock_t *);
// // void lock_release(lock_t *)