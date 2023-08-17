#ifndef FILE_H
#define FILE_H

#include "comm/types.h"

#define FILE_NAME_SIZE      32
#define FILE_TABLE_SIZE     2048

// 文件类型
typedef enum _file_type_t {
    FILE_UNKNOWN = 0,
    FILE_TTY,
}file_type_t;

struct _fs_t;
// 文件描述符
typedef struct  _file_t {
    char file_name[FILE_NAME_SIZE];     // 文件名
    file_type_t type;           // 文件类型
    uint32_t size;              // 文件大小
    int ref;                    // 引用次数
    int dev_id;                 // 文件所属的设备号 
    int pos;  	                // 当前位置
    int mode;					// 读写模式

    struct _fs_t * fs;
}file_t;


file_t * file_alloc (void);
void file_free (file_t * file);
void file_table_init (void);
void file_inc_ref (file_t * file);

#endif