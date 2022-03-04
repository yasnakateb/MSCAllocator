#include <stdlib.h>
#include <stdint.h>

#ifndef __ALLOCATOR__
#define __ALLOCATOR__ 

typedef struct memory_space{
    uint8_t  *memory_start;
    uint8_t  *memory_next;
    uint32_t block_size;
    uint32_t number_of_free_blocks;
    uint32_t number_of_initialized_blocks;
    uint32_t number_of_blocks;
   
} memory_space;


uint8_t* get_address(memory_space *space,uint32_t index);
uint32_t get_index(memory_space *space,uint8_t* address);
void* msc_alloc(memory_space *space);
void msc_free(memory_space *space,void *address);
void create_memory_space(memory_space *space,size_t block_size,uint32_t number_of_blocks);
void delete_memory_space(memory_space *space);

#endif
