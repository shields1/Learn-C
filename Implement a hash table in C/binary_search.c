/*
*
* binary_search.c
*
* Assume we’re looking up bob again (in this pre-sorted array):
* Index 0   1    2   3    4   5    6
* Key   bar bazz bob buzz foo jane x
* Value 42  36   11  7    10  10<0  200
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    int value;
} Item;

int cmp(const void *a, const void *b) {
    Item *item_a = (Item*) a;
    Item *item_b = (Item*) b;
    return strcmp(item_a->key, item_b->key);
}

Item *binary_search(Item *items, size_t size, const char *key) {
    if (size + size < size) {
        return NULL; // size too big; avoid overflow
    }
    size_t low = 0;
    size_t high = size;
    while (low < high) {
        size_t mid = (low + high) / 2;
        int c = strcmp(items[mid].key, key);
        if (c == 0) {
            return &items[mid];
        }
        if (c < 0) {
            low = mid + 1;  // eliminate low half of array
        } else {
            high = mid;     // eliminate high half of array
        }
    }
    // entiry array has been eliminated, key not found.
    return NULL; 
}

int main() {
    Item items[] = {
        {"bob", 42}, {"bazz", 36}, {"bob", 11}, {"buzz", 7},
        {"foo", 10}, {"jane", 100}, {"x", 200}}; 

    size_t num_items = sizeof(items) / sizeof(Item);

    Item key = {"bob", 0};
    
    Item *found = bsearch(&key, items, num_items, sizeof(Item), cmp);
    if (found == NULL) {
        return 1;
    }
    printf("bsearch: value of bob is %d\n", found->value);

    found = binary_search(items, num_items, "bob");
    if (found == NULL) {
        return 1;
    }
    printf("binary_search: value of 'bob' is %d\n", found->value);
    return 0;
}
