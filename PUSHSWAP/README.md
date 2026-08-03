*This activity has been created as part of the 42 curriculum by isendris, senandri.*

# push_swap

Sort integers on a stack with a limited set of operations, using as few moves as possible.

## Description

`push_swap` takes a list of integers as argument and prints to standard output the shortest possible sequence of Push_swap operations to sort those integers in ascending order in stack `a`.

The program implements four distinct sorting strategies and automatically selects the most suitable one based on the size and disorder of the input.

## Instructions

### Compilation

```bash
make
```

### Usage

```bash
./push_swap [--simple|--medium|--complex|--adaptive] <list of integers>
```

**Strategy selectors (optional):**
- `--simple`: force the O(n²) algorithm
- `--medium`: force the O(n√n) algorithm
- `--complex`: force the O(n log n) algorithm
- `--adaptive`: automatic selection based on disorder (default behavior)

**Benchmark mode (optional):**
```bash
./push_swap --bench [--simple|--medium|--complex] <list of integers>
```
Prints to stderr the disorder rate, the strategy used, the total number of operations and the breakdown per operation type.

### Examples

```bash
# Basic sort
./push_swap 5 4 3 2 1

# Force a strategy
./push_swap --complex 5 4 3 2 1

# Verify with the checker provided on the intra (after tar -xf checker.tar.xz)
ARG="4 67 3 87 23"; ./push_swap --adaptive $ARG | ./checker/ubuntu_checker $ARG

# Display metrics
./push_swap --bench 5 4 3 2 1 2> bench.txt; cat bench.txt
```

### Cleaning

```bash
make clean    # removes the .o files
make fclean   # removes the .o files and the binary
make re       # recompiles everything
```

## Algorithms

### `--simple` — O(n²): Selection sort

Finds the minimum in stack `a`, brings it to the top via `ra` or `rra` (shortest path), pushes it to `b` with `pb`. Repeats until 3 elements remain in `a`, sorts them with `sort_three`, then pushes everything back to `a` with `pa`.

**Rationale:** Simple to implement and efficient on small inputs (≤ 5 elements) or nearly sorted inputs.

### `--medium` — O(n√n): Chunk-based sorting

Splits the elements into groups of `⌈√n⌉` consecutive ranks (chunks). For each chunk, locates each element in `a` (shortest path), pushes it to `b` while keeping `b` sorted in descending order through positioned insertion. At the end, the maximum of `b` is brought back to the top and everything is pushed back to `a` with `pa`.

**Rationale:** Good trade-off between implementation complexity and performance for medium-sized inputs (6–359 elements).

### `--complex` — O(n log n): Radix sort (LSD)

Assigns each value its normalized rank (0 to n-1). Performs `⌈log₂(n)⌉` passes, with a weight that doubles at each pass (1, 2, 4, …). At each pass, goes through the n elements of `a`: if `(rank / weight) % 2` is 0 → `pb`, otherwise → `ra`. After the pass, everything is pushed back to `a` with `pa`. After all the passes, `a` is sorted.

**Rationale:** Optimal for large inputs (≥ 360 elements) since the number of operations grows in n·log(n) regardless of the distribution.

### `--adaptive` — Automatic selection

Measures the **disorder** before any move:

```
disorder = inversions / (n × (n-1) / 2)
```

where an inversion is a pair (i, j) with i < j and a[i] > a[j]. The disorder is 0 for a sorted input and 1 for reverse order.

**Selection thresholds:**

| Condition | Strategy |
|-----------|-----------|
| n ≤ 5 | Simple |
| disorder ≥ 0.5 or n ≥ 360 | Complex |
| disorder < 0.2 | Simple |
| otherwise | Medium |

**Threshold rationale:**
- Above 50% disorder, the subject requires an O(n log n) method: radix sort guarantees this bound regardless of the distribution.
- Below 360 elements (with moderate disorder), radix sort always performs `log₂(n)` full passes even if few elements are out of place, making it less efficient than chunk-based sorting.
- Below 20% disorder, the input is nearly sorted: selection sort moves very few elements and remains competitive (O(n²) is allowed by the subject in this regime).
- Between 20% and 50%, chunk-based sorting (O(n√n), matching the subject's medium regime) better amortizes the rotation cost on intermediate-sized inputs.

## Performance

| Size | Pass | Good | Excellent |
|--------|--------|-----|-----------|
| 100 numbers | < 2,000 ops | < 1,500 ops | < 700 ops |
| 500 numbers | < 12,000 ops | < 8,000 ops | < 5,500 ops |

Measured results: ~800 to ~1,100 ops for 100 numbers depending on disorder (chunks or radix), ~6,800 ops for 500 numbers.

## Contributions

| Member | Files |
|--------|----------|
| **senandri** | `push_swap.h`, `Makefile`, `LIBFT/`, `ps_parsing.c`, `ps_errors.c`, `ps_stack.c`, `op_swap.c`, `op_push.c`, `op_rotate.c`, `op_rrotate.c`, `bench.c`, `simple.c` |
| **isendris** | `main.c`, `adaptive.c`, `medium.c`, `medium_utils.c`, `complex.c` |

## Resources

- [Wikipedia — Radix sort](https://en.wikipedia.org/wiki/Radix_sort)
- [Wikipedia — Selection sort](https://en.wikipedia.org/wiki/Selection_sort)
- push_swap visualizer: [https://okayama1.github.io/push_swap_visualizer/](https://okayama1.github.io/push_swap_visualizer/)

**AI usage:**
AI was used to:
- Deepen the understanding of the sorting algorithms (radix sort, chunk-based sorting, selection sort) and their complexities in the Push_swap model
- Clarify theoretical concepts (inversions, Big-O, choice of the adaptive thresholds)
- Write this README

The design of the algorithms, the architecture of the project and the C implementation were done by the two learners.
