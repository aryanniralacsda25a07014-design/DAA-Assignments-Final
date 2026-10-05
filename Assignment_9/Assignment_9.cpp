#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

// Node of Huffman Tree
struct Node {
    char data;
    int freq;
    Node *left, *right;

    Node(char data, int freq) {
        this->data = data;
        this->freq = freq;
        left = right = NULL;
    }
};

// Comparator for Min Heap
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Generate Huffman Codes
void generateCodes(Node* root, string code,
                   unordered_map<char, string>& huffmanCode) {

    if (root == NULL)
        return;

    // Leaf node
    if (root->left == NULL && root->right == NULL) {
        huffmanCode[root->data] = code;
        return;
    }

    generateCodes(root->left, code + "0", huffmanCode);
    generateCodes(root->right, code + "1", huffmanCode);
}

int main() {

    string text = "ABRACADABRA";

    // Calculate frequency
    unordered_map<char, int> freq;

    for (char ch : text)
        freq[ch]++;

    // Min Heap
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Insert all characters
    for (auto x : freq) {
        pq.push(new Node(x.first, x.second));
    }

    // Build Huffman Tree
    while (pq.size() > 1) {

        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();

        Node* newNode = new Node('$', left->freq + right->freq);

        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    // Root of Huffman Tree
    Node* root = pq.top();

    // Generate codes
    unordered_map<char, string> huffmanCode;

    generateCodes(root, "", huffmanCode);

    // Display codes
    cout << "Huffman Codes:\n";

    for (auto x : huffmanCode) {
        cout << x.first << " : " << x.second << endl;
    }

    // Encode the string
    string encoded = "";

    for (char ch : text)
        encoded += huffmanCode[ch];

    cout << "\nOriginal String: " << text << endl;
    cout << "Encoded String : " << encoded << endl;

    return 0;
}
