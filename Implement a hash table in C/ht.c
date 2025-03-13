/*
*
* ht.c - Simple hash table implmented in C.
*
*/
#include "ht.h"
#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

// Hash table entry (slot may be filled or empty).
typedef struct {
    const char *key;    // NULL if slot is empty
    void *value;
} ht_entry;

// Hash table structes: create with ht_create, free with ht_destory
struct ht {
    ht_entry *entries;  // hash slots
    size_t capacity;    // size of _entries array
    size_t length;      // number of items in hash table
}

#define INITIAL_CAPACITY 16 // can't be zero


