#ifndef __STRFUNCS_H__
#define __STRFUNCS_H__

#include <stddef.h>

/*Calcula la longitu de la cadena apuntada por str*/
size_t string_length(const char *str);

/*Devuelve una cadena en memoria dinamica que se obtiene tomandolos caracteres de str que son distintos de c*/
char *string_filter(const char *str, char c);

#endif