#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_TASKS 10

typedef struct {
    int id;
    int execution_time;
    int period;
    int deadline;
    int time_remaining;
    int next_start_time;
} Task;

// Function to calculate GCD
int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}

// Function to calculate LCM of all task periods
int find_lcm(int periods[], int n) {
    int lcm = periods[0];
    for (int i = 1; i < n; i++) {
        lcm = (lcm * periods[i]) / gcd(lcm, periods[i]);
    }
    return lcm;
}

void earliest_deadline_first(Task tasks[], int n) {
    int periods[MAX_TASKS];
    for (int i = 0; i < n; i++) {
        periods[i] = tasks[i].period;
    }
    
    int simulation_time = find_lcm(periods, n); // Corrected to LCM of periods
    printf("\nEarliest-Deadline First Scheduling (Simulating till time = %d):\n", simulation_time);

    for (int time = 0; time < simulation_time; time++) {
        int chosen_task = -1;
        
        // Check if any task arrives at this time
        for (int i = 0; i < n; i++) {
            if (time == tasks[i].next_start_time) {
                tasks[i].time_remaining = tasks[i].execution_time;
                tasks[i].next_start_time += tasks[i].period;
            }
        }

        // Pick the task with the earliest deadline
        for (int i = 0; i < n; i++) {
            if (tasks[i].time_remaining > 0) {
                if (chosen_task == -1 || tasks[i].deadline < tasks[chosen_task].deadline) {
                    chosen_task = i;
                }
            }
        }

        // Execute the chosen task or idle
        if (chosen_task != -1) {
            printf("Time %d: Task %d\n", time, tasks[chosen_task].id);
            tasks[chosen_task].time_remaining--;
        } else {
            printf("Time %d: Idle\n", time);
        }
    }
}

int main() {
    int n;
    printf("Enter the number of tasks: ");
    scanf("%d", &n);
    
    Task tasks[MAX_TASKS];
    for (int i = 0; i < n; i++) {
        printf("Enter execution time, period, and deadline for Task %d: ", i + 1);
        scanf("%d %d %d", &tasks[i].execution_time, &tasks[i].period, &tasks[i].deadline);
        tasks[i].id = i + 1;
        tasks[i].time_remaining = 0;
        tasks[i].next_start_time = 0;
    }
    
    earliest_deadline_first(tasks, n);
    
    return 0;
}
