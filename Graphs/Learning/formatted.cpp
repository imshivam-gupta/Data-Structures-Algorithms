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

    vector<int> bfsOfGraph(int V) {
        vector<int> bfs;
        vector<bool> visited(V, false);
        queue<int> q;

        int startNode = 0;
        q.push(startNode);
        visited[startNode] = true;

        while(!q.empty()){
            int currNode = q.front();
            bfs.push_back(currNode);
            q.pop();

            for(int itr : adj[currNode]){
                if(!visited[itr]){
                    q.push(itr);
                    visited[itr] = true;
                }
            }
        }

        return bfs;
    }
};

// int main() {
//     int n, m;
//     cin >> n >> m;
//     Graph g(n, m);
//     for(int i = 0; i < m; i++) {
//         int u, v;
//         cin >> u >> v;
//         g.addEdge(u, v);
//     }
//
//     g.visualiseGraph();
//
//     vector<int> bfsResult = g.bfsOfGraph(n);
//     cout << "BFS Traversal of the Graph:" << endl;
//     for(int i : bfsResult) {
//         cout << i << " ";
//     }
//     cout << endl;
//
//     return 0;
// }
