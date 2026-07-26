#include <iostream>
#include <queue>
using namespace std;

struct Node {
    char ch; 
    int freq; 
    Node *left, *right;
    
    Node(char c, int f, Node* l = NULL, Node* r = NULL) : ch(c), freq(f), left(l), right(r) {}
};

struct comp {
    bool operator()(Node* l, Node* r) { return l->freq > r->freq; }
};

void print(Node* root, string str) {
    if (!root) return;
    if (root->ch != '$') cout << root->ch << ": " << str << "\n";
    print(root->left, str + "0");
    print(root->right, str + "1");
}

int main() {
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    
    priority_queue<Node*, vector<Node*>, comp> pq;
    for (int i = 0; i < 6; i++) pq.push(new Node(arr[i], freq[i]));
    
    while (pq.size() > 1) {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();
        pq.push(new Node('$', left->freq + right->freq, left, right));
    }
    
    print(pq.top(), "");
    return 0;
}
