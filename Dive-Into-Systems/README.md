📚 Study Plan for Dive into Systems

(by Swarnendu Biswas, Tia Newhall, Kevin C. Webb)

This book covers computer systems, architecture, operating systems, and networks with a hands-on approach. Below is a structured 4-week study plan with hands-on exercises to reinforce learning.


---

🗓 Week 1: Understanding Computer Systems & C Programming

📌 Day 1-2: Introduction to Systems & C Programming (Ch. 1-2)

Key Topics:

Overview of computer systems

Why learn systems programming?

Basics of C programming


Hands-on Exercises:

Write a simple C program (Hello, World!).

Practice compiling with gcc (gcc hello.c -o hello).

Modify and experiment with printf() formatting.



🔹 Next Step: Learn how a C program interacts with system memory.


---

📌 Day 3-4: Memory Representation & C Data Structures (Ch. 3-4)

Key Topics:

Binary, Hexadecimal, Two's Complement

How C represents integers, floats, and pointers

Arrays, structs, and memory layout


Hands-on Exercises:

Convert numbers between decimal, binary, and hex manually.

Write a C program that prints pointer addresses (%p).

Implement a linked list in C using struct.



🔹 Next Step: Learn about how the OS manages memory.


---

🗓 Week 2: Memory & Assembly

📌 Day 5-6: Memory & The Stack (Ch. 5)

Key Topics:

Stack vs. Heap memory

Function calls, stack frames, recursion


Hands-on Exercises:

Write a recursive function and analyze its stack usage.

Use gdb to inspect stack frames during execution.



🔹 Next Step: Learn about assembly and how C code is translated.


---

📌 Day 7-8: Assembly & x86-64 (Ch. 6)

Key Topics:

Basics of x86-64 assembly

Registers, instructions, calling conventions


Hands-on Exercises:

Compile a C program with gcc -S to generate assembly.

Write a simple assembly function to add two numbers.



🔹 Next Step: Explore virtual memory and memory allocation.


---

🗓 Week 3: Virtual Memory, Processes, and System Calls

📌 Day 9-10: Virtual Memory & Address Translation (Ch. 7)

Key Topics:

Virtual vs. Physical memory

Pages, page tables, TLBs


Hands-on Exercises:

Use pmap to inspect a process’s memory layout.

Implement a simple malloc() wrapper that tracks allocations.



🔹 Next Step: Explore processes and system calls.


---

📌 Day 11-12: Processes & System Calls (Ch. 8-9)

Key Topics:

Processes, context switching

System calls (fork(), exec(), wait())


Hands-on Exercises:

Write a fork bomb (while(1) fork();).

Implement a basic shell (mini-sh.c).



🔹 Next Step: Learn about threads and concurrency.


---

🗓 Week 4: Multithreading, I/O, and Networking

📌 Day 13-14: Threads & Synchronization (Ch. 10-11)

Key Topics:

POSIX threads (pthread_create())

Race conditions, mutexes, deadlocks


Hands-on Exercises:

Write a multi-threaded counter using pthread_create().

Fix a race condition with a mutex (pthread_mutex_lock()).



🔹 Next Step: Explore file I/O and networking.


---

📌 Day 15-16: File I/O & Networking (Ch. 12-13)

Key Topics:

System calls for file handling (open(), read(), write())

Sockets and basic networking


Hands-on Exercises:

Implement a file copy program using read() and write().

Create a simple TCP server-client program in C.



🔹 Next Step: Review and do a final hands-on project.


---

🗓 Week 5 (Bonus Week): Final Projects

🔹 Project 1: Implement a Simple Malloc()

Write a custom memory allocator using sbrk().


🔹 Project 2: Build a Web Server

Create a multi-threaded HTTP server in C.



---

🚀 Final Thoughts

Beginner? Follow Weeks 1-3 closely.

Intermediate? Skip some intro topics and focus on Weeks 3-5.

Advanced? Build a malloc() implementation or OS simulation.
