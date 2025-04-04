/*
*
* demo.c
*
* Example usage:
* $ echo 'foo bar the bar bar bar the' | ./demo
* foo 1
* bar 4
* the 2
* 3
*
*
* If you don’t know how a hash table works, here’s a quick refresher. 
* A hash table i* s a container data structure that allows you to quickly look up a key (often a string) 
* to find its corresponding value (any data type). Under the hood, they’re arrays that are indexed by a hash function of the key.

* A hash function turns a key into a random-looking number, and it must always return the same number given the same key. 
* For example, with the hash function we’re going to use (64-bit FNV-1a), the hashes of the keys above are as follows:
*
* Key   Hash                 Hash modulo 16
* bar   16101355973854746    10
* bazz  11123581685902069096 8
* bob   21748447695211092    4
* buzz  18414333339470238796 12
* foo   15902901984413996407 7
* jane  10985288698319103569 1
* x     12638214688346347271 7 (same as foo)
*/
#include <stdio.h>
#include <stdlib.h>
#include "ht.h"

void exit_nomem(void) {
    fprintf(stderr, "out of memory\n");
    exit(EXIT_FAILURE);
}

int main() {
    ht *counts = ht_create();
    if (counts == NULL) {
        exit_nomem();
    }

    // read next word from stdin (at most 100 chars long).
    char word[101];
    while (scanf("%100s", word) != EOF) {
        // look up word
        void *value = ht_get(counts, word);
        if (value != NULL) {
            // Already exists, increment int that value points to.
            int *pcount = (int *)value;
            (*pcount)++;
            continue;
        }
        // Word not found, allocate space for new int and set to 1.
        int *pcount = malloc(sizeof(int));
        if (pcount == NULL) {
            exit_nomem();
        }
        *pcount = 1;
        if (ht_set(counts, word, pcount) == NULL) {
            exit_nomem();
        }
    }

    // Print out words and frequencies, freeing values as we go.
    hti it = ht_iterator(counts);
    while (ht_next(&it)) {
        printf("%s %d\n", it.key, *(int *)it.value);
        free(it.value);
    }

    // Show the number of unique words.
    printf("\nUnique number of words: %d\n", (int)ht_length(counts));

    ht_destroy(counts);
    return 0;
}
