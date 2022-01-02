#include <stdio.h>
#include <string.h>
#include "../include/allocator.h"

int main(int argc,char *argv[]){

    memory_space p;
    create_memory_space(&p,4,4);
    int *d=ms_alloc(&p);
    *d=32;
    printf("%d\n",*d);
    float *f=ms_alloc(&p);
    *f=312.5;
    printf("%f\n",*f);
    ms_free(&p,d);
    ms_free(&p,f);
    delete_memory_space(&p);

    return 0;
}
