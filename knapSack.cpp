#include <bits/stdc++.h>
using namespace std;

struct Item {
    int weight, value;
};

// Compare by value/weight ratio
bool cmp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, Item arr[], int n) {
    // Sort items by value/weight ratio
    sort(arr, arr + n, cmp);

    double totalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (arr[i].weight <= W) {
            // take full item
            W -= arr[i].weight;
            totalValue += arr[i].value;
        } else {
            // take fraction
            totalValue += arr[i].value * ((double)W / arr[i].weight);
            break;
        }
    }

    return totalValue;
}

int main() {
    int n = 3;                  // number of items
    int W = 50;                 // knapsack capacity
    Item arr[] = {{10, 60}, {20, 100}, {30, 120}};

    cout << "Maximum value = " << fractionalKnapsack(W, arr, n);
    return 0;
}
