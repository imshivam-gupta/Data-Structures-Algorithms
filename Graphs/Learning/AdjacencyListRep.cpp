#include<bits/stdc++.h>
using namespace std;

class Graph{
private:
    int numOfVertices;
    int numOfEdges;
    vector<vector<int>> adj;

public:
    Graph(int numOfVertices,int numOfEdges) {
        this->numOfEdges = numOfEdges;
        this->numOfVertices = numOfVertices;
        adj.resize(numOfVertices);
    }

    void addEdge(int startNode,int endNode) {
        if(startNode>=numOfVertices || endNode>=numOfVertices) {
            cout << "Sorry out of bound vertex selected" << endl;
            return;
        }

        adj[startNode].push_back(endNode);
        adj[endNode].push_back(startNode);
    }

    void visualiseGraph() {
        cout << "Adjacency List Representation of the Graph:" << endl;
        for(int i = 0; i < numOfVertices; ++i) {
            cout << i << ": ";
            for(int j : adj[i]) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};