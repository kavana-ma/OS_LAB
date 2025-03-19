#include <stdio.h>
void roundRobin(int bt[], int n, int quantum, int queue[], int sys_count, int user_count) {
    int remaining_bt[20];
    int wt[20] = {0}, tat[20] = {0}, ct[20] = {0};
    int total_count = sys_count + user_count;
    int queue_index = 0;
    int current_time = 0, total_bt = 0;
    float wtavg = 0, tatavg = 0;

    for (int i = 0; i < total_count; i++) {
        remaining_bt[i] = bt[i];
        total_bt += bt[i];
    }

    while (total_bt > 0) {
        for (int i = 0; i < total_count; i++) {
            if (remaining_bt[i] > 0) {
                int time_slice = (remaining_bt[i] <= quantum) ? remaining_bt[i] : quantum;
                current_time += time_slice;
                remaining_bt[i] -= time_slice;
                total_bt -= time_slice;

                if (remaining_bt[i] == 0) {
                    ct[i] = current_time;
                    tat[i] = ct[i] - (total_bt - bt[i]);
                    wt[i] = tat[i] - bt[i];
                }
            }
        }
    }

    for (int i = 0; i < total_count; i++) {
        wtavg += wt[i];
        tatavg += tat[i];
    }

    printf("\nPROCESS\tBURST TIME\tQUEUE\tCOMPLETION TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for (int i = 0; i < total_count; i++) {
        if (queue[i] == 1) {
            printf("%d\t%d\t\tSystem\t%d\t\t%d\t\t%d\n", i + 1, bt[i], ct[i], wt[i], tat[i]);
        } else if (queue[i] == 2) {
            printf("%d\t%d\t\tUser\t%d\t\t%d\t\t%d\n", i + 1, bt[i], ct[i], wt[i], tat[i]);
        }
    }

    printf("\nAverage Waiting Time: %.2f", wtavg / total_count);
    printf("\nAverage Turnaround Time: %.2f\n", tatavg / total_count);
}

int main() {
    int bt[20], queue[20];
    int n, quantum;
    int sys_count = 0, user_count = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter Burst Time for Process %d: ", i + 1);
        scanf("%d", &bt[i]);
        printf("Enter Queue Number (1 = System, 2 = User) for Process %d: ", i + 1);
        scanf("%d", &queue[i]);

        if (queue[i] == 1) {
            sys_count++;
        } else if (queue[i] == 2) {
            user_count++;
        }
    }

    printf("Enter the Time Quantum: ");
    scanf("%d", &quantum);

    roundRobin(bt, n, quantum, queue, sys_count, user_count);

    return 0;
}
