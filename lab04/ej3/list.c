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
    list new_node = malloc(sizeof(list));
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

void tail(list l) {
    assert(!is_empty(l));
    list aux = l;
    l = aux->next;
    free(aux);
    aux = NULL;
}

void destroy(list l) {
    while(!is_empty(l)) {
        tail(l);
    }
}

void addr(list l, list_elem e) {
    list q,r;
    q = malloc(sizeof(list));
    q->elem = e;
    q->next = NULL;
    if(l == NULL) {
        l = q;
    }
    else {
        r = l;
        while(r->next != NULL) {
            r = r->next;
        }
        r->next = q;
    }
}

unsigned int length(list l) {
    unsigned int count = 0;
    list r = l;
    while(r->next != NULL) {
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
    assert(length(l) > n);
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
    list new_list = empty_list();
    list r = l;
    while(r->next != NULL) {
        addr(new_list, r->elem);
        r = r->next;
    }
    return new_list;
}