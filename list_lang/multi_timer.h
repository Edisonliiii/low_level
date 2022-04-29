#ifndef _MULTI_TIMER_H_
#define _MULTI_TIMER_H_

#include "stddef.h"
#include "stdint.h"

typedef struct Timer {
  uint32_t timeout;
  uint32_t repeat;
  void (*timeout_cb)(void);
  struct Timer* next;
} Timer;

#ifdef __cplusplus
extern "C" {  // 该区段内不做name mangling
#endif

void timer_init(struct Timer* handle, void (*timeout_cb)(), uint32_t timeout,
                uint32_t repeat);
int timer_start(struct Timer* handler);
void timer_stop(struct Timer* handler);
void timer_ticks(void);
void timer_loop(void);

#ifdef __cplusplus
}
#endif

#endif