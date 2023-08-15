#include "lib_syscall.h"
#include "stdio.h"

char cmd_buf[256];
int main(int argc, char ** argv) {
#if 0
    sbrk(0);
    sbrk(100);
    sbrk(200);
    sbrk(4096*2 + 200);
    sbrk(4096*5 + 1234);

    printf("abef\b\b\b\bcd\n");     // cdef  \b 是光标左移1位，
    printf("abcd\x7f;fg\n");        // abc;fg
    printf("\0337Hello, world!\0338123\n");   // 123lo,world
    printf("\033[31;42mHello,world!\033[39;49m123\n");

    printf("123\033[2DHello,word!\n");  // 光标左移2，1Hello,word!
    printf("123\033[2CHello,word!\n");  // 光标右移2，123  Hello,word!

    printf("\033[31m\n");  // ESC [pn m, Hello,world红色，其余绿色
    printf("\033[10;10H test!\n");  // 定位到10, 10，test!
    printf("\033[20;20H test!\n");  // 定位到20, 20，test!
    printf("\033[32;25;39m123\n");  // ESC [pn m, Hello,world红色，其余绿色 

    printf("\033[2J\n");   // clear screen
#endif
    open("tty:0", 0);           // int fd = 0   stdin 三个都是指向同一个tty设备，tty0，只是在进程的 文件表中，fd不一样。  => tty0
    dup(0);                     // int fd = 1   stdout  => tty0
    dup(0);                     // int fd = 2   stdeer  => tty0

    printf("Hello from shell\n");
    printf("OsTest\n");
    fprintf(stderr, "error");

    for (;;) {
        gets(cmd_buf);
        puts(cmd_buf);

        // printf("shell pid=%d\n", getpid());
        // msleep(1000);

    }
}