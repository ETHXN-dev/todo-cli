# todo-cli

A simple command-line todo list manager written in C with file persistence.

## Why I Built It

I built this project to level up as a C developer. I wanted to get comfortable working with files, structs, command line arguments, and memory — the kind of fundamentals that make you a stronger systems programmer.

## What I Learned

- How to use `argc` and `argv` to handle command line arguments
- How to read and write to files using `fopen`, `fscanf`, `fprintf`, and `fclose`
- How to design a simple file format for storing structured data
- How structs work in C and how to store and retrieve them from a file
- Why you can't edit a line in a plain text file in place, and how to work around it
- String handling in C — `strcpy`, `strcmp`, and why you can't assign strings directly
- Defensive programming — validating arguments and handling edge cases like missing files

## How to Compile

```bash
gcc todo.c -o todo
```

## How to Use

**Add a task:**
```bash
./todo add "Buy milk"
```

**List all tasks:**
```bash
./todo list
```

**Mark a task as done:**
```bash
./todo done 1
```

Tasks are stored in a `tasks.txt` file in the current directory.
