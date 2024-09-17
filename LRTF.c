#include <stdio.h>
#include <stdbool.h>

void lrtf(int n, int pid[], int at[], int bt[]) {
    int rt[n], ct[n], tat[n], wt[n], response[n];
    bool first_exec[n];  
    int time = 0, completed = 0, total_tat = 0, total_wt = 0, total_rt = 0;
    int context_switches = 0;  // To count context switches
    int last_index = -1;  // To keep track of the last executed process
    int i;

    for (i = 0; i < n; i++) {
        rt[i] = bt[i];
        first_exec[i] = true; 
    }

    while (completed < n) {
        int max_index = -1;
        int max_remaining_time = -1;

        for (i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0) {
                if (rt[i] > max_remaining_time) {
                    max_remaining_time = rt[i];
                    max_index = i;
                }
            }
        }

        if (max_index != -1) {
            if (first_exec[max_index]) {
                response[max_index] = time - at[max_index];  
                total_rt += response[max_index];
                first_exec[max_index] = false;
            }

            if (last_index != -1 && last_index != max_index) {
                context_switches++;  // Increment context switches when a different process is executed
            }
            
            last_index = max_index;

            time++;
            rt[max_index]--;

            if (rt[max_index] == 0) {
                ct[max_index] = time;
                tat[max_index] = ct[max_index] - at[max_index];
                wt[max_index] = tat[max_index] - bt[max_index];
                total_tat += tat[max_index];
                total_wt += wt[max_index];
                completed++;
            }
        } else {
            time++;
        }
    }

    // Output the process details
    printf("Process\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i], response[i]);
    }

    // Calculating the efficiency and inefficiency
    float efficiency = ((float)(total_tat - total_wt) / total_tat) * 100;
    float inefficiency = ((float)total_wt / total_tat) * 100;

    // Display summary of results
    printf("Average Turnaround Time = %.2f\n", (float)total_tat / n);
    printf("Average Waiting Time = %.2f\n", (float)total_wt / n);
    printf("Average Response Time = %.2f\n", (float)total_rt / n);
    printf("Number of Context Switches = %d\n", context_switches);
    printf("Efficiency = %.2f%%\n", efficiency);
    printf("Inefficiency = %.2f%%\n", inefficiency);
}

int main() {
    int n;
    printf("Number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n];

    for (int i = 0; i < n; i++) {
        printf("Enter PID, Arrival Time, Burst Time for process %d: ", i + 1);
        scanf("%d %d %d", &pid[i], &at[i], &bt[i]);
    }

    lrtf(n, pid, at, bt);

    return 0;
}
