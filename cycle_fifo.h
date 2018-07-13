#ifndef __CYCLE_FIFO_H__
#define __CYCLE_FIFO_H__

#ifdef __cplusplus
extern "C"{
#endif

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#ifdef __cplusplus
};
#endif

//#include "log.h"

//32M
#define BUFFSIZE ((1024 * 1024) * 32)
#define min(x, y) ((x) < (y) ? (x) : (y))

//pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;


struct cycle_buffer {
    unsigned char *buf;
    unsigned int size;
    unsigned int in;
    unsigned int out;
    pthread_mutex_t lock;
};

#if 1
int cycle_buffer_init(struct cycle_buffer* cfifo);
void cycle_buffer_del(struct cycle_buffer* cfifo);
unsigned int fifo_get(char *buf, unsigned int len);
unsigned int fifo_put(char *buf, unsigned int len);
void * thread_read(void *arg);
void * thread_write(void *arg);

#else
extern "C" int cycle_buffer_init(struct cycle_buffer* cfifo);
extern "C" void cycle_buffer_del(struct cycle_buffer* cfifo);
extern "C" unsigned int fifo_get(unsigned char *buf, unsigned int len);
extern "C" unsigned int fifo_put(unsigned char *buf, unsigned int len);
extern "C" void * thread_read(void *arg);
extern "C" void * thread_write(void *arg);
#endif

#endif
