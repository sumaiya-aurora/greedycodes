#include <bits/stdc++.h>
using namespace std;

struct Node {
    int id;
    int value;
    vector<int> children;
};

int K;  // maximum allowed per node
vector<Node> tree;
vector<Node> newTree;
int newID = 1;

// Greedy splitting of one node value
vector<int> greedySplit(int value) {
    vector<int> parts;
    while (value > K) {
        parts.push_back(K);
        value -= K;
    }
    if (value > 0) parts.push_back(value);
    return parts;
}

// DFS to rebuild split-tree
int dfs(int u) {
    Node curr = tree[u];

    // split current node value
    vector<int> pieces = greedySplit(curr.value);

    // create first main node
    int parentID = newID++;
    newTree.push_back({parentID, pieces[0], {}});

    // attach extra split nodes as children
    int lastParent = parentID;
    for (int i = 1; i < pieces.size(); i++) {
        int childID = newID++;
        newTree.push_back({childID, pieces[i], {}});
        newTree[lastParent-1].children.push_back(childID);
        lastParent = childID;
    }

    // recursively process original children
    for (int child : curr.children) {
        int newChild = dfs(child);
        newTree[lastParent-1].children.push_back(newChild);
    }

    return parentID;
}

int main() {
    int n;
    cout << "Enter number of nodes in tree: ";
    cin >> n;

    tree.resize(n+1);

    cout << "Enter node values:\n";
    for (int i = 1; i <= n; i++) {
        tree[i].id = i;
        cin >> tree[i].value;
    }

    cout << "Enter tree edges (parent child):\n";
    for (int i = 1; i < n; i++) {
        int p, c;
        cin >> p >> c;
        tree[p].children.push_back(c);
    }

    cout << "Enter max allowed value K: ";
    cin >> K;

    // Process root = 1
    dfs(1);

    // Print new tree
    cout << "\nNew Tree after Greedy Splitting:\n";
    for (auto &node : newTree) {
        cout << "Node " << node.id << " (value = " << node.value << ") --> children: ";
        for (int c : node.children) cout << c << " ";
        cout << "\n";
    }

    return 0;
}
