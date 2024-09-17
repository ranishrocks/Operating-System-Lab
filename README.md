
# Longest Remaining Time First (LRTF) Scheduling Algorithm

## Overview

This project is an implementation of the **Longest Remaining Time First (LRTF)** scheduling algorithm, a preemptive CPU scheduling algorithm. In LRTF scheduling, the process with the longest remaining burst time is selected for execution. This algorithm prioritizes processes that have more work left, which can reduce starvation but may increase the average waiting time.

The code simulates this algorithm and calculates the following metrics for each process:
- **Completion Time (CT)**
- **Turnaround Time (TAT)**
- **Waiting Time (WT)**
- **Response Time (RT)**
- **Number of Context Switches**

Additionally, the code provides insights into the **efficiency** and **inefficiency** of the scheduling approach.

## Features

- Preemptive scheduling based on remaining burst time
- Dynamic context switching based on process arrival
- Calculates key process scheduling metrics:
  - Average Turnaround Time
  - Average Waiting Time
  - Average Response Time
  - Total and Average Completion Time
  - Efficiency and Inefficiency of the schedule
  - Context Switches count

## How the LRTF Algorithm Works

1. The scheduler always picks the process with the **longest remaining burst time**.
2. If a process with a longer burst time arrives while another process is being executed, the scheduler switches to the new process.
3. The process continues until its burst time is reduced to 0, marking its completion.
4. The algorithm calculates various metrics based on the process execution and context switches.


## Installation and Usage

To run the program, follow these steps:

1. Clone the repository:
    ```bash
    git clone https://github.com/ranishrocks/Operating-System-Lab.git
    ```
2. Compile the C program:
    ```bash
    gcc -o lrtf LRTF.c
    ```
3. Run the program:
    ```bash
    ./lrtf
    ```

## Future Improvements

- Adding support for priority-based scheduling.
- Allowing for dynamic process arrival during execution.
- Optimization of context switching to reduce overhead.

## Contributions

Feel free to fork the project and submit pull requests if you'd like to contribute to improving the LRTF scheduling implementation.

![Drawing 2024-09-17 11 20 10 excalidraw](https://github.com/user-attachments/assets/162aa8e5-d614-4367-8e0d-f7713778ba12)
