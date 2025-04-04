/*
** stats.c - Show statistics of a hash table
** Usage:
**    $ python3 samples/gensimilar.py 466550 >samples/similar.txt
**    $ gcc -O2 -Wall -o stats samples/stats.c ht.c
**    $ ./stats <samples/words.txt
**    len=466550 cap=1048576 avgprobe=1.402
**    $ ./stats <samples/similar.txt
**    len=466550 cap=1048576 avgprobe=1.378
*/

#include "../ht.h"

#include <ctype.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void exit_nomem() {
    fprintf(stderr, "out of memory\n"),
    exit(EXIT_FAILURE);
}

// Copied from ht.c
typedef struct {
    char *key;      // key is NULL if this slot is empty
    void *value;
} ht_entry;

struct ht {
    ht_entry *entries;  // hash slots
    size_t capacity;    // size of _entries array
    size_t length;      // number of items in hash table
};

#define FNV_OFFSET 14695981039346656037UL
#define FNV_PRIME 1099511628211UL
