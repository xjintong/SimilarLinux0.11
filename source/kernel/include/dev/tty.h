#ifndef TTY_H
#define TTY_H

#include "ipc/sem.h"
#define TTY_NR              8           // 最大支持的tty设备数量

#define TTY_OBUF_SIZE       512         // tty输入缓存大小
#define TTY_IBUF_SIZE       512         // tty输出缓存大小

typedef struct _tty_fifo_t {
    char * buf;
    int size;           // 最大字节数
    int read, write;    // 当前读写位置
    int count;          // 当前已有的数据量
}tty_fifo_t;    

#define TTY_OCRLF   (1 << 0)

#define TTY_INCLR   (1 << 0)        // 将\n转成\r\n
#define TTY_IECHO   (1 << 1)        // 是否回显

// tty设备
typedef struct _tty_t {
    char obuf[TTY_OBUF_SIZE];
    tty_fifo_t ofifo;
    sem_t osem;     // 输出信号量
    char ibuf[TTY_IBUF_SIZE];
    tty_fifo_t ififo;
    sem_t isem;

    int iflags;
    int oflags;
    int console_idx;
}tty_t;

int tty_fifo_put (tty_fifo_t *fifo, char c);
int tty_fifo_get (tty_fifo_t *fifo, char * c);

void tty_select (int tty);
void tty_in(char ch);

#endif