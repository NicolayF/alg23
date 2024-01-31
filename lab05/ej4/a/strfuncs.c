#include "strfuncs.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

size_t string_length(const char *str){
    unsigned int i = 0;
    while(str[i]!= '\0'){
        i++;
    }
    return i;
}

char *string_filter(const char *str, char c){
    unsigned int i = 0;
    unsigned int j = 0;
    char *new_str = malloc(sizeof(char) * string_length(str) + 1);
    while(str[i]!= '\0'){
        if(str[i]!= c){
            new_str[j] = str[i];
            j++;
        }
        i++;
    }
    new_str[i] = '\0';
    return new_str;
}