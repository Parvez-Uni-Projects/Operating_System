#
Queue 98 183 37 122 14 124 65 67
Current head position = 53

Summary of the algorithms

Algorithm | Working procedure
--- | ---
FCFS | First come first serve
SSTF | Shortest seek time first
SCAN | Move to the end of the disk and then move to the other end of the disk and process the request
C-SCAN | Move to the end of the disk and then move to the other end of the disk and process the request in the same direction always
LOOK | Same as scan but will go to the last request in the direction of the head
C-LOOK | Same as c-scan but will go to the last request in the direction of the head


## FCFS (First Come First Serve)
Here the first cylinder request will be processed at first 

```mermaid

graph TD

53-->|53-98 = 45| A
A[98] -->|183-98 = 85| B[183]
B -->|183-37 = 146| C[37]
C -->|37-122 = 85| D[122]
D -->|122-14 = 108| E[14]
E -->|14-124 = 110| F[124]
F -->|124-65 = 59| G[65]
G -->|65-67 = 2| H[67]

```

Total head movement = 45 + 85 + 146 + 85 + 108 + 110 + 59 + 2  = 640

## SSTF (Shortest Seek Time First)

Here the shortest seek time will be processed at first 

so sorting the request


14 37 65 67 98 122 124 183

Current head is 53

0 14 37 53 65 67 98 122 124 183 199




```mermaid

graph TD

53 --> |65 - 53 = 12| A[65]
A --> |65 - 67 = 2| B[67]
B --> |67 - 37 = 30| C[37]
C --> |37 - 14 = 23| D[14]
D --> |14 - 98 = 84| E[98]
E --> |98 - 122 = 24| F[122]
F --> |122 - 124 = 2| G[124]
G --> |124 - 183 = 59| H[183]

```



Total head movement = 12 + 2 + 30 + 23 + 84 + 24 + 2 + 59 = 236

## SCAN

Here the head will move to the end of the disk and then it will move to the other end of the disk and process the request

Here the direction of the head is important and it will be given in the question

In this case lets assume head is moving to to 0

```
98 183 37 122 14 124 65 67

0 14 37 53 65 67 98 122 124 183 199
```


```mermaid

graph TD

53 --> |53 - 37 = 16| 37

37--> |37 - 14 = 23| 14

14 --> |14 - 0 = 14| C[0]

C --> |0 - 65 = 65| D[65]

D --> |65 - 67 = 2| E[67]

E --> |67 - 98 = 31| F[98]

F --> |98 - 122 = 24| G[122]

G --> |122 - 124 = 2| H[124]

H --> |124 - 183 = 59| I[183]

```

Total head movement = 16 + 23 + 14 + 65 + 2 + 31 + 24 + 2 + 59 = 236

## C-SCAN

Here the head will move to the end of the disk and then it will move to the other end of the disk and process the request in the same direction always

Here the service direction will be given 

```
98 183 37 122 14 124 65 67

0 14 37 53 65 67 98 122 124 183 199
```

```mermaid

graph LR

53 --> |65 - 53 = 12| 65

65 --> |65 - 67 = 2| 67

67 --> |67 - 98 = 31| 98

98 --> |98 - 122 = 24| 122

122 --> |122 - 124 = 2| 124

124 --> |124 - 183 = 59| 183

183 --> |183 - 199 = 16| 199

199 --> |199 - 0 = 0| 0

0 --> |0 - 14 = 14| 14

14 --> |14 - 37 = 23| 37

```

Total head movement = 12 + 2 + 31 + 24 + 2 + 59 + 16 + 0 + 14 + 23 = 183

## LOOK

It is same as scan but it will not go to the end of the disk but rather it will go to the last request in the direction of the head

```mermaid

graph LR

53 --> |53 - 37 = 16| 37

37 --> |37 - 14 = 23| 14

14 --> |14 - 65 = 51| 65

65 --> |65 - 67 = 2| 67

67 --> |67 - 98 = 31| 98

98 --> |98 - 122 = 24| 122

122 --> |122 - 124 = 2| 124

124 --> |124 - 183 = 59| 183

```

Total head movement = 16 + 23 + 51 + 2 + 31 + 24 + 2 + 59 = 208


## C-LOOK

Almost same as c-scan but will not go to the end of the disk


```mermaid

graph LR
53 --> |65 - 53 = 12| 65

65 --> |65 - 67 = 2| 67

67 --> |67 - 98 = 31| 98

98 --> |98 - 122 = 24| 122

122 --> |122 - 124 = 2| 124

124 --> |124 - 183 = 59| 183

183 --> | 183 - 14 = 0| 14

14 --> |14 - 37 = 23| 37

```

Total head movement = 12 + 2 + 31 + 24 + 2 + 59 + 0 + 23 = 153





