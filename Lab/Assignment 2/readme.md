Write codes to implement the following scheduling algorithms: FCFS, SJF and SRTN (Shortest Remaining Time Next).


Overview of waiting time and turnaround time for the following scheduling algorithms:

| Algorithm | Waiting Time | Turnaround Time |
| --------- | ------------ | --------------- |
| FCFS      |    5.57      |     12.67       |
| SJF       |    4.33      |     11.33       |
| SRTN      |    4.33      |     11.33       |

## FCFS (First Come First Serve)

### Problem Statement

Write a program to implement the FCFS scheduling algorithm. The program should accept the number of processes, arrival time and burst time of each process as input and display the Gantt chart and the average waiting time.

### Algorithm

1. Start
2. Accept the number of processes, arrival time and burst time of each process as input.
3. Sort the processes according to their arrival time.
4. Calculate the waiting time of each process.
5. Calculate the average waiting time.
6. Display the Gantt chart and the average waiting time.
7. Stop

### Input

```
3
5 7 9
4 0 2
```

### Output

```

Enter the number of process:  3
Enter the CPU times : 5 7 9 
Enter the arrival times : 4 0 2 
Process 1: Waiting Time: 12 Turnaround Time: 17
Process 2: Waiting Time: 0 Turnaround Time: 7
Process 3: Waiting Time: 5 Turnaround Time: 14
Average Waiting time: 5.67
Average Turnaround time: 12.67

```


## SJF (Shortest Job First)

### Problem Statement

Write a program to implement the SJF scheduling algorithm. The program should accept the number of processes, arrival time and burst time of each process as input and display the Gantt chart and the average waiting time.

### Algorithm

1. Start
2. Accept the number of processes, arrival time and burst time of each process as input.
3. Sort the processes according to their burst time.
4. Calculate the waiting time of each process.
5. Calculate the average waiting time.
6. Display the Gantt chart and the average waiting time.
7. Stop

### Input

```
3
5 7 9
4 0 2
```

### Output

```
Enter the number of process: 3
Enter the CPU times 5 7 9 
Enter the arrival times 4 0 2 


Process 1: Waiting Time: 3 Turnaround Time: 8
Process 2: Waiting Time: 0 Turnaround Time: 7
Process 3: Waiting Time: 10 Turnaround Time: 19
Average Waiting time : 4.33
Average Turnaround time : 11.33
```

## SRTN (Shortest Remaining Time Next)

### Problem Statement

Write a program to implement the SRTN scheduling algorithm. The program should accept the number of processes, arrival time and burst time of each process as input and display the Gantt chart and the average waiting time.

### Algorithm

1. Start
2. Accept the number of processes, arrival time and burst time of each process as input.
3. Sort the processes according to their arrival time.
4. Calculate the waiting time of each process.
5. Calculate the average waiting time.
6. Display the Gantt chart and the average waiting time.
7. Stop

### Input

```
3
5 7 9
4 0 2
```

### Output

```

Enter the number of process: 3
Enter the CPU times 5 7 9 
Enter the arrival times 4 0 2 
Process 1: Waiting Time: 3 Turnaround Time: 8
Process 2: Waiting Time: 0 Turnaround Time: 7
Process 3: Waiting Time: 10 Turnaround Time: 19
Average Waiting time : 4.33
Average Turnaround time : 11.33

```



