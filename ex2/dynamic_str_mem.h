//
// Created by codeninja on 21/03/18.
//

#include <cstring>
#include <stdio>
#include <stdlib>
#include "ec_malloc.h"

#ifndef DYNAMIC_STR_MEM_H
#define DYNAMIC_STR_MEM_H
#endif

void *ec_malloc(unsigned int);

char *dynamic_str_mem(char *str)
{
    int i=0;
    char c;
    char *str;
    str = (char *) ec_malloc(sizeof(char));
    

}
