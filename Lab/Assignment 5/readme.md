
# FIFO

## Problem Statement

Write a program to implement the FIFO page replacement algorithm. The program should accept the number of frames and the reference string as input and display the number of page faults.

## Algorithm

1. Start
2. Accept the number of frames and the reference string as input.
3. Initialize the page fault count to 0.
4. Initialize the page frame array to -1.
5. For each page in the reference string:
   1. If the page is not present in the page frame array:
      1. Increment the page fault count.
      2. If the page frame array is not full:
         1. Add the page to the page frame array.
      3. Else:
         1. Remove the first page from the page frame array.
         2. Add the page to the page frame array.
6. Display the number of page faults.
7. Stop

## Output

```
Time Step 1: 7 - - (Miss)
Time Step 2: 7 0 - (Miss)
Time Step 3: 7 0 1 (Miss)
Time Step 4: 0 1 2 (Miss)
Time Step 5: 0 1 2 (Hit)
Time Step 6: 1 2 3 (Miss)
Time Step 7: 2 3 0 (Miss)
Time Step 8: 3 0 4 (Miss)
Time Step 9: 0 4 2 (Miss)
Time Step 10: 4 2 3 (Miss)
Time Step 11: 2 3 0 (Miss)
Time Step 12: 2 3 0 (Hit)
Time Step 13: 2 3 0 (Hit)
Time Step 14: 2 3 0 (Hit)
Time Step 15: 2 3 0 (Hit)
Time Step 16: 3 0 1 (Miss)
Time Step 17: 0 1 2 (Miss)
Time Step 18: 0 1 2 (Hit)
Time Step 19: 0 1 2 (Hit)
Time Step 20: 1 2 7 (Miss)
Time Step 21: 2 7 0 (Miss)
Time Step 22: 7 0 1 (Miss)

Number of Page Faults (FIFO): 15
Page Fault Rate (FIFO): 68.18%
```

# LRU (Least Recently Used)

## Problem Statement

Write a program to implement the LRU page replacement algorithm. The program should accept the number of frames and the reference string as input and display the number of page faults.

### Algorithm

1. Start
2. Accept the number of frames and the reference string as input.
3. Initialize the page fault count to 0.
4. Initialize the page frame array to -1.
5. Initialize the page frame time array to 0.
6. For each page in the reference string:
   1. If the page is not present in the page frame array:
      1. Increment the page fault count.
      2. If the page frame array is not full:
         1. Add the page to the page frame array.
         2. Add the current time to the page frame time array.
      3. Else:
         1. Find the page in the page frame array with the least time.
         2. Replace the page with the least time with the current page.
         3. Add the current time to the page frame time array.
   2. Else:
      1. Update the time of the page in the page frame time array with the current time.
7. Display the number of page faults.
8. Stop

## Output

```
Time Step 1: 7 - - (Miss)
Time Step 2: 7 0 - (Miss)
Time Step 3: 7 0 1 (Miss)
Time Step 4: 2 0 1 (Miss)
Time Step 5: 2 0 1 (Hit)
Time Step 6: 2 0 3 (Miss)
Time Step 7: 2 0 3 (Hit)
Time Step 8: 4 0 3 (Miss)
Time Step 9: 4 0 2 (Miss)
Time Step 10: 4 3 2 (Miss)
Time Step 11: 0 3 2 (Miss)
Time Step 12: 0 3 2 (Hit)
Time Step 13: 0 3 2 (Hit)
Time Step 14: 0 3 2 (Hit)
Time Step 15: 0 3 2 (Hit)
Time Step 16: 1 3 2 (Miss)
Time Step 17: 1 3 2 (Hit)
Time Step 18: 1 0 2 (Miss)
Time Step 19: 1 0 2 (Hit)
Time Step 20: 1 0 7 (Miss)
Time Step 21: 1 0 7 (Hit)
Time Step 22: 1 0 7 (Hit)

Number of Page Faults (LRU): 12
Page Fault Rate (LRU): 54.55%
```

# FIRST FIT

## Problem Statement

Write a program to implement the first fit memory allocation algorithm. The program should accept the number of memory blocks, the size of each memory block, the number of processes, the size of each process and the memory allocation method as input and display the memory allocation table.

## Algorithm

