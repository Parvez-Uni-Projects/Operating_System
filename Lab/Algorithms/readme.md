# Bankers Algorithm

## Introduction

The Banker's algorithm is a resource allocation and deadlock avoidance algorithm developed by Edsger Dijkstra that tests for safety by simulating the allocation of predetermined maximum possible amounts of all resources, and then makes an "s-state" check to test for possible deadlock conditions for all other pending activities, before deciding whether allocation should be allowed to continue.

## Algorithm

Let `n` be the number of processes in the system and `m` be the number of resources types.

1. Let `Available` be a vector of length `m` indicating the number of available resources of each type.

2. Let `Max` be an `n` by `m` matrix that defines the maximum demand of each process in a system.

3. Let `Allocation` be an `n` by `m` matrix that defines the number of resources of each type currently allocated to each process.

4. Let `Need` be an `n` by `m` matrix that indicates the remaining resource need of each process.

5. The `i`th row of the `Need` matrix is defined as `Max[i] - Allocation[i]`.

6. If `Need[i,j] = k`, then the `i`th process may need at most `k` more instances of the `j`th resource type to complete its task.

7. If `Need[i,j] = 0`, then the `i`th process is said to be **fully allocated**.

8. If `Need[i,j] > 0`, then the `i`th process is said to be **not fully allocated**.

9. If `Need[i,j] = k`, then the `i`th process is said to be **partially allocated**.

10. If `Need[i,j] = Max[i,j]`, then the `i`th process is said to be **not allocated**.

11. If `Need[i,j] > Available[j]`, then the `i`th process must wait, since the resources are not available.

12. If `Need[i,j] <= Available[j]`, then the `i`th process may proceed.

13. If `Need[i,j] <= Available[j]` for all `i`, then the system is in a **safe state**.

14. If `Need[i,j] > Available[j]` for some `i`, then the system is in an **unsafe state**.

## Example

Consider a system with five processes `P1` through `P5` and three resource types `A`, `B` and `C`. Suppose that the following data are available for the processes and the system has `10` instances of `A` , `6` instances of `B` and `7` instances of `C` available.

### Allocation Matrix:

Calculation formula : `Allocation[i,j] = Max[i,j] - Need[i,j]`

| Process | A | B | C |
| :-----: | :-----: | :-----: | :-----: |
| P1 | 1 | 1 | 2 |
| P2 | 2 | 1 | 2 |
| P3 | 4 | 0 | 1 |
| P4 | 0 | 2 | 0 |
| P5 | 1 | 1 | 2 |

### Max Matrix:

calculation formula : `Max[i,j] = Allocation[i,j] + Need[i,j]`

| Process | A | B | C |
| :-----: | :-----: | :-----: | :-----: |
| P1 | 4 | 3 | 3 |
| P2 | 3 | 2 | 2 |
| P3 | 9 | 0 | 2 |
| P4 | 7 | 5 | 3 |
| P5 | 1 | 1 | 2 |

### Need Matrix:

calculation formula : `Need[i,j] = Max[i,j] - Allocation[i,j]`

| Process | A | B | C |
| :-----: | :-----: | :-----: | :-----: |
| P1 | 3 | 2 | 1 |
| P2 | 1 | 1 | 0 |
| P3 | 5 | 0 | 1 |
| P4 | 7 | 3 | 3 |
| P5 | 0 | 0 | 0 |

### Total Available Vector:

Will be given always.
A | B | C
:-----: | :-----: | :-----:
10 | 6 | 7

### Available Vector:

calculation formula : `Available[j] = Total Available[j] - sum(Allocation[i,j])`

| A | B | C |
| :-----: | :-----: | :-----: |
| 2 | 1 | 0 |


### Safe Sequence:

calculation formula : Take the process that needs less than current available resources. In any order so sometimes there can be multiple safe sequences.

| Process | A | B | C |
:-----: | :-----: | :-----: | :-----:
P2 | 1 | 1 | 0
P5 | 0 | 0 | 0
P1 | 3 | 2 | 1
P3 | 5 | 0 | 1
P4 | 7 | 3 | 3


In this example, the system is in a safe state since there exists a safe sequence `P2`, `P5`, `P1`, `P3`, `P4`.



