#include <stdio.h>

int main() {
    int n;
    int bt[10], priority[10], pid[10];
    int wt[10], tt[10];
    float avgWt = 0, avgTt = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter Burst Time for P%d: ", pid[i]);
        scanf("%d", &bt[i]);
        printf("Enter Priority for P%d (lower number = higher priority): ", pid[i]);
        scanf("%d", &priority[i]);
    }


    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (priority[i] > priority[j]) {
                int temp;

                temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }

    wt[0] = 0;

    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    for (int i = 0; i < n; i++) {
        tt[i] = wt[i] + bt[i];
        avgWt += wt[i];
        avgTt += tt[i];
    }

    avgWt /= n;
    avgTt /= n;

    printf("\nProcess\tBT\tPriority\tWT\tTT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t\t%d\t%d\n",
               pid[i], bt[i], priority[i], wt[i], tt[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avgWt);
    printf("\nAverage Turnaround Time = %.2f\n", avgTt);

    return 0;
}
