
📖 Suggested Reading Plan (2–3 Weeks)

Beginner: 1 chapter per day (~1–2 hrs per day)

Intermediate/Advanced: 2+ chapters per day (~2–3 hrs)

Hands-on Learning: Code all exercises and projects



---

📚 Chapter Breakdown & Key Topics

🔵 Week 1: The Basics of C

📌 Day 1: Chapter 1 – A Tutorial Introduction (2–3 hrs)

Topics: Hello World, printf, variables, loops

Hands-on:

Write and run hello.c:

#include <stdio.h>
int main() {
    printf("Hello, world!\n");
    return 0;
}

Modify it to take user input (scanf).



📌 Day 2: Chapter 2 – Types, Operators, Expressions (2 hrs)

Topics: Data types, operators, precedence

Hands-on:

Implement basic calculations using int, float, and double.

Experiment with bitwise operators (&, |, ^, ~).



📌 Day 3: Chapter 3 – Control Flow (2 hrs)

Topics: if, else, loops, switch-case, goto

Hands-on:

Implement a calculator program using switch-case.

Write a Fibonacci sequence generator using while.



📌 Day 4: Chapter 4 – Functions & Program Structure (2 hrs)

Topics: Function declarations, recursion, modularity

Hands-on:

Write a recursive function for factorial calculation.

Implement a modular program with multiple .c and .h files.



📌 Day 5: Chapter 5 – Pointers & Arrays (3 hrs)

Topics: Pointer arithmetic, dynamic memory, arrays

Hands-on:

Write a string reverse function using pointers.

Experiment with malloc() and free().



📌 Day 6: Chapter 6 – Structures & Unions (2–3 hrs)

Topics: Structs, unions, typedefs, linked lists

Hands-on:

Implement a simple linked list in C.



📌 Day 7: Review & Hands-on Projects (3–4 hrs)

Revisit: Key chapters, pointer exercises

Hands-on:

Modify K&R’s word count program (wc).

Implement a basic stack using structs.




---

🟠 Week 2: Advanced C Concepts & The Standard Library

📌 Day 8: Chapter 7 – Input & Output (2–3 hrs)

Topics: getchar(), putchar(), file I/O

Hands-on:

Implement a file copy program using fopen(), fread(), fwrite().



📌 Day 9: Chapter 8 – The Unix System Interface (3 hrs)

Topics: System calls, low-level I/O, process control

Hands-on:

Write a program to list files in a directory (ls) using opendir() and readdir().



📌 Day 10: Memory Management & Optimization (3 hrs)

Topics: malloc(), calloc(), memory leaks

Hands-on:

Implement a dynamic array that resizes when full.



📌 Day 11: Strings & Character Manipulation (2–3 hrs)

Topics: strcpy(), strlen(), manual string handling

Hands-on:

Write your own implementation of strlen().



📌 Day 12: File Handling & Pipes (3 hrs)

Topics: fopen(), fgets(), fprintf()

Hands-on:

Implement a simple log file system that appends logs to a text file.



📌 Day 13: Debugging & Error Handling (3 hrs)

Topics: GDB, Valgrind, error handling

Hands-on:

Debug a program using GDB (gdb ./a.out).

Check for memory leaks with Valgrind (valgrind ./a.out).



📌 Day 14: Review & Final Projects (4+ hrs)

Final Practice:

Implement a basic shell (mini-sh) in C.

Build a simple HTTP server using sockets.




---

🚀 Extra Hands-On Challenges

1. Rewrite Standard Functions – Implement strlen(), strcpy(), strcmp().


2. Build a Dynamic Array – A resizable array that grows as elements are added.


3. Create a Simple Database – Store, retrieve, and update records in a file.


4. Write a Small Compiler/Interpreter – Parse and evaluate expressions.


5. Contribute to Open Source – Look for small C projects on GitHub.



Here are five hands-on projects based on The C Programming Language (K&R, 2nd Edition). These projects reinforce concepts like file handling, pointers, memory management, data structures, and system programming.


---

🛠 Project 1: Implement strlen(), strcpy(), and strcmp()

📌 Goal: Understand how C handles strings at a low level.

Concepts Used: Pointers, arrays, loops

🔹 Task 1: Implement strlen()
```C
#include <stdio.h>

size_t my_strlen(const char *str) {
    size_t len = 0;
    while (*str++) len++;
    return len;
}

int main() {
    printf("Length: %zu\n", my_strlen("Hello, World!"));
    return 0;
}
```
🔹 Task 2: Implement strcpy()
```C
char *my_strcpy(char *dest, const char *src) {
    char *ptr = dest;
    while ((*ptr++ = *src++));
    return dest;
}
```
🔹 Task 3: Implement strcmp()
```C
int my_strcmp(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}
```
🔹 Next Step: Implement more string functions (strcat(), strchr()).


