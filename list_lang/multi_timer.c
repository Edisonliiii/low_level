#include "multi_timer.h"
#include <string.h>
static struct Timer* head_handler = NULL;

static uint32_t _timer_ticks = 0;

void 
timer_init(struct Timer* handle, void(*timeout_cb)(), 
           uint32_t timeout, uint32_t repeat)
{
  memset(handle, 0, sizeof(struct Timer));
  handle->timeout_cb = timeout_cb;
  handle->timeout = _timer_ticks + timeout;
  handle->repeat = repeat;
}


/* 
 * @add handle to the head of the list
 */
int 
timer_start(struct Timer* handle)
{
  struct Timer* target = head_handler;
  while (target)
  {
  	if (target == handle) return -1;
  	target = target->next;
  }
  handle->next = head_handler;
  head_handler = handle;
  return 0;
}

void
timer_stop(struct Timer* handle)
{
  struct Timer** curr;
  for(curr=&head_handler; *curr;)
  {
    struct Timer* entry = *curr;
    if (entry==handle)
    {
      *curr = entry->next;
    } else {
      curr = &entry->next;
    }
  }
}

void
timer_loop()
{
  struct Timer* target;
  for (target = head_handler; target; target=target->next)
  {
    if (_timer_ticks >= target->timeout)
    {
      if (target->repeat == 0) timer_stop(target);
      else {
      	target->timeout = _timer_ticks + target->repeat;
      }
      target->timeout_cb();
    }
  }
}

void
timer_ticks()
{
  ++_timer_ticks;
}






