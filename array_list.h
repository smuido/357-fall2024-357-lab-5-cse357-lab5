#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

typedef struct {
    char **data;
    int size;
    int capacity;
} array_list;

array_list *array_list_new(void);
void array_list_add_to_end(array_list *list, char *value);

#endif