---

🛠 Project 2: Build a Dynamic Array (Resizable Array)

📌 Goal: Create an array that grows dynamically.

Concepts Used: malloc(), realloc(), free(), pointers
```C
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    size_t used;
    size_t size;
} DynamicArray;

void initArray(DynamicArray *a, size_t initialSize) {
    a->array = malloc(initialSize * sizeof(int));
    a->used = 0;
    a->size = initialSize;
}

void insertArray(DynamicArray *a, int element) {
    if (a->used == a->size) {
        a->size *= 2;
        a->array = realloc(a->array, a->size * sizeof(int));
    }
    a->array[a->used++] = element;
}

void freeArray(DynamicArray *a) {
    free(a->array);
    a->array = NULL;
    a->used = a->size = 0;
}

int main() {
    DynamicArray a;
    initArray(&a, 5);
    
    for (int i = 0; i < 10; i++) insertArray(&a, i);

    for (int i = 0; i < a.used; i++) printf("%d ", a.array[i]);
    
    freeArray(&a);
    return 0;
}
```
🔹 Next Step: Implement removeElement() to shrink the array.


---

🛠 Project 3: Create a Simple Key-Value Database

📌 Goal: Store key-value pairs in a file and retrieve them.

Concepts Used: File handling, struct, fwrite(), fread()
```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY 50
#define MAX_VALUE 100
#define DB_FILE "database.bin"

typedef struct {
    char key[MAX_KEY];
    char value[MAX_VALUE];
} KeyValuePair;

void addRecord(const char *key, const char *value) {
    FILE *file = fopen(DB_FILE, "ab");
    if (!file) return;
    
    KeyValuePair record;
    strncpy(record.key, key, MAX_KEY);
    strncpy(record.value, value, MAX_VALUE);
    
    fwrite(&record, sizeof(KeyValuePair), 1, file);
    fclose(file);
}

void getRecord(const char *key) {
    FILE *file = fopen(DB_FILE, "rb");
    if (!file) return;
    
    KeyValuePair record;
    while (fread(&record, sizeof(KeyValuePair), 1, file)) {
        if (strcmp(record.key, key) == 0) {
            printf("Key: %s, Value: %s\n", record.key, record.value);
            fclose(file);
            return;
        }
    }
    
    printf("Key not found!\n");
    fclose(file);
}

int main() {
    addRecord("username", "john_doe");
    addRecord("password", "123456");

    getRecord("username");
    return 0;
}
```
🔹 Next Step: Implement deleteRecord().


---

🛠 Project 4: Implement a Mini Shell (mini-sh)

📌 Goal: Create a simple command-line shell like Bash.

Concepts Used: fork(), execvp(), waitpid()
```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD 100

void mini_sh() {
    char cmd[MAX_CMD];
    
    while (1) {
        printf("mini-sh> ");
        fgets(cmd, MAX_CMD, stdin);
        cmd[strcspn(cmd, "\n")] = 0;
        
        if (strcmp(cmd, "exit") == 0) break;

        pid_t pid = fork();
        if (pid == 0) {
            char *args[] = {cmd, NULL};
            execvp(cmd, args);
            perror("Execution failed");
            exit(1);
        } else {
            wait(NULL);
        }
    }
}

int main() {
    mini_sh();
    return 0;
}
```
🔹 Next Step: Add support for cd and multiple arguments.


---

🛠 Project 5: Build a Simple HTTP Server

📌 Goal: Serve basic HTML pages over HTTP.

Concepts Used: Sockets (socket(), bind(), listen(), accept())
```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

void serve_client(int client_socket) {
    char response[] =
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/html\r\n"
        "Connection: close\r\n\r\n"
        "<html><body><h1>Hello from C Server!</h1></body></html>";
    
    write(client_socket, response, sizeof(response) - 1);
    close(client_socket);
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = {AF_INET, htons(PORT), INADDR_ANY};

    bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));
    listen(server_socket, 5);
    printf("Server running on port %d...\n", PORT);
    
    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        serve_client(client_socket);
    }
    
    return 0;
}
```
🔹 Next Step: Add handling for GET and POST requests.


---

🚀 Final Thoughts

Beginner? Start with Projects 1 & 2.

Intermediate? Try Project 3 (Key-Value Database).

Advanced? Build Project 4 (Shell) & Project 5 (Server).
