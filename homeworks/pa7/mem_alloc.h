#ifndef MEM_ALLOC_H
#define MEM_ALLOC_H

#include <stddef.h>  
#define PAGE_SIZE 4096   
#define WORD_SIZE 8      
#define SUCCESS 0       
#define FAILURE -1      

typedef struct Header {
    struct Header *next;      
    struct Header *previous;
    size_t size;                   
} Header;

static Header * free_list = NULL;

int mem_init();
int mem_extend(Header * last);
void * mem_alloc(size_t requested_size);
void mem_free(void * ptr);

#endif 
