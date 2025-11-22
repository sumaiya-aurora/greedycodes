#include <bits/stdc++.h>

using namespace std;

// Structure to represent a job
struct Job {
    int id;       // Job ID
    int deadline; // Deadline of job
    int profit;   // Profit if job is done
};

// Function to sort jobs by profit in descending order
bool compareProfit(Job a, Job b) {
    return a.profit > b.profit;
}

void jobSequencing(vector<Job> jobs) {
    int n = jobs.size();

    // Step 1: Sort jobs by profit
    sort(jobs.begin(), jobs.end(), compareProfit);

    // Step 2: Find maximum deadline
    int maxDeadline = 0;
    for (auto job : jobs) {
        if (job.deadline > maxDeadline)
            maxDeadline = job.deadline;
    }

    // Step 3: Initialize slots
    vector<int> slot(maxDeadline + 1, -1); // -1 means empty slot

    int totalProfit = 0;

    cout << "Selected Jobs: ";

    // Step 4: Assign jobs to slots
    for (auto job : jobs) {
        // Find a free slot for this job (from its deadline backwards)
        for (int j = job.deadline; j > 0; j--) {
            if (slot[j] == -1) {
                slot[j] = job.id;
                totalProfit += job.profit;
                cout << job.id << " ";
                break;
            }
        }
    }

    cout << "\nTotal Profit: " << totalProfit << endl;
}

int main() {
    vector<Job> jobs = {
        {1, 2, 100},
        {2, 1, 19},
        {3, 2, 27},
        {4, 1, 25},
        {5, 3, 15}
    };

    jobSequencing(jobs);

    return 0;
}
