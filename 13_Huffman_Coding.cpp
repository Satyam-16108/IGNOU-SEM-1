#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    unsigned freq;
    Node *left, *right;
    Node(char d, unsigned f) {
        left = right = NULL;
        data = d;
        freq = f;
    }
};

struct compare {
    bool operator()(Node* l, Node* r) { return (l->freq > r->freq); }
};

void printCodes(struct Node* root, string str) {
    if (!root) return;
    if (root->data != '$') cout << root->data << ": " << str << "\n";
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

void HuffmanCodes(char data[], int freq[], int size) {
    priority_queue<Node*, vector<Node*>, compare> minHeap;
    for (int i = 0; i < size; ++i)
        minHeap.push(new Node(data[i], freq[i]));

    while (minHeap.size() != 1) {
        Node *left = minHeap.top(); minHeap.pop();
        Node *right = minHeap.top(); minHeap.pop();
        Node *top = new Node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }
    printCodes(minHeap.top(), "");
}

int main() {
    char arr[] = { 'A', 'B', 'I', 'M', 'S', 'X', 'Z' };
    int freq[] = { 10, 7, 15, 8, 10, 5, 2 };
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Huffman Codes:\n";
    HuffmanCodes(arr, freq, size);
    return 0;
}
