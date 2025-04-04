# Write a Hash table

Based on https://github.com/jamesroutley/write-a-hash-table

## API

Associative arrays are a collection of unordered key-value pairs. Duplicate keys
are not permitted. The following operations are supported:

- `search(a, k)`: return the value `v` associated with key `k` from the
  associative array `a`, or `NULL` if the key does not exist.
- `insert(a, k, v)`: store the pair `k:v` in the associative array `a`.
- `delete(a, k)`: delete the `k:v` pair associated with `k`, or do nothing if
  `k` does not exist.
