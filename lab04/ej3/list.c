#include "list.h"
#include <stdlib.h>
#include <assert.h>

struct _list {
    list_elem elem;
    list next;
};

list empty_list() {
    list new_list = NULL;
    return new_list;
}

void addl(list l, list_elem e) {
    list new_node = malloc(sizeof(struct _list));
    new_node->elem = e;
    new_node->next = l->next;
    l = new_node;
}

bool is_empty(list l) {
    return l == NULL;
}

list_elem head(list l) {
    assert(!is_empty(l));
    return l->elem;
}

list tail(list l) {
    assert(!is_empty(l));
    list aux = l;
    l = l->next;
    free(aux);
    aux = NULL;
    return l;
}

void destroy(list l) {
    list r = l;
    while(l != NULL) {
        l = l->next;
        free(r);
        r = l;  
    }
}

list addr(list l, list_elem e) {
    list q = empty_list();
    list r = empty_list();
    r = l;
    q = malloc(sizeof(struct _list));
    q->elem = e;
    q->next = NULL;
    if(l == NULL) {
        l = q;
    }
    else {
        //r = l;
        while(r->next != NULL) {
            r = r->next;
        }
        r->next = q;
    }
    return l;
}

unsigned int list_length(list l) {
    unsigned int count = 0;
    list r = empty_list();
    r = l;
    while(r != NULL) {
        r = r->next;
        count++;
    }
    return count;
}

void concat(list l, list l0) {
    list r = l;
    while(r->next != NULL) {
        r = r->next;
    }
    r = l0;
}

list_elem index(list l, unsigned int n) {
    assert(list_length(l) > n);
    list r = l;
    for (unsigned int i = 0; i < n; i++) {
        r = r->next;
    }
    return r->elem;
}

void take(list l, unsigned int n) {
    list r = l;
    for (unsigned int i = 0; i < n; i++) {
        r = r->next;
    }
    destroy(r);
}

void drop(list l, unsigned int n) {
    for (unsigned int i = 0; i < n; i++) {
        tail(l);
    }
}

list copy_list(list l) {
    list copy_list = empty_list();
    list r = empty_list(); 
    r = l;
    while(r != NULL) {
        copy_list = addr(copy_list, r->elem);
        r = r->next;
    }
    return copy_list;
}