#include <bits/stdc++.h>
using namespace std;

// Structure to store activity details
struct Activity {
    int start;
    int finish;
};

// Comparison function to sort activities by finish time
bool compare(Activity a1, Activity a2) {
    return a1.finish < a2.finish;
}

int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;

    vector<Activity> activities(n);

    // Input start and finish times
    for (int i = 0; i < n; i++) {
        cout << "Enter start and finish time of activity " << i + 1 << ": ";
        cin >> activities[i].start >> activities[i].finish;
    }

    // Sort activities by finish time
    sort(activities.begin(), activities.end(), compare);

    cout << "Selected activities: " << endl;

    int lastFinish = 0; // End time of last selected activity

    for (int i = 0; i < n; i++) {
        if (activities[i].start >= lastFinish) {
            // Select this activity
            cout << "Activity " << i + 1 << " (" << activities[i].start 
                 << ", " << activities[i].finish << ")" << endl;
            lastFinish = activities[i].finish;
        }
    }

    return 0;
}
