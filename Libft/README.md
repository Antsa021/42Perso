*This activity has been created as part of the 42 curriculum by senandri.*

# libft

## Description

Libft is a C programming project from the 42 curriculum.

The goal of this project is to recreate a personal C library by rewriting several standard functions from the C standard library, as well as additional utility functions that will be useful in future 42 projects.

This project helps students understand how common C functions work internally, especially around:

- Memory manipulation
- String manipulation
- Character checking and conversion
- Dynamic memory allocation
- File descriptor output
- Linked lists

By implementing these functions manually, the project strengthens understanding of pointers, memory management, allocation, and basic data structures in C.

---

## Library Description

The library created in this project is called `libft.a`.

It is a static C library containing custom implementations of standard and utility functions.

### Part 1 — Libc functions

These functions reproduce the behavior of standard C library functions:

| Function | Description |
|---|---|
| `ft_isalpha` | Checks if a character is alphabetic |
| `ft_isdigit` | Checks if a character is a digit |
| `ft_isalnum` | Checks if a character is alphanumeric |
| `ft_isascii` | Checks if a character belongs to the ASCII table |
| `ft_isprint` | Checks if a character is printable |
| `ft_strlen` | Calculates the length of a string |
| `ft_memset` | Fills memory with a constant byte |
| `ft_bzero` | Sets memory bytes to zero |
| `ft_memcpy` | Copies memory from one area to another |
| `ft_memmove` | Copies memory safely, even with overlapping areas |
| `ft_strlcpy` | Copies a string with size limitation |
| `ft_strlcat` | Concatenates strings with size limitation |
| `ft_toupper` | Converts a lowercase letter to uppercase |
| `ft_tolower` | Converts an uppercase letter to lowercase |
| `ft_strchr` | Locates the first occurrence of a character in a string |
| `ft_strrchr` | Locates the last occurrence of a character in a string |
| `ft_strncmp` | Compares two strings up to `n` characters |
| `ft_memchr` | Locates a byte in memory |
| `ft_memcmp` | Compares two memory areas |
| `ft_strnstr` | Locates a substring in a string with size limitation |
| `ft_atoi` | Converts a string to an integer |
| `ft_calloc` | Allocates memory and initializes it to zero |
| `ft_strdup` | Duplicates a string into newly allocated memory |

### Part 2 — Additional functions

These functions are not direct rewrites of libc functions but are useful tools for later projects:

| Function | Description |
|---|---|
| `ft_substr` | Creates a substring from a string |
| `ft_strjoin` | Joins two strings into a new string |
| `ft_strtrim` | Removes characters from the beginning and end of a string |
| `ft_split` | Splits a string into an array of strings using a delimiter |
| `ft_itoa` | Converts an integer to a string |
| `ft_strmapi` | Applies a function to each character of a string and creates a new string |
| `ft_striteri` | Applies a function to each character of a string in place |
| `ft_putchar_fd` | Writes a character to a file descriptor |
| `ft_putstr_fd` | Writes a string to a file descriptor |
| `ft_putendl_fd` | Writes a string followed by a newline to a file descriptor |
| `ft_putnbr_fd` | Writes an integer to a file descriptor |

### Bonus — Linked list functions

The bonus part implements basic linked list manipulation functions using the `t_list` structure.

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;

## Resources

Several resources were used during this project to better understand the concepts and complete the library properly.

The main resource was peer-to-peer learning, which is an important part of the 42 curriculum. I often discussed with other students to compare approaches, understand errors, debug functions, and improve my understanding of C programming.

I also used internet resources to read documentation, check the behavior of standard C functions, and better understand topics such as memory allocation, pointers, strings, file descriptors, and linked lists.

Some useful references include:

- The C manual pages:
  - `man strlen`
  - `man memset`
  - `man memcpy`
  - `man memmove`
  - `man calloc`
  - `man malloc`
  - `man free`
- The GNU C Library documentation
- The 42 Libft subject
- Norminette documentation
- Online tutorials and articles about C programming
- Peer-to-peer explanations and code reviews with other 42 students

### Use of AI

AI was used occasionally as a learning support tool.

It helped me understand some difficult concepts, clarify certain errors, and get simpler explanations about topics such as pointers, memory management, linked lists, and Makefile structure.

AI was not used to replace the learning process. The project was still written, tested, debugged, and understood manually.