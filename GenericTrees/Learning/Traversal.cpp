#include<bits/stdc++.h>
using namespace std;

class Traversal {
public:
    void dfs(int node, int par, vector<vector<int>> &adj) {
        cout << node << " ";

        for(int child:adj[node]) {
            if(child == par) continue;
            dfs(child, node, adj);
        }
    }

    void bfs(int root,vector<vector<int>> &adj) {
        queue<pair<int,int>> q;
        q.push({root,0});

        while(q.empty()==false) {
            int node = q.front().first;
            int par = q.front().second;
            cout << node << " ";
            q.pop();
            for(auto child: adj[node]) {
                if(child==par) {
                    continue;
                }

                q.push({child,node});
            }
        }
    }
};

int main() {
    int n; cin >> n;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<n-1;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Traversal t;
    t.bfs(1,adj);
    cout << " \n";
    t.dfs(1,0,adj);
}
