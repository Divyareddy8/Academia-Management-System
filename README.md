# Course Management System

The **Course Management System** is a multi-user academic management platform implemented in **C**, designed for Linux environments. It leverages low-level **Linux system calls** such as file locking, process control, and socket programming to provide a secure, concurrent, and role-based academic portal for students, faculty, and administrators.

This project demonstrates strong foundations in **Operating Systems**, **Computer Networks**, and **Systems Programming**.

---

## Overview

The system follows a **client–server architecture**, where a central server manages academic data stored in files and serves multiple clients concurrently. Each client connects to the server via sockets and interacts with the system based on their assigned role.

To ensure data consistency and prevent race conditions, the system uses **POSIX read and write locks (`fcntl`)**, allowing safe concurrent access to shared resources.

---

## Key Features

### User Account Management

* Student, faculty, and administrator data are stored persistently in files
* Accounts are categorized by role and managed centrally by the administrator

### Secure Login System

* Role-based authentication for students, faculty, and administrators
* Administrator access is password-protected to prevent unauthorized control

### Role-Based Functionality

**Administrator**

* Add, modify, activate, or block student and faculty accounts
* View complete student and faculty records
* Manage academic data across the system
* Logout securely

**Student**

* View available courses
* Enroll in new courses
* Drop enrolled courses
* View enrolled course details
* Change password
* Logout securely

**Faculty**

* View courses offered
* Add new courses
* Remove courses from the catalog
* Update course details
* Change password
* Logout securely

### Data Locking and Concurrency

* Read and write locks are implemented using POSIX file locking
* Supports multiple concurrent clients without data corruption
* Ensures integrity of academic records during simultaneous access

### Socket Programming

* Server maintains all academic data and services client requests
* Multiple clients can connect and operate concurrently
* Uses TCP sockets for reliable communication

---

## Technologies Used

* C (GNU GCC)
* Linux system calls
* POSIX file locking (`fcntl`)
* TCP socket programming
* Process management using `fork()`
* File-based persistent storage

---

## Usage

1. Compile the server and client programs using a Linux-compatible compiler.
2. Start the server on a central machine.
3. Run the client application from student, faculty, or administrator terminals.
4. Log in using valid credentials.
5. Use the interactive menu to perform role-specific operations such as course enrollment, account management, or course updates.

---

## Notes

* This project is intended to run on **Linux-based systems**.
* POSIX system calls used in the project are not supported natively on Windows.
* Recommended environment: Linux or WSL with GCC.


