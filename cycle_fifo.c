#include "cycle_fifo.h"

extern FILE* log_fd;
static struct cycle_buffer *fifo = NULL;

//初始化队列
int cycle_buffer_init(struct cycle_buffer* cfifo)
{
    int size = BUFFSIZE, ret;
    if(NULL == cfifo)
    {
        return -1;
    }

    ret = size & (size - 1);
    if (ret)
        return ret;

    fifo = cfifo;

    memset(fifo, 0, sizeof(struct cycle_buffer));
    fifo->size = size;
    fifo->in = fifo->out = 0;
    pthread_mutex_init(&fifo->lock, NULL);

    fifo->buf = (unsigned char *) malloc(size);
    if (fifo->buf == NULL)
    {
        free(fifo);
        return -1;
    }

    memset(fifo->buf, 0, size);
    return 0;
}


void cycle_buffer_del(struct cycle_buffer* cfifo)
{

    if(cfifo && cfifo->buf)
    {
        free(cfifo->buf);
    }

    fifo = NULL;
}


unsigned int fifo_get(char *buf, unsigned int len)
{
    unsigned int l;
    pthread_mutex_lock(&fifo->lock);
    len = min(len, fifo->in - fifo->out);
    l = min(len, fifo->size - (fifo->out & (fifo->size - 1)));


    memcpy(buf, fifo->buf + (fifo->out & (fifo->size - 1)), l);
    memcpy(buf + l, fifo->buf, len - l);
    fifo->out += len;
    pthread_mutex_unlock(&fifo->lock);
    return len;
}


unsigned int fifo_put(char *buf, unsigned int len)
{
    unsigned int l;
    pthread_mutex_lock(&fifo->lock);

    len = min(len, fifo->size - fifo->in + fifo->out);
    l = min(len, fifo->size - (fifo->in & (fifo->size - 1)));


    memcpy(fifo->buf + (fifo->in & (fifo->size - 1)), buf, l);
    memcpy(fifo->buf, buf + l, len - l);
    fifo->in += len;
    pthread_mutex_unlock(&fifo->lock);
    return len;
}


