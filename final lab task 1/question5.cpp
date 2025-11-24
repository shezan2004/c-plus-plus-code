#include <iostream>
#include <queue>
#include <map>
#include <string>
using namespace std;


struct Node {
    char character;
    int frequency;
    Node* left;
    Node* right;

    Node(char c, int f) {
        character = c;
        frequency = f;
        left = NULL;
        right = NULL;
    }
};


struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->frequency > b->frequency;
    }
};


void printCodes(Node* root, string code, map<char, string>& huffmanCodes) {
    if (!root) return;

    if (!root->left && !root->right) {
        huffmanCodes[root->character] = code;
    }

    printCodes(root->left, code + "0", huffmanCodes);
    printCodes(root->right, code + "1", huffmanCodes);
}


void huffmanCoding(const map<char, int>& frequencies) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (map<char, int>::const_iterator it = frequencies.begin(); it != frequencies.end(); ++it) {
        pq.push(new Node(it->first, it->second));
    }

    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();

        Node* sumNode = new Node('\0', left->frequency + right->frequency);
        sumNode->left = left;
        sumNode->right = right;

        pq.push(sumNode);
    }

    Node* root = pq.top();
    map<char, string> huffmanCodes;
    printCodes(root, "", huffmanCodes);

    cout << "Huffman Codes:\n";
    for (map<char, string>::iterator it = huffmanCodes.begin(); it != huffmanCodes.end(); ++it) {
        cout << it->first << ": " << it->second << endl;
    }
}

int main() {
    map<char, int> frequencies;

    int n;
    cout << "Enter the number of characters: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        char character;
        int frequency;
        cout << "Enter character and its frequency: ";
        cin >> character >> frequency;
        frequencies[character] = frequency;
    }

    huffmanCoding(frequencies);

    return 0;
}
