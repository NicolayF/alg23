#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "sorted_list.h"
//#include "list.h"

struct _node{
    elem_t value;
    struct _node *next;
};

sorted_list_t sorted_list_empty()
{
    sorted_list_t empty_list = NULL;
    return empty_list;
}

bool sorted_list_is_empty(sorted_list_t list)
{
	return list == NULL;
}

elem_t sorted_list_head(sorted_list_t list)
{
    assert(!sorted_list_is_empty(list));
	return list->value;
}

sorted_list_t sorted_list_append(sorted_list_t list, elem_t elem)
{
    sorted_list_t aux = list;
    sorted_list_t new_node = malloc(sizeof(struct _node));
    new_node->value = elem;
    new_node->next = NULL;

    if(list == NULL || list->value > new_node->value){
        new_node->next = list;
        list = new_node;
        return list;
    }
    while(aux->next!= NULL && aux->next->value < new_node->value){
        aux = aux->next;
    }
    new_node->next = aux->next;
    aux->next = new_node;
    return list;
}

sorted_list_t sorted_list_tail(sorted_list_t list)
{
    sorted_list_t aux = list;
    if(list!=NULL){
        list = aux->next;
        free(aux);
    }
    return list;
}

unsigned int sorted_list_length(sorted_list_t list)
{
    unsigned int length = 0;
    sorted_list_t aux = list;
    while(aux != NULL){
        length++;
        aux = aux->next;
    }
    return length;
}

elem_t sorted_list_elem_at(sorted_list_t list, unsigned int index)
{
    sorted_list_t aux = list;
    unsigned int i = 0;
    while(aux != NULL && i < index){
        aux = aux->next;
        i++;
    }
    return aux->value;
}

sorted_list_t sorted_list_take(sorted_list_t list, unsigned int num)
{
    sorted_list_t aux = list;
    sorted_list_t new_list = NULL;
    unsigned int i = 0;
    while(i < num){
        new_list = sorted_list_append(new_list, aux->value);
        aux = aux->next;
        i++;
    }
    return new_list;
}

sorted_list_t sorted_list_drop(sorted_list_t list, unsigned int num)
{
    sorted_list_t aux = list;
    sorted_list_t new_list = NULL;
    unsigned int i = 0;
    while(i < num){
        aux = aux->next;
        i++;
    }
    while(aux != NULL){
        new_list = sorted_list_append(new_list, aux->value);
        aux = aux->next;
    }
    return new_list;
}

void sorted_list_print(sorted_list_t list)
{
    sorted_list_t aux = list;
    printf("[");
    while(aux!= NULL){
        printf("%d ", aux->value);
        aux = aux->next;
    }
    printf("]");
}

sorted_list_t sorted_list_destroy(sorted_list_t list)
{
    sorted_list_t aux = list;
    while(aux!= NULL){
        list = aux->next;
        free(aux);
        aux = list;
    }
    list = NULL;
    return list;
}
