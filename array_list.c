#include <stdlib.h>
#include <stdio.h>
#include "array_list.h"

#define INITIAL_CAPACITY 4

array_list *array_list_new(void) {
    array_list *list = malloc(sizeof(array_list));
    if (list == NULL) {
        return NULL;
    }

    list->data = malloc(sizeof(char *) * INITIAL_CAPACITY);
    if (list->data == NULL) {
        free(list);
        return NULL;
    }

    list->size = 0;
    list->capacity = INITIAL_CAPACITY;

    return list;
}

void array_list_add_to_end(array_list *list, char *value) {
    char **new_data;

    if (list == NULL) {
        return;
    }

    if (list->size >= list->capacity) {
        list->capacity = list->capacity * 2;
        new_data = realloc(list->data, sizeof(char *) * list->capacity);

        if (new_data == NULL) {
            fprintf(stderr, "realloc failed\n");
            exit(1);
        }

        list->data = new_data;
    }

    list->data[list->size] = value;
    list->size++;
}