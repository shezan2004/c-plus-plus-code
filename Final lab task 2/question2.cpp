#include <iostream>
#include <sstream>
using namespace std;


struct Node {
    int value;
    int weight; 
    Node *next;

    Node(int v, int w = -1) {
        value = v;
        weight = w;
        next = NULL;
    }
};


class LinkedList {
private:
    Node *head;

public:
    LinkedList() {
        head = NULL;
    }

    void insert(int value, int weight = -1) {
        Node *newNode = new Node(value, weight);
        newNode->next = head;
        head = newNode;
    }

    string toString(bool isWeighted) {
        stringstream result;
        Node *current = head;
        while (current) {
            if (isWeighted)
                result << "(" << current->value << ", " << current->weight << ") -> ";
            else
                result << current->value << " -> ";
            current = current->next;
        }
        result << "NULL";
        return result.str();
    }
};


class Graph {
private:
    LinkedList *adjList;
    int numVertices;
    bool isWeighted;
    bool isDirected;

public:
    Graph(int vertices, bool weighted = false, bool directed = true) {
        numVertices = vertices;
        isWeighted = weighted;
        isDirected = directed;
        adjList = new LinkedList[vertices];
    }

    ~Graph() {
        delete[] adjList;
    }

    void addEdge(int src, int dest, int weight = 1) {
        adjList[src].insert(dest, isWeighted ? weight : -1);
        if (!isDirected) {
            adjList[dest].insert(src, isWeighted ? weight : -1);
        }
    }

    void display() {
        for (int i = 0; i < numVertices; i++) {
            cout << i << ": " << adjList[i].toString(isWeighted) << endl;
        }
    }
};

int main() {
    cout << "Directed Graph:" << endl;
    Graph directedGraph(5);
    directedGraph.addEdge(0, 1);
    directedGraph.addEdge(0, 4);
    directedGraph.addEdge(1, 2);
    directedGraph.addEdge(1, 3);
    directedGraph.addEdge(1, 4);
    directedGraph.display();

    cout << "\nUndirected Graph:" << endl;
    Graph undirectedGraph(5, false, false);
    undirectedGraph.addEdge(0, 1);
    undirectedGraph.addEdge(0, 4);
    undirectedGraph.addEdge(1, 2);
    undirectedGraph.addEdge(1, 3);
    undirectedGraph.addEdge(1, 4);
    undirectedGraph.display();

    cout << "\nDirected Weighted Graph:" << endl;
    Graph directedWeightedGraph(5, true);
    directedWeightedGraph.addEdge(0, 1, 10);
    directedWeightedGraph.addEdge(0, 4, 20);
    directedWeightedGraph.addEdge(1, 2, 30);
    directedWeightedGraph.addEdge(1, 3, 40);
    directedWeightedGraph.addEdge(1, 4, 50);
    directedWeightedGraph.display();

    cout << "\nUndirected Weighted Graph:" << endl;
    Graph undirectedWeightedGraph(5, true, false);
    undirectedWeightedGraph.addEdge(0, 1, 10);
    undirectedWeightedGraph.addEdge(0, 4, 20);
    undirectedWeightedGraph.addEdge(1, 2, 30);
    undirectedWeightedGraph.addEdge(1, 3, 40);
    undirectedWeightedGraph.addEdge(1, 4, 50);
    undirectedWeightedGraph.display();

    return 0;
}
