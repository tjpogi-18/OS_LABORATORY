#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Process {
    int pid;           // Process ID
    double burstTime;  // Burst Time
    double completionTime;
    double turnaroundTime;
    double waitingTime;
};

int main() {
    int n = 6;
    vector<double> bt = {99.99, 107.9, 143.77, 20.24, 50.55, 66.66};  // Burst Times
    
    vector<Process> processes(n);
    
    // Initialize processes
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        processes[i].burstTime = bt[i];
    }
    
    // Sort processes by burst time (SJF - Shortest Job First)
    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.burstTime < b.burstTime;
    });
    
    // SJF Scheduling
    double currentTime = 0;
    
    for (int i = 0; i < n; i++) {
        // Process execution
        currentTime += processes[i].burstTime;
        processes[i].completionTime = currentTime;
        processes[i].turnaroundTime = processes[i].completionTime;
        processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;
    }
    
    // Display results
    cout << "\n========== SHORTEST JOB FIRST (SJF) SCHEDULING ALGORITHM ==========\n\n";
    cout << left << setw(6) << "PID" 
         << setw(12) << "BT" 
         << setw(12) << "TAT" 
         << setw(12) << "WT" << endl;
    cout << "---------------------------------------------\n";
    
    double totalTAT = 0, totalWT = 0;
    
    for (int i = 0; i < n; i++) {
        cout << left << setw(6) << processes[i].pid
             << setw(12) << fixed << setprecision(2) << processes[i].burstTime
             << setw(12) << fixed << setprecision(2) << processes[i].turnaroundTime
             << setw(12) << fixed << setprecision(2) << processes[i].waitingTime << endl;
        
        totalTAT += processes[i].turnaroundTime;
        totalWT += processes[i].waitingTime;
    }
    
    cout << "---------------------------------------------\n";
    cout << "\nAverage Turnaround Time: " << fixed << setprecision(2) << (totalTAT / n) << endl;
    cout << "Average Waiting Time: " << fixed << setprecision(2) << (totalWT / n) << endl;
    
    return 0;
}
