# OPERATING-SYSTEMS-CSE321-BRACU


CSE 321: Operating Systems - 


##Questions are shortened. See the lab folder for full questions with details.

# Lab Assignment 1

Ans: ⚡  <a href="https://github.com/AnonXarkA/OPERATING-SYSTEMS-CSE321-BRACU/tree/main/Lab%201"> LAB 1</a> <be> 



This document outlines the tasks for Lab Assignment 1 for the CSE 321 Operating Systems course. The assignment is divided into two main sections and is worth a total of 25 marks.

1. Linux Shell Commands (11 Marks)
This section focuses on essential Linux command-line operations. You will be tested on your ability to manage files and directories, manipulate permissions, and process text.

Task a (5 Marks): Perform a sequence of file and directory operations, including creating, moving, copying, and deleting files and directories. This task also involves checking and modifying file permissions.

Task b (2 Marks): Create a text file and use command-line tools to count specific lines within it.

Task c (2 Marks): Display all hidden files located in the root directory.

Task d (2 Marks): Extract and display a specific range of lines (lines 5-17) from a text file.

2. C Programming (14 Marks)
This section tests your fundamental C programming skills, covering basic I/O, file handling, and string manipulation.

Task a (2 Marks): Write a program that takes two numbers as input and performs addition, subtraction, or multiplication based on their comparison.

Task b (3 Marks): Develop a program that reads a text file, removes extra spaces between words, and writes the corrected text to a new file.

