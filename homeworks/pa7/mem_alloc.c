#include "mem_alloc.h"
#include <sys/mman.h> 
#include <unistd.h>    
#include <string.h>

int mem_init() {

    // Initializing page of memory
    void *page = mmap(NULL, PAGE_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    if (page == MAP_FAILED) { // Error checking 
        return FAILURE;
    }

    free_list = (Header *)page;
    free_list->size = PAGE_SIZE - sizeof(Header);
    free_list->next = NULL;
    free_list->previous = NULL;
    return SUCCESS;
}

int mem_extend(Header *last) {
    void *page = mmap(NULL, PAGE_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (page == MAP_FAILED) {
        return FAILURE;
    }

    Header *new_block = (Header *)page;
    new_block->size = PAGE_SIZE - sizeof(Header);
    new_block->next = NULL;
    new_block->previous = last;

    if (last != NULL) {
        last->next = new_block;
    }

    return SUCCESS;
}

void *mem_alloc(size_t requested_size) {
    if (requested_size == 0 || requested_size > PAGE_SIZE - sizeof(Header)) {
        return NULL;  
    }
    if (free_list == NULL) {
        if (mem_init() == FAILURE) {
            return NULL; 
        }
    }
    size_t aligned_size = (requested_size + (WORD_SIZE - 1)) & ~(WORD_SIZE - 1);
    Header *current = free_list;
    Header *prev = NULL;

    while (current != NULL) {
        if (!is_allocated(current) && current->size >= aligned_size) {
            if (current->size > aligned_size + sizeof(Header)) {
                Header *new_block = (Header *)((char *)current + sizeof(Header) + aligned_size);
                new_block->size = current->size - aligned_size - sizeof(Header);
                new_block->next = current->next;
                new_block->previous = current;
                
                if (current->next) {
                    current->next->previous = new_block;
                }
                current->size = aligned_size;
                current->next = new_block;
            }

            set_allocated(current);
            return (void *)((char *)current + sizeof(Header));
        }
        prev = current;
        current = current->next;
    }

    if (mem_extend(prev) == FAILURE) {
        return NULL;
    }

    current = prev->next;
    current->size = aligned_size;
    set_allocated(current);

    return (void *)((char *)current + sizeof(Header));

}

//void mem_free(void *ptr) {
    
//}


