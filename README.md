
<p align="center">
        <img src="https://scontent.feoh1-1.fna.fbcdn.net/v/t1.0-9/104448042_2608745076110649_8646754031899513624_o.png?_nc_cat=108&_nc_sid=174925&_nc_ohc=zDYFAk4wVUcAX_FuUU9&_nc_ht=scontent.feoh1-1.fna&oh=a74be9afae4c0e3c269e6ae1a55f6bba&oe=5F627106" width="280"/>
        </p>
<p align="center">
     <p align="center">
          <img src="https://www.holbertonschool.com/holberton-logo.png" width="360"/>
     </p>
     
# 0x16. C - Simple shell
In this project we'll create a simple UNIX command interpreter in C programming language.

## Table of Contents
* [Introduction](#Introduction)
  * What is Shell
  * What is it for
* [Project Information](#Project-Information)
    * Tasks
    * General requirements
    * Allowed functions
* [Documentation](#Documentation)
    * Compilation
    * Testing
    * Files
    * Show flowchart
* [Extra Information](#Extra-Information)
    * Resources
* [Authors](#Authors)
  
  ---
  
  
## Introduction
  
### What is Shell 
A **shell** is a command-line interpreter, it is the computer program that provides a user interface to access the services of the operating system. Depending on the type of interface they use, shells can be of various types, in this case, a shell program of the type **`sh`** ([Bourne Shell](https://en.wikipedia.org/wiki/Bourne_shell)) will be developed. Users typically interact with a shell using a [terminal emulator](https://en.wikipedia.org/wiki/Terminal_emulator) that is used for entering data into and displaying or printing data from, a computer or a computing system.

### What is it for
This consists of interpreting orders. It incorporates features such as process control, input/output redirection, law listing and reading, protection, communications, and a command language for writing batch programs or scripts. All Unix-type systems have at least one interpreter compatible with the Bourne shell. The Bourne shell program is found within the Unix file hierarchy at **`/bin/sh`**.



## Project Information

### Tasks

* Task 0. README, man, AUTHORS
* Task 1. Betty would be proud
* Task 2. Simple shell 0.1
* Task 3. Simple shell 0.2
* Task 4. Simple shell 0.3
* Task 5. Simple shell 0.4
* Task 6. Simple shell 1.0
* Task 7. What happens when you type ls -l in the shell

### General requirements
 * Allowed editors: vi, vim, emacs
 * All your files will be compiled on `Ubuntu 14.04 LTS`
 * Your C programs and functions will be compiled with `gcc 4.8.4` using the flags `-Wall` `-Werror` `-Wextra` and `-pedantic`
 * Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
 * No more than 5 functions per file
 * All your header files should be include guarded
 * This shell should not have any memory leaks
 * Unless specified otherwise, your program must have the exact same output as `sh` (`/bin/sh`) as well as the exact same error output.

### Allowed functions
* `access` (man 2 access)
* `chdir` (man 2 chdir)
* `close` (man 2 close)
* `closedir` (man 3 closedir)
* `execve` (man 2 execve)
* `exit` (man 3 exit)
* `_exit` (man 2 _exit)
* `fflush` (man 3 fflush)
* `fork` (man 2 fork)
* `free` (man 3 free)
* `getcwd` (man 3 getcwd)
* `getline` (man 3 getline)
* `isatty` (man 3 isatty)
* `kill` (man 2 kill)
* `malloc` (man 3 malloc)
* `open` (man 2 open)
* `opendir` (man 3 opendir)
* `perror`(man 3 perror)
* `read` (man 2 read)
* `readdir` (man 3 readdir)
* `signal` (man 2 signal)
* `stat` (__ xstat) (man 2 stat)
* `lstat` (__ lxstat) (man 2 lstat)
* `fstat` (__ fxstat) (man 2 fstat)
* `strtok` (man 3 strtok)
* `wait` (man 2 wait)
* `waitpid` (man 2 waitpid)
* `wait3` (man 2 wait3)
* `wait4` (man 2 wait4)
* `write` (man 2 write)

## Documentation

### Compilation
Your shell will be compiled this way:

`gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`

### Testing

Your shell should work like this in interactive mode:

```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
