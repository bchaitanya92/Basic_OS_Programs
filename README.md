# 🚀 Basic Programs in Operating Systems — C Language

<p align="center">
  <img src="https://img.shields.io/badge/C-Programming-blue?logo=c" alt="C">
  <img src="https://img.shields.io/badge/Operating%20System-Algorithms-green" alt="OS">
  <img src="https://img.shields.io/badge/Education-Learning-orange" alt="Education">
</p>

<p align="center">
  <b>Comprehensive C programs for mastering Operating System Concepts</b><br>
  <i>Learn, Practice, and Build a Strong Foundation in OS Principles!</i>
</p>

---

## 📋 Project Overview

This repository contains a curated set of C programs implementing fundamental Operating System concepts and algorithms. Each file is self-contained, well-commented, and ideal for students, interview preparation, and anyone looking to strengthen their understanding of OS principles through practical implementation.

---

## 🗂️ Folder Structure

```
Basic_OS_Programs/
│
├── *.c         # C source files (OS algorithms and concepts)
├── README.md   # This file
```

---

## 💻 Program List

| File Name                                 | Description                                              |
|-------------------------------------------|----------------------------------------------------------|
| Bankers_Algorithm_DeadLock_Avoidance.c    | Implementation of Banker's algorithm for deadlock avoidance |
| CPU_Scheduling.c                          | Various CPU scheduling algorithms (FCFS, SJF, Priority, Round Robin) |
| Contiguous_Memory_Allocation_Techniques.c | Memory allocation techniques (First Fit, Best Fit, Worst Fit) |
| File_Organization_Techniques.c            | Different file organization methods                      |
| Linked_File_Allocation.c                  | Linked file allocation technique implementation          |
| Main_writer_and_reader.c                  | Main program for writer-reader synchronization           |
| Page_Replacement_Algorithms.c             | Page replacement algorithms (FIFO, LRU)                  |
| Process_Call_System.c                     | System calls for process management                      |
| Producer_Consumer.c                       | Producer-consumer synchronization problem                |
| SCAN_disk_scheduling_algorithm.c          | SCAN disk scheduling algorithm implementation            |
| reader.c                                  | Reader process implementation                            |
| writer.c                                  | Writer process implementation                            |

---

## 🏆 Program Classification by Concept

<details>
<summary><b>Process Management</b></summary>

- CPU_Scheduling.c
- Process_Call_System.c
- Producer_Consumer.c
- Main_writer_and_reader.c
- reader.c
- writer.c
</details>

<details>
<summary><b>Memory Management</b></summary>

- Contiguous_Memory_Allocation_Techniques.c
- Linked_File_Allocation.c
- Page_Replacement_Algorithms.c
</details>

<details>
<summary><b>Deadlock Handling</b></summary>

- Bankers_Algorithm_DeadLock_Avoidance.c
</details>

<details>
<summary><b>File Systems</b></summary>

- File_Organization_Techniques.c
- SCAN_disk_scheduling_algorithm.c
</details>

---

## 🚀 Getting Started

### 1. Prerequisites
- C compiler (e.g., GCC, MinGW, or any standard C compiler)

### 2. Compile & Run
Open PowerShell or your terminal and run:
```powershell
gcc Bankers_Algorithm_DeadLock_Avoidance.c -o bankers.exe
./bankers.exe
```
Replace `Bankers_Algorithm_DeadLock_Avoidance.c` with any file you want to run.

For programs with multiple files (like reader-writer), compile together:
```powershell
gcc reader.c writer.c Main_writer_and_reader.c -o rw_sync.exe
./rw_sync.exe
```

---

## 💡 Usage

- Browse the `.c` files to study or modify the code
- Compile and run programs to see how each OS concept works
- Use as a reference for assignments, interviews, or self-study

---

## 👨‍💻 Author & Credits

<p>
  <b>Repository maintained for educational purposes</b> <br>
  <br>
  <b>Concepts covered:</b> Operating Systems, Process Management, Memory Management, Deadlock Handling, File Systems<br>
</p>

<p align="center">
  <i>Feel free to explore, modify, and experiment with the programs for learning, assignments, or your own projects!<br>
  Contributions and feedback are always welcome. Happy Coding! 🎉</i>
</p>

---

## 📄 License

This repository is intended for educational purposes only.