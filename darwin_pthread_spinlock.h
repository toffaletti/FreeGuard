#ifndef DARWIN_PTHREAD_SPINLOCK_H
#define DARWIN_PTHREAD_SPINLOCK_H

#ifdef __APPLE__
#include <errno.h>
#include <libkern/OSAtomic.h>

typedef OSSpinLock pthread_spinlock_t;

static inline int pthread_spin_init(pthread_spinlock_t *lock, int pshared) {
  *lock = 0;
  return 0;
}

static inline int pthread_spin_destroy(pthread_spinlock_t *lock) { return 0; }

static inline int pthread_spin_lock(pthread_spinlock_t *lock) {
  OSSpinLockLock(lock);
  return 0;
}

static inline int pthread_spin_trylock(pthread_spinlock_t *lock) {
  return OSSpinLockTry(lock) ? 0 : EBUSY;
}

static inline int pthread_spin_unlock(pthread_spinlock_t *lock) {
  OSSpinLockUnlock(lock);
  return 0;
}

#endif // __APPLE__

#endif // DARWIN_PTHREAD_SPINLOCK_H