Task c (3 Marks): Create a password validation program that checks if a given string meets specific criteria (must contain at least one lowercase letter, one uppercase letter, one digit, and one special character from _, $, #, @).

Task d (3 Marks): Write a function to check if a company email address is using the new domain (@sheba.xyz) or an outdated one (@kaaj.com).

Task e (3 Marks): Implement a program that uses pointers to determine if a given string is a palindrome.

Ans: ⚡  <a href="https://github.com/AnonXarkA/OPERATING-SYSTEMS-CSE321-BRACU/tree/main/Lab%201"> LAB 1</a> <be> 

#  Lab Assignment 2

Ans: ⚡  <a href="https://github.com/AnonXarkA/OPERATING-SYSTEMS-CSE321-BRACU/tree/main/Lab%202"> LAB 2</a> <be> 

This document outlines the tasks for Lab Assignment 2 for the CSE 321 Operating Systems course. The assignment focuses on C programming, system calls, and threading, with a total of 20 marks available.

1. C Programming (Struct and Function) (4 Marks)
This section tests your ability to use structs and functions in C.

Task 1 (2 Marks): Calculate the total bill for a restaurant meal and divide it amongst a group of people. This task requires using structs to manage item quantity and price.

Task 2 (2 Marks): Write a C program that uses a function to find and print all perfect numbers within a given range.

2. System Calls (10 Marks)
This section covers the use of system calls for process creation and management.

Task 1 (2 Marks): Write a C program to open a file and write user-provided strings to it. The program should create the file if it doesn't exist and stop taking input when the user enters "-1".

Task 2 (2 Marks): Create a child and grandchild process, ensuring the output is printed in a specific order: grandchild, child, then parent.

Task 3 (2 Marks): Use multiple fork() calls and create additional child processes based on whether the process ID (PID) is odd. The final output should be the total number of processes created.

Task 4 (2 Marks): Create two separate programs, "sort.c" and "oddeven.c". Then, write a third program that uses a child process to sort an array and the parent process to determine if the numbers in the array are odd or even.

Task 5 (2 Marks): Write a program where a parent process creates one child and three grandchild processes, and then prints all of their process IDs.

3. Threading (6 Marks)
This section focuses on the fundamentals of multithreading in C.

Task 1 (2 Marks): Create five threads that execute sequentially, with each thread printing a message indicating when it is running and when it has closed.

Task 2 (2 Marks): Use five threads to print five integers each in a sequential order (e.g., Thread 0 prints 1-5, Thread 1 prints 6-10, and so on).

Task 3 (2 Marks): Create three threads that calculate the sum of ASCII values for three different usernames. A fourth thread will then compare these sums and print "Youreka" if all are equal, "Miracle" if two are equal, or "Hasta la vista" if none are equal.

Ans: ⚡  <a href="https://github.com/AnonXarkA/OPERATING-SYSTEMS-CSE321-BRACU/tree/main/Lab%202"> LAB 2</a> <be> 

# Lab Assignment 3

Ans: ⚡  <a href="https://github.com/AnonXarkA/OPERATING-SYSTEMS-CSE321-BRACU/tree/main/Lab%203"> LAB 3</a> <be> 

This document provides an overview of the tasks for Lab Assignment 3 for the CSE 321 Operating Systems course. The assignment is worth a total of 20 marks and focuses on inter-process communication (IPC).

Task 1: Online Banking with Shared Memory and Pipes (10 Marks)
This task requires you to implement a simple online banking application using two cooperating processes: a parent process (home) and a child process (opr).

Objective: The parent process will create a shared memory segment and a pipe. It will prompt the user to select a banking operation (add money, withdraw, or check balance) and store this choice along with an initial balance in the shared memory.

Child Process Role: The child process will read the data from the shared memory, execute the requested transaction (adding or withdrawing money with input validation), and print the result.

Communication:

Shared Memory: Used to pass the user's selected operation and the account balance between the parent and child.

Pipe: Used by the child process to send a final "Thank you" message back to the parent before terminating.

Termination: The parent process will read the final message from the pipe and then remove the shared memory segment.

Task 2: Workspace Authentication with Message Queues (10 Marks)
This task involves creating a three-level process hierarchy to simulate a workspace login and OTP verification system using message queues for communication.

Objective: The main log in process will validate a user-provided workspace name. If correct ("cse321"), it will initiate a multi-step verification process with its child (otp_generator) and grandchild (mail).

Process Flow & Communication:

log in to otp_generator: Sends the validated workspace name via a message queue.

otp_generator: Reads the workspace name. It then generates an OTP (its own process ID) and sends it back to the log in process in one message and forwards the same OTP to its child, mail, in another message.

mail to log in: The mail process receives the OTP from its parent and forwards it to the main log in process.

Verification: The log in process receives the OTP from both the otp_generator and mail processes. It compares them to verify the OTP.

Termination: The log in process prints the final verification status ("OTP Verified" or "OTP Incorrect") and removes the message queue.

Ans: ⚡  <a href="https://github.com/AnonXarkA/OPERATING-SYSTEMS-CSE321-BRACU/tree/main/Lab%203"> LAB 3</a> <be> 

# Lab Assignment 4

Ans: ⚡  <a href="https://github.com/AnonXarkA/OPERATING-SYSTEMS-CSE321-BRACU/tree/main/Lab%204"> LAB 4</a> <be> 

This document outlines the tasks for Lab Assignment 4 for the CSE 321 Operating Systems course. The assignment is worth a total of 20 marks and focuses on synchronization using semaphores and mutexes in C.

Background: Semaphores and Mutexes
The assignment begins with a brief introduction to POSIX threads, semaphores, and mutexes, including the necessary libraries (<semaphore.h>, <pthread.h>) and key functions:

Semaphore functions: sem_init, sem_wait, sem_post, sem_destroy.

Mutex functions: pthread_mutex_init, pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock.

Task 1: Producer-Consumer Problem with Mutex (10 Marks)
This task requires you to solve the classic producer-consumer problem by modifying a given C code snippet.

Objective: Implement the logic for a producer and a consumer function that share a fixed-size buffer.

Synchronization: You must use mutexes and condition variables (pthread_mutex_t, pthread_cond_t) to handle the critical sections and ensure proper communication between the producer and consumer threads.

Implementation: The code should be completed to allow the producer to add items to the buffer and the consumer to remove them, preventing race conditions and deadlocks. The program will use one producer thread and one consumer thread.

Task 2: Farmer and Shop Owner Problem with Semaphores (10 Marks)
This task presents a variation of the producer-consumer problem involving farmers and shop owners who share a warehouse.

Objective: Modify the provided C code to simulate five farmers producing different crops and five shop owners taking them from a shared warehouse.

Synchronization: This solution requires the use of both mutexes for mutual exclusion within the critical section and semaphores (sem_t) to manage the empty and full slots in the warehouse.

Implementation: You will need to complete the Farmer and ShopOwner functions. Farmers will add crops to the warehouse, and shop owners will remove them. The program must correctly manage access to the shared warehouse buffer among the ten threads.


Ans: ⚡  <a href="https://github.com/AnonXarkA/OPERATING-SYSTEMS-CSE321-BRACU/tree/main/Lab%204"> LAB 4</a> <be> 



# Lab Assignment 5


Ans: ⚡  <a href="https://github.com/AnonXarkA/OPERATING-SYSTEMS-CSE321-BRACU/tree/main/Lab%205"> LAB 5</a> <be> 

This document provides an overview of the single task for Lab Assignment 5 for the CSE 321 Operating Systems course. The assignment is worth a total of 20 marks and focuses on virtual memory management.

Task 1: Logical to Physical Address Mapping (20 Marks)
This task requires you to write a C program that simulates the mapping of logical addresses to physical addresses in a paged memory system.

Objective: Given a set of system parameters and a series of logical addresses generated by the CPU, your program must calculate the corresponding physical addresses.

System Parameters:

Physical Memory Size: 32 bytes

Page Size: 4 bytes

Page Table:

Page 0 -> Frame 3

Page 1 -> Frame 6

Page 2 -> Frame 8

Page 3 -> Frame 12

Page 4 -> Frame 2

Logical Addresses to Map: 8, 4, 3, 2, 15, 18, 25

Implementation:

You are required to modify a provided C code skeleton to implement the solution.

The core of the task is to correctly extract the page number and offset from each logical address.

Use the page number to look up the corresponding frame number in the page table.



Ans: ⚡  <a href="https://github.com/AnonXarkA/OPERATING-SYSTEMS-CSE321-BRACU/tree/main/Lab%205"> LAB 5</a> <be> 

Calculate the final physical address using the formula: physical_address = (frame_number * page_size) + offset.

The program must also handle cases where a logical address is invalid (e.g., the page number is not in the page table or the resulting physical address is out of bounds).
