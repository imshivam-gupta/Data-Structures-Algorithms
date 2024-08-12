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
        adj.resize(numOfVertices,vector<int>(numOfVertices,0));
    }

    void addEdge(int startNode,int endNode) {
        if(startNode>=numOfVertices || endNode>=numOfVertices) {
            cout << "Sorry out of bound vertex selected" << endl;
            return;
        }

        adj[startNode][endNode] = 1;
        adj[endNode][startNode] = 1;
    }

    void visualiseGraph() {
        cout << "Adjacency Matrix Representation of the Graph:" << endl;
        for(int i = 0; i < numOfVertices; ++i) {
            for(int j = 0; j < numOfVertices; ++j) {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }

        cout << "\nList of Edges:" << endl;
        for(int i = 0; i < numOfVertices; ++i) {
            for(int j = i+1; j < numOfVertices; ++j) {
                if(adj[i][j] == 1) {
                    cout << "(" << i << ", " << j << ")" << endl;
                }
            }
        }
    }
};