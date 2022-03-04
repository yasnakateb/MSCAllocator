#include "../include/allocator.h"

uint8_t* get_address(memory_space *space,uint32_t index){
    return space->memory_start+(index*space->block_size);
}

uint32_t get_index(memory_space *space,uint8_t* address){
  return ((uint32_t)(address-space->memory_start))/space->block_size;
}

void* msc_alloc(memory_space *space){

    void *ret_val=NULL;
    if(space->number_of_initialized_blocks<space->number_of_blocks)
    {
        uint8_t *address=get_address(space,space->number_of_initialized_blocks);
        *address=space->number_of_initialized_blocks+1;
        space->number_of_initialized_blocks++;
    }

    if(space->number_of_free_blocks>0)
    {
        ret_val=(void*)space->memory_next;
        space->number_of_free_blocks--;

        if(space->number_of_free_blocks!=0)
        {
            space->memory_next=get_address(space,*((uint8_t*)space->memory_next));
        }

        else
        {
            space->memory_next=NULL;
        }
        
    }
    return ret_val;  
}

void msc_free(memory_space *space,void *address){

    if(space->memory_next!=NULL)
    {
        (*(uint8_t*)address)=get_index(space,space->memory_next);
        space->memory_next=(uint8_t*)address;
    }
    else
    {
        *((uint8_t*)address)=space->number_of_blocks;
        space->memory_next=(uint8_t*)address;
    }
    space->number_of_free_blocks++;
}

void create_memory_space(memory_space *space,size_t block_size,uint32_t number_of_blocks){
  space->number_of_blocks=number_of_blocks;
  space->block_size=block_size;
  space->memory_start=malloc(block_size*number_of_blocks*sizeof(uint8_t));
  space->number_of_free_blocks=number_of_blocks;
  space->number_of_initialized_blocks=0;
  space->memory_next=space->memory_start;
}

void delete_memory_space(memory_space *space){
  free(space->memory_start);
  space->memory_start=NULL;
}



