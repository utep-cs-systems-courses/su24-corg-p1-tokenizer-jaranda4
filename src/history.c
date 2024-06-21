#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "history.h"

List* init_history() {
    List *list = (List*)malloc(sizeof(List));
    list->root = NULL;
    return list;
}

void add_history(List *list, char *str) {
    Item *new_item = (Item*)malloc(sizeof(Item));
    new_item->id = (list->root == NULL) ? 1 : list->root->id + 1;
    new_item->str = strdup(str);
    new_item->next = list->root;
    list->root = new_item;
}

char *get_history(List *list, int id) {
    Item *current = list->root;
    while (current) {
        if (current->id == id) {
            return current->str;
        }
        current = current->next;
    }
    return NULL;
}

void print_history(List *list) {
    Item *current = list->root;
    while (current) {
        printf("History %d: %s\n", current->id, current->str);
        current = current->next;
    }
}

void free_history(List *list) {
    Item *current = list->root;
    while (current) {
        Item *temp = current;
        current = current->next;
        free(temp->str);
        free(temp);
    }
    free(list);
}
