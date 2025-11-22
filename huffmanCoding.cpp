#include <bits/stdc++.h>
using namespace std;

// Structure for Huffman Tree node
struct Node {
    char ch;       // Character
    int freq;      // Frequency
    Node *left;    // Left child
    Node *right;   // Right child

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

// Compare struct for priority queue (min-heap)
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq; // smallest freq has highest priority
    }
};

// Recursive function to print Huffman codes
void printCodes(Node* root, string code) {
    if (!root) return;

    // If this is a leaf node (character)
    if (!root->left && !root->right) {
        cout << root->ch << ": " << code << endl;
    }

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

// Function to build Huffman Tree
void huffmanCoding(vector<char> chars, vector<int> freq) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Step 1: Create leaf nodes for each character and push to priority queue
    for (int i = 0; i < chars.size(); i++) {
        pq.push(new Node(chars[i], freq[i]));
    }

    // Step 2: Build the tree
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* newNode = new Node('$', left->freq + right->freq); // $ = internal node
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    // Step 3: Print Huffman codes
    cout << "Huffman Codes:\n";
    printCodes(pq.top(), "");
}

int main() {
    vector<char> chars = {'a', 'b', 'c', 'd', 'e', 'f'};
    vector<int> freq = {5, 9, 12, 13, 16, 45};

    huffmanCoding(chars, freq);

    return 0;
}
