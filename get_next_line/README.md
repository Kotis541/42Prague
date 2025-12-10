This project has been created as part of the 42 curriculum by vokotera.
Description
Get Next Line is a C function that reads and returns one line at a time from a file descriptor. This project teaches fundamental concepts in systems programming, particularly:

Static variables - maintaining state between function calls
Buffer management - efficient reading using configurable buffer sizes
Memory management - proper allocation and deallocation to prevent leaks
File I/O operations - working with file descriptors and the read() system call

Goal
The primary goal is to implement a function get_next_line(int fd) that:

Returns a single line (including the trailing \n) from the given file descriptor
Handles multiple consecutive calls to read an entire file line by line
Works with any buffer size (defined at compile time)
Manages memory efficiently without leaks
Returns NULL when reaching EOF or encountering an error

Brief Overview
The function uses a static variable (stash) to store leftover data between calls. Each invocation:

Reads from the file descriptor in chunks of BUFFER_SIZE bytes
Accumulates data until a newline character (\n) is found or EOF is reached
Extracts and returns one complete line
Stores any remaining data for the next call

Resources
https://www.geeksforgeeks.org/c/static-variables-in-c/
https://pubs.opengroup.org/onlinepubs/009604599/functions/read.html
https://www.educative.io/answers/read-data-from-a-file-using-read-in-c
https://42-cursus.gitbook.io/guide/1-rank-01/get_next_line
Ai was used to guide through whole project. Where to start how to properly connect it and build it. 
