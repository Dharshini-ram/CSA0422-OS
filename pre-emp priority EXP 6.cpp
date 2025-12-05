#include <stdio.h>

int main() {
    int n, i, time = 0, smallest, count = 0;
    int bt[20], rt[20], priority[20], p[20];
    int wt[20], tat[20];
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("P%d Burst Time: ", i+1);
        scanf("%d", &bt[i]);
        printf("P%d Priority (lower = higher priority): ", i+1);
        scanf("%d", &priority[i]);
        rt[i] = bt[i];   // Remaining time
    }

    // Priority of finished processes must not interfere
    priority[19] = 9999; 

    while(count < n) {
        smallest = 19;

        // Find process with highest priority AND not finished
        for(i = 0; i < n; i++) {
            if(priority[i] < priority[smallest] && rt[i] > 0)
                smallest = i;
        }

        // Run 1 time unit
        rt[smallest]--;

        if(rt[smallest] == 0) {
            count++;
            int finish = time + 1;

            tat[smallest] = finish;  
            wt[smallest] = tat[smallest] - bt[smallest];

            avg_wt += wt[smallest];
            avg_tat += tat[smallest];
        }

        time++;
    }

    printf("\nProcess\tBT\tPriority\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t\t%d\t%d\n", p[i], bt[i], priority[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt/n);
    printf("\\nAverage Turn Around Time = %.2f\n", avg_tat/n);

    return 0;
}

