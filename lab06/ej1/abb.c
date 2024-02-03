#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "abb.h"

struct _s_abb {
    abb_elem elem;
    struct _s_abb *left;
    struct _s_abb *right;
};

static bool elem_eq(abb_elem a, abb_elem b) {
    return a == b;
}

static bool elem_less(abb_elem a, abb_elem b) {
    return a < b;
}

static bool check_greater(abb_elem e, abb tree) {
    bool greater = true;
    if(tree != NULL){
        greater = elem_less(tree->elem, e) && check_greater(e, tree->left) && check_greater(e, tree->right);
    }
    return greater;
}

static bool check_smaller(abb_elem e, abb tree) {
    bool smaller = true;
    if(tree != NULL){
        smaller = elem_less(e, tree->elem) && check_smaller(e, tree->left) && check_smaller(e, tree->right);
    }
    return smaller;
}

static bool invrep(abb tree) {
    bool valid = true;
    if (tree == NULL) {
        return true;
    }
    else {
        valid = check_greater(tree->elem, tree->left) &&
                check_smaller(tree->elem, tree->right) &&
                invrep(tree->left) && invrep(tree->right);
    }
    return valid;
}

abb abb_empty(void) {
    abb tree = NULL;
    assert(invrep(tree) && abb_is_empty(tree));
    return tree;
}

abb abb_add(abb tree, abb_elem e) {
    assert(invrep(tree));
    if (tree == NULL) {
        tree = malloc(sizeof(struct _s_abb));
        tree->elem = e;
        tree->left = NULL;
        tree->right = NULL;
    }
    else if (elem_less(e, tree->elem)) {
        tree->left = abb_add(tree->left, e);
    }
    else if (elem_less(tree->elem, e)) {
        tree->right = abb_add(tree->right, e);
    }
    assert(invrep(tree) && abb_exists(tree, e));
    return tree;
}

bool abb_is_empty(abb tree) {
    assert(invrep(tree));
    return tree == NULL;
}

bool abb_exists(abb tree, abb_elem e) {
    bool exists=false;
    assert(invrep(tree));
    if (tree == NULL) {
        exists = false;
    }
    else if (elem_eq(e, tree->elem)) {
        exists = true;
    }
    else if (elem_less(e, tree->elem)) {
        exists = abb_exists(tree->left, e);
    }
    else if (elem_less(tree->elem, e)) {
        exists = abb_exists(tree->right, e);
    }
    return exists;
}

unsigned int abb_length(abb tree) {
    unsigned int length=0;
    assert(invrep(tree));
    if (tree == NULL) {
        length = 0;
    }
    else {
        length = 1 + abb_length(tree->left) + abb_length(tree->right);
    }
    assert(invrep(tree) && (abb_is_empty(tree) || length > 0));
    return length;
}

abb abb_remove(abb tree, abb_elem e) {
    assert(invrep(tree));
    if (tree == NULL) {
        return tree;
    }
    else if (elem_less(e, tree->elem)) {
        tree->left = abb_remove(tree->left, e);
    }
    else if (elem_less(tree->elem, e)) {
        tree->right = abb_remove(tree->right, e);
    }
    else if (elem_eq(e, tree->elem)) {
        if (tree->left == NULL && tree->right == NULL) {
            free(tree);
            tree = NULL;
        }
        else if (tree->left == NULL) {
            tree = tree->right;
        }
        else if (tree->right == NULL) {
            tree = tree->left;
        }
        else {
            tree->elem = abb_min(tree->right);
            tree->right = abb_remove(tree->right, tree->elem);
        }
    }
    assert(invrep(tree) && !abb_exists(tree, e));
    return tree;
}


abb_elem abb_root(abb tree) {
    abb_elem root;
    assert(invrep(tree) && !abb_is_empty(tree));
    root = tree->elem;
    assert(abb_exists(tree, root));
    return root;
}

abb_elem abb_max(abb tree) {
    abb_elem max_e;
    abb temp = tree;
    assert(invrep(tree) && !abb_is_empty(tree));
    while(temp->right != NULL){
        temp = temp->right;
    }
    max_e = temp->elem;
    assert(invrep(tree) && abb_exists(tree, max_e));
    return max_e;
}

abb_elem abb_min(abb tree) {
    abb_elem min_e;
    abb temp = tree;
    assert(invrep(tree) && !abb_is_empty(tree));
    while(temp->left != NULL){
        temp = temp->left;
    }
    min_e = temp->elem;
    assert(invrep(tree) && abb_exists(tree, min_e));
    return min_e;
}

void abb_dump(abb tree) {
    assert(invrep(tree));
    if (tree != NULL) {
        abb_dump(tree->left);
        printf("%d ", tree->elem);
        abb_dump(tree->right);
    }
}

abb abb_destroy(abb tree) {
    assert(invrep(tree));
    if (tree !=  NULL) {
        tree->left = abb_destroy(tree->left);
        tree->right = abb_destroy(tree->right);
        free(tree);
        tree = NULL;
    }
    assert(tree == NULL);
    return tree;
}

