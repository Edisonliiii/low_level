#include <stdio.h>

#include "multi_timer.h"
struct Timer timer1;
struct Timer timer2;

void timer1_callback() { printf("Timer1 timeout!\r\n"); }

void timer2_callback() { printf("Timer2 timeout!\r\n"); }

int main(int argc, char const *argv[]) {
  timer_init(&timer1, timer1_callback, 1000, 1000);
  timer_start(&timer1);

  timer_init(&timer2, timer2_callback, 50, 0);
  timer_start(&timer2);

  while (1) timer_loop();
}

void HAL_SYSTICK_Callback(void) { timer_ticks(); }