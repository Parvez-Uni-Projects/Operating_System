## Problem Statement

Write a program to simulate the Producer-Consumer problem using semaphores. Your program should have 2 producers and 2 consumers (follow lab manual for output format). Your program should print appropriate messages while simulating the problem.

## Algorithm

1. Start
2. Initialize the semaphores.
3. Create two producer threads and two consumer threads.
4. Wait for the threads to finish.
5. Stop

## Details of consumer producer problem

### Producer

1. Wait for empty buffer.
2. Wait for mutex.
3. Add item to buffer.
4. Signal mutex.
5. Signal full buffer.

### Consumer

1. Wait for full buffer.
2. Wait for mutex.
3. Remove item from buffer.
4. Signal mutex.
5. Signal empty buffer.

