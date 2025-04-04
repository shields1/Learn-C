// hash_table.h

// Stores our key-value pairs
typedef struct {
    char *key;
    char *value;
} ht_item;

// Stores an array of pointers to items, and some details about it's size and how full it is
typedef struct {
    int base_size;
    int size;
    int count;
    ht_item **items;
} ht_hash_table;

ht_hash_table* ht_new();
void ht_del_hash_table(ht_hash_table *ht);
void ht_insert(ht_hash_table *ht, const char *key, const char *value);
char* ht_search(ht_hash_table *ht, const char *key);
void ht_delete(ht_hash_table *ht, const char *key);
