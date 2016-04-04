/*
	The MIT License (MIT)

	Copyright (c) 2016 AaronKow

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in
	all copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
	THE SOFTWARE.
*/

#ifndef WATER_FLOW_H_
#define WATER_FLOW_H_

#include <pthread.h>
#include <stdbool.h>
#include <sys/time.h>
#include "interrupt.h"

struct gpio_struct {
	unsigned int gpio;
};
struct timeval currentTime, oldTime;

volatile int pulse_count;
unsigned int ml;							// millilitre
unsigned long ml_total;						// total millilitre
float elapsed, calibration_factor, flow_rate;
float timedifference_msec(struct timeval t0, struct timeval t1);

void flow(void);
void *get_water_sensor(void *arguments);
void *interrupt_func(void *arguments);

#endif