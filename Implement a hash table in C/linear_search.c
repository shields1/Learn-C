/*
*
*
* linear_search.c
*
* Let’s say you’re searching for the key bob in the following array (each item is a string key with an associated integer value):
*
* Index 0   1   2    3    4   5    6
* Key   foo bar bazz buzz bob jane x 
* Value 10  42  36  7     11  100  200
*/

#include <string.h>
#include <stdio.h>

typedef struct {
    char *key;
    int value;
} Item;

Item* linear_search(Item *items, size_t size, const char *key) {
    for (size_t i = 0; i < size; i++) {
        if (strcmp(items[i].key, key) == 0) {
            return &items[i];
        }
    }
    return NULL;
}

int main() {
    Item items[] = {
        {"foo", 10}, {"bar", 42}, {"bazz", 36}, {"buzz", 7},
        {"bob", 11}, {"jane", 100}, {"x", 200}};
    size_t num_items = sizeof(items) / sizeof(Item);

    Item *found = linear_search(items, num_items, "bob");
    if (found == NULL) {
        return 1;
    }
    printf("linear_search: value of 'bob' is %d\n", found->value);
    return 0;
}
