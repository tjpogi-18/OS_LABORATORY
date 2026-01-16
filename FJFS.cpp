#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Process {
    int pid;           // Process ID
    int arrivalTime;   // Arrival Time
    int burstTime;     // Burst Time
    int completionTime;
    int turnaroundTime;
    int waitingTime;
};

int main() {
    int n = 10;
    vector<int> bt = {9, 8, 7, 8, 7, 8, 2, 1, 2, 5};  // Burst Times
    vector<int> at = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};  // Arrival Times
    
    vector<Process> processes(n);
    
    // Initialize processes
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        processes[i].arrivalTime = at[i];
        processes[i].burstTime = bt[i];
    }
    
    // FCFS Scheduling
    int currentTime = 0;
    
    for (int i = 0; i < n; i++) {
        // If CPU is idle, move to arrival time of next process
        if (currentTime < processes[i].arrivalTime) {
            currentTime = processes[i].arrivalTime;
        }
        
        // Process execution
        currentTime += processes[i].burstTime;
        processes[i].completionTime = currentTime;
        processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;
        processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;
    }
    
    // Display results
    cout << "\n========== FCFS SCHEDULING ALGORITHM ==========\n\n";
    cout << left << setw(6) << "PID" 
         << setw(6) << "AT" 
         << setw(6) << "BT" 
         << setw(6) << "TAT" 
         << setw(6) << "WT" << endl;
    cout << "----------------------------------------------\n";
    
    float totalTAT = 0, totalWT = 0;
    
    for (int i = 0; i < n; i++) {
        cout << left << setw(6) << processes[i].pid
             << setw(6) << processes[i].arrivalTime
             << setw(6) << processes[i].burstTime
             << setw(6) << processes[i].turnaroundTime
             << setw(6) << processes[i].waitingTime << endl;
        
        totalTAT += processes[i].turnaroundTime;
        totalWT += processes[i].waitingTime;
    }
    
    cout << "----------------------------------------------\n";
    cout << "\nAverage Turnaround Time: " << fixed << setprecision(2) << (totalTAT / n) << endl;
    cout << "Average Waiting Time: " << fixed << setprecision(2) << (totalWT / n) << endl;
    
    return 0;
}