*This activity has been created as part of the 42 curriculum by senandri.*

# Libft

## Description

Libft is a foundational C project from the 42 curriculum. The goal is to reimplement a set of standard C library functions from scratch, then compile them into a static library — `libft.a` — that can be reused in future 42 projects.

The library is split into three parts:

- **Part 1 – Libc functions**: reimplementations of standard `libc` functions
- **Part 2 – Additional functions**: utility functions not present in `libc`, or present in a different form
- **Part 3 – Linked list**: a set of functions to create and manipulate a singly linked list using the `t_list` structure

## Library Overview

### Part 1 – Libc functions

| Function     | Description |

| `ft_isalpha` | Returns 1 if the character is alphabetic, 0 otherwise |
| `ft_isdigit` | Returns 1 if the character is a digit, 0 otherwise |
| `ft_isalnum` | Returns 1 if the character is alphanumeric, 0 otherwise |
| `ft_isascii` | Returns 1 if the character is in the ASCII table, 0 otherwise |
| `ft_isprint` | Returns 1 if the character is printable, 0 otherwise |
| `ft_strlen`  | Returns the length of a string |
| `ft_memset`  | Fills a memory area with a given byte value |
| `ft_bzero`   | Sets a memory area to zero |
| `ft_memcpy`  | Copies a memory area to a non-overlapping destination |
| `ft_memmove` | Copies a memory area, handling overlapping regions correctly |
| `ft_strlcpy` | Copies a string into a buffer with size limit, returns total length |
| `ft_strlcat` | Appends a string to a buffer with size limit, returns attempted total length |
| `ft_toupper` | Converts a lowercase character to uppercase |
| `ft_tolower` | Converts an uppercase character to lowercase |
| `ft_strchr`  | Returns a pointer to the first occurrence of a character in a string |
| `ft_strrchr` | Returns a pointer to the last occurrence of a character in a string |
| `ft_strncmp` | Compares two strings up to n characters |
| `ft_memchr`  | Searches for a byte value in a memory area |
| `ft_memcmp`  | Compares two memory areas |
| `ft_strnstr` | Locates a substring within a string, searching at most n characters |
| `ft_atoi`    | Converts a string to an integer |
| `ft_calloc`  | Allocates zero-initialized memory for an array |
| `ft_strdup`  | Returns a heap-allocated copy of a string |

### Part 2 – Additional functions

| Function        | Description |

| `ft_substr`     | Returns a heap-allocated substring of a string |
| `ft_strjoin`    | Returns a heap-allocated concatenation of two strings |
| `ft_strtrim`    | Returns a copy of a string with leading/trailing characters from a set removed |
| `ft_split`      | Splits a string by a delimiter and returns an array of substrings |
| `ft_itoa`       | Returns a string representation of an integer |
| `ft_strmapi`    | Applies a function to each character of a string, returning a new string |
| `ft_striteri`   | Applies a function to each character of a string, modifying it in place |
| `ft_putchar_fd` | Outputs a character to a file descriptor |
| `ft_putstr_fd`  | Outputs a string to a file descriptor |
| `ft_putendl_fd` | Outputs a string followed by a newline to a file descriptor |
| `ft_putnbr_fd`  | Outputs an integer to a file descriptor |

### Part 3 – Linked list

The linked list functions operate on the following structure, declared in `libft.h`:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

| Function          | Description |

| `ft_lstnew`       | Creates a new list node with the given content |
| `ft_lstadd_front` | Adds a node at the beginning of the list |
| `ft_lstsize`      | Returns the number of nodes in the list |
| `ft_lstlast`      | Returns the last node of the list |
| `ft_lstadd_back`  | Adds a node at the end of the list |
| `ft_lstdelone`    | Frees a single node using a deletion function |
| `ft_lstclear`     | Frees the entire list and sets the pointer to NULL |
| `ft_lstiter`      | Applies a function to the content of each node |
| `ft_lstmap`       | Creates a new list by applying a function to each node's content |

## Instructions

### Compilation

To compile the library:

```bash
make
```

This will produce `libft.a` at the root of the repository.

### Using the library in your project

```bash
cc -Wall -Wextra -Werror your_file.c -L. -lft -o your_program
```

Make sure `libft.h` is included in your source files:

```c
#include "libft.h"
```

### Makefile rules

| Rule                | Effect |

| `make` / `make all` | Compiles the library |
| `make clean`        | Removes object files |
| `make fclean`       | Removes object files and `libft.a` |
| `make re`           | Full recompile from scratch |

## Resources

### References

- Man pages (`man 3 <function_name>`) for all reimplemented functions
- [GNU C Library documentation](https://www.gnu.org/software/libc/manual/) for additional details
- 42 Piscine subject PDFs (Makefile structure and rules)

### Use of AI

AI was used during this project in the following ways:

- **Conceptual questions**: to understand underlying C mechanics such as linked lists, signed/unsigned arithmetic, the compilation vs. linking distinction, and static library creation with `ar`
- **README generation**: the structure and content of this README was generated by AI
