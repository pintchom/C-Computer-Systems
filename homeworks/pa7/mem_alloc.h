#ifndef MEM_ALLOC_H
#define MEM_ALLOC_H

#include <stddef.h>  
#define PAGE_SIZE 4096   
#define WORD_SIZE 8      
#define SUCCESS 0       
#define FAILURE -1      

typedef struct Header {
    size_t size;               
    struct Header *next;      
    struct Header *previous;  
} Header;

static Header *free_list = NULL;

void *mem_alloc(size_t requested_size);
void mem_free(void *ptr);
int is_allocated(Header *header);
void set_allocated(Header *header);
void set_free(Header *header);
Header *get_header(void *mem);
int is_free(Header *header);
int same_page(Header *h1, Header *h2);
void print_list();
void print_header(Header *header);

#endif 