1. Start
2. Accept the number of memory blocks, the size of each memory block, the number of processes, the size of each process and the memory allocation method as input.
3. Initialize the memory allocation table to -1.
4. Put each of them to the first block that has enough space.
5. Display the memory allocation table.
6. Stop

## Output

```
!!! First Fit Memory Allocation !!!
Request 1 - 100 allocated
Remaining Memory Size:
Hole 1: 50
Hole 2: 100
Hole 3: 70
Hole 4: 115
Hole 5: 15
------------------------
Request 2 - 10 allocated
Remaining Memory Size:
Hole 1: 40
Hole 2: 100
Hole 3: 70
Hole 4: 115
Hole 5: 15
------------------------
Request 3 - 35 allocated
Remaining Memory Size:
Hole 1: 5
Hole 2: 100
Hole 3: 70
Hole 4: 115
Hole 5: 15
------------------------
Request 4 - 15 allocated
Remaining Memory Size:
Hole 1: 5
Hole 2: 85
Hole 3: 70
Hole 4: 115
Hole 5: 15
------------------------
Request 5 - 23 allocated
Remaining Memory Size:
Hole 1: 5
Hole 2: 62
Hole 3: 70
Hole 4: 115
Hole 5: 15
------------------------
Request 6 - 6 allocated
Remaining Memory Size:
Hole 1: 5
Hole 2: 56
Hole 3: 70
Hole 4: 115
Hole 5: 15
------------------------
Request 7 - 25 allocated
Remaining Memory Size:
Hole 1: 5
Hole 2: 31
Hole 3: 70
Hole 4: 115
Hole 5: 15
------------------------
Request 8 - 55 allocated
Remaining Memory Size:
Hole 1: 5
Hole 2: 31
Hole 3: 15
Hole 4: 115
Hole 5: 15
------------------------
Request 9 - 88 allocated
Remaining Memory Size:
Hole 1: 5
Hole 2: 31
Hole 3: 15
Hole 4: 27
Hole 5: 15
------------------------
Request 10 - 40 not allocated
Remaining Memory Size:
Hole 1: 5
Hole 2: 31
Hole 3: 15
Hole 4: 27
Hole 5: 15
------------------------

External Fragmentation: 93
```

# WORST FIT

## Problem Statement

Write a program to implement the worst fit memory allocation algorithm. The program should accept the number of memory blocks, the size of each memory block, the number of processes, the size of each process and the memory allocation method as input and display the memory allocation table.

## Algorithm

1. Start
2. Accept the number of memory blocks, the size of each memory block, the number of processes, the size of each process and the memory allocation method as input.
3. Initialize the memory allocation table to -1.
4. Put each of them to the block that has the largest size.
5. Display the memory allocation table.
6. Stop

## Output

```

!!! Worst Fit Memory Allocation !!!
Request 1 - 100 allocated
Remaining Memory Size:
Hole 1: 50
Hole 2: 100
Hole 3: 70
Hole 4: 115
Hole 5: 15
------------------------
Request 2 - 10 allocated
Remaining Memory Size:
Hole 1: 50
Hole 2: 100
Hole 3: 70
Hole 4: 105
Hole 5: 15
------------------------
Request 3 - 35 allocated
Remaining Memory Size:
Hole 1: 50
Hole 2: 100
Hole 3: 70
Hole 4: 70
Hole 5: 15
------------------------
Request 4 - 15 allocated
Remaining Memory Size:
Hole 1: 50
Hole 2: 85
Hole 3: 70
Hole 4: 70
Hole 5: 15
------------------------
Request 5 - 23 allocated
Remaining Memory Size:
Hole 1: 50
Hole 2: 62
Hole 3: 70
Hole 4: 70
Hole 5: 15
------------------------
Request 6 - 6 allocated
Remaining Memory Size:
Hole 1: 50
Hole 2: 62
Hole 3: 64
Hole 4: 70
Hole 5: 15
------------------------
Request 7 - 25 allocated
Remaining Memory Size:
Hole 1: 50
Hole 2: 62
Hole 3: 64
Hole 4: 45
Hole 5: 15
------------------------
Request 8 - 55 allocated
Remaining Memory Size:
Hole 1: 50
Hole 2: 62
Hole 3: 9
Hole 4: 45
Hole 5: 15
------------------------
Request 9 - 88 can not allocated 
 !!! Terminating simulation !!! 

External Fragmentation: 181
```



