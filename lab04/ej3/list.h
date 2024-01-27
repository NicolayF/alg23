#ifndef _LIST_H
#define _LIST_H

#include <stdbool.h>

typedef int list_elem;
typedef struct _list * list;

list empty_list();

void addl(list l, list_elem e);

bool is_empty(list l);

list_elem head(list l);

list tail(list l);

list addr(list l, list_elem e);

unsigned int list_length(list l);

void concat(list l, list l0);

list_elem index(list l, unsigned int n);

void take(list l, unsigned int n);

void drop(list l, unsigned int n);

list copy_list(list l);

void destroy(list l);

#endif