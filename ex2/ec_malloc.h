//
// Created by codeninja on 8/01/18.
//
#include <iostream>

#ifndef EC_MALLOC_H
#define EC_MALLOC_H
#endif

// An error-checked malloc() wrapper function
void *ec_malloc(unsigned int size)
{
    void *ptr;
    ptr = malloc(size);
    if (ptr == NULL)
        std::cout<<"[DEBUG] Err in EC_MALLOC() on Memory Allocation"<<std::endl;
    return ptr;
}
