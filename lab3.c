#include <stdio.h>

int main() {
    int numberOfProcesses, timeQuantum;
    int bt[10], remainingTime[10];
    int wt[10], tt[10];
    int currentTime = 0, completedProcesses = 0;
    float averageWt = 0, averageTt = 0;

    printf("Enter number of processes: ");
    scanf("%d", &numberOfProcesses);

    printf("Enter burst time of each process:\n");
    for (int i = 0; i < numberOfProcesses; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]);
        remainingTime[i] = bt[i];
        wt[i] = 0;
    }

    printf("Enter time quantum: ");
    scanf("%d", &timeQuantum);

    while (completedProcesses < numberOfProcesses) {
        for (int i = 0; i < numberOfProcesses; i++) {
            if (remainingTime[i] > 0) {
                if (remainingTime[i] > timeQuantum) {
                    currentTime += timeQuantum;
                    remainingTime[i] -= timeQuantum;
                } else {
                    currentTime += remainingTime[i];
                    wt[i] = currentTime - bt[i];
                    remainingTime[i] = 0;
                    completedProcesses++;
                }
            }
        }
    }

    printf("\nProcess\tBT\tWT\tTT\n");
    for (int i = 0; i < numberOfProcesses; i++) {
        tt[i] = bt[i] + wt[i];
        averageWt += wt[i];
        averageTt += tt[i];

        printf("P%d\t%d\t%d\t%d\n",
               i + 1,
               bt[i],
               wt[i],
               tt[i]);
    }

    averageWt /= numberOfProcesses;
    averageTt /= numberOfProcesses;

    printf("\nAverage Waiting Time: %.2f", averageWt);
    printf("\nAverage Turnaround Time: %.2f\n", averageTt);

    return 0;
}
