#include <stdio.h>

void main() {
    int n, i, j, temp;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int bt[n], wt[n], tat[n], at[n]; 
    float wtavg = 0, tatavg = 0;

    printf("Enter the arrival time and burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d - Arrival Time: ", i + 1);
        scanf("%d", &at[i]);
        printf("Process %d - Burst Time: ", i + 1);
        scanf("%d", &bt[i]);
    }

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (bt[i] > bt[j]) {
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;
            }
        }
    }

    wt[0] = 0;
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1] - at[i];
        if (wt[i] < 0) wt[i] = 0; 
    }

    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i]; 
        wtavg += wt[i];
        tatavg += tat[i];
    }

    printf("\nSJF (Non-Preemptive) Scheduling\n");
    printf("Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, at[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", wtavg / n);
    printf("Average Turnaround Time: %.2f\n", tatavg / n);
}
