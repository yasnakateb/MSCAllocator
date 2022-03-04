#include <stdio.h>
#include <string.h>
#include "../include/mscalloc.h"

int main(int argc,char *argv[]){

    memory_space p;
    create_memory_space(&p,4,4);
    int *d=msc_alloc(&p);
    *d=32;
    printf("%d\n",*d);
    float *f=msc_alloc(&p);
    *f=312.5;
    printf("%f\n",*f);
    msc_free(&p,d);
    msc_free(&p,f);
    delete_memory_space(&p);

    return 0;
}
