#include <stdlib.h>
#include "fence.h"

struct _fence_t {
    fence_t next;
    type_t type;
};

fence_t fence_P(){
    fence_t new_fence = NULL;
    return new_fence;
}
fence_t fence_add_P(fence_t fence){
    fence_t aux = fence;
    fence_t new_fence = malloc(sizeof(struct _fence_t));
    new_fence->next = NULL;
    new_fence->type = P;
    if(fence == NULL){
        fence = new_fence;
    }
    else{
        while(aux->next != NULL){
            aux = aux->next;
        }
        aux->next = new_fence;
    }
    return fence;
}
fence_t fence_add_A(fence_t fence){
    fence_t aux = fence;
    fence_t new_fence = malloc(sizeof(struct _fence_t));
    new_fence->next = NULL;
    new_fence->type = A;
    if(fence == NULL){
        fence = new_fence;
    }
    else{
        while(aux->next != NULL){
            aux = aux->next;
        }
        aux->next = new_fence;
    }
    return fence;
}
fence_t fence_add_H(fence_t fence){
    fence_t aux = fence;
    fence_t new_fence = malloc(sizeof(struct _fence_t));
    new_fence->next = NULL;
    new_fence->type = H;
    if(fence == NULL){
        fence = new_fence;
    }
    else{
        while(aux->next != NULL){
            aux = aux->next;
        }
        aux->next = new_fence;
    }
    return fence;
}
fence_t fence_add_T(fence_t fence){
    fence_t aux = fence;
    fence_t new_fence = malloc(sizeof(struct _fence_t));
    new_fence->next = NULL;
    new_fence->type = T;
    if(fence == NULL){
        fence = new_fence;
    }
    else{
        while(aux->next != NULL){
            aux = aux->next;
        }
        aux->next = new_fence;
    }
    return fence;
}
bool fence_is_correct(fence_t fence){
    fence_t current = fence;
    if(fence->type != P || fence_size(fence) < 3){
        return false;
    }
    else{
        fence_t previous = current;
        current = current->next;
        fence_t after = current->next;
        while(after != NULL){
            if(current->type != P){
                if(previous->type != P || after->type != P || after == NULL){
                    return false;
                }
            }
            previous = current;
            current = current->next;
            after = current->next;
        }
        if(current->type != P){
            return false;
        }
    }
    return true;
}
unsigned int fence_perimeter(fence_t fence){
    unsigned int perimeter = 0;
    fence_t aux = fence;
    while(aux != NULL){
        if(aux->type != P){
            perimeter += 3;
        }
        aux = aux->next;
    }
    return perimeter;
}
unsigned int fence_size(fence_t fence){
    unsigned int size = 0;
    fence_t aux = fence;
    while(aux != NULL){
        size++;
        aux = aux->next;
    }
    return size;
}
type_t *fence_to_array(fence_t fence){
    fence_t aux = fence;
    type_t *array = malloc(sizeof(type_t) * fence_size(fence));
    for (unsigned int i = 0; i < fence_size(fence); i++) {
        array[i] = aux->type;
        aux = aux->next;
    }
    return array;
}
fence_t fence_destroy(fence_t fence){
    fence_t aux = fence;
    while(aux != NULL){
        fence = fence->next;
        free(aux);
        aux = fence;
    }
    fence = NULL;
    return fence;
}