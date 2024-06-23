#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "history.h"

/* Initialize the linked list to keep the history. */
List* init_history(void) {
    List *list = (List*)malloc(sizeof(List));
    if (!list) {
        perror("Failed to initialize history");
        exit(EXIT_FAILURE);
    }
    list->root = NULL;
    return list;
}

/* Add a history item to the end of the list. */
void add_history(List *list, char *str) {
    static int id_counter = 1;
    Item *new_item = (Item*)malloc(sizeof(Item));
    if (!new_item) {
        perror("Failed to add history item");
        exit(EXIT_FAILURE);
    }
    new_item->id = id_counter++;
    new_item->str = strdup(str);
    new_item->next = NULL;

    if (!list->root) {
        list->root = new_item;
    } else {
        Item *current = list->root;
        while (current->next) {
            current = current->next;
        }
        current->next = new_item;
    }
}

/* Retrieve the string stored in the node where Item->id == id. */
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

/* Print the entire contents of the list. */
void print_history(List *list) {
    Item *current = list->root;
    while (current) {
        printf("%d: %s\n", current->id, current->str);
        current = current->next;
    }
}

/* Free the history list and the strings it references. */
void free_history(List *list) {
    Item *current = list->root;
    while (current) {
        Item *next = current->next;
        free(current->str);
        free(current);
        current = next;
    }
    free(list);
}
