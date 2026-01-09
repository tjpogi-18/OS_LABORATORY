#include<stdio.h>

int main()
{
    int bt[20], wt[20], tat[20], i, n;
    float wtavg, tatavg;

    printf("\nEnter the number of processes -- ");
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        printf("\nEnter Burst Time for Process %d -- ", i);
        scanf("%d", &bt[i]);
    }
    wt[0] = wtavg = 0; // waiting time for first process is 0

    tat[0] = tatavg = bt[0]; // turnaround time for first process is its burst time
    for(i=1; i<n; i++)
    {
        wt[i] = wt[i-1] + bt[i-1];  //0 + 24 
        tat[i] = tat[i-1] + bt[i];  //24 + 3 = 27
        wtavg = wtavg + wt[i];      // 0 = 0+ 24
        tatavg = tatavg + tat[i];  // 0=0+ 27
    }
    printf("\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n");
    for(i=0; i<n; i++)
        printf("\n\t P%d \t\t %d \t\t %d \t\t %d", i, bt[i], wt[i], tat[i]);
    printf("\nAverage Waiting Time -- %f", wtavg/n);
    printf("\nAverage Turnaround Time -- %f", tatavg/n);
    getchar();
    return 0;
}