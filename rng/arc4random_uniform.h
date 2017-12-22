#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h>
//#include "arc4random.h"

extern uint32_t arc4random(void);
extern void arc4random_buf(void *buf, size_t n);
uint32_t arc4random_uniform(uint32_t upper_bound);
