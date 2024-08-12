#include<bits/stdc++.h>
using namespace std;

class TreeDiameter {
public:

    static void heightFinder(vector<vector<long long>> &adj,long long src,long long par,vector<long long> &height) {
        bool leaf = true;
        long long maxHeightChild = 0;
        for(long long child:adj[src]) {
            if(child != par) {
                leaf = false;
                heightFinder(adj,child,src,height);
                maxHeightChild = max(maxHeightChild, height[child]);
            }
        }

        if(leaf) {
            height[src] = 0;
        } else {
            height[src] = 1+maxHeightChild;
        }
    }

    static void solver(vector<vector<long long>> &adj,long long src,long long par,vector<long long> &height,vector<long long> &ans) {
        vector<long long> childHts;

        for(long long child: adj[src]) {
            if(child != par) {
                solver(adj,child,src,height,ans);
                childHts.push_back(height[child]);
                ans[src] = max(ans[src],ans[child]);
            }
        }

        sort(childHts.begin(),childHts.end());
        if(childHts.size()==1) {
            ans[src] = max(ans[src],1+childHts[childHts.size()-1]);
        } else if(childHts.size()>=2) {
            ans[src] = max(ans[src],2+childHts[childHts.size()-1]+childHts[childHts.size()-2]);
        }
    }

    static long long diameter(long long numNodes,vector<vector<long long>> edges) {
        vector<vector<long long>> adj(numNodes+1);

        for(vector<long long> edge:edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<long long> ans(numNodes+1,0);
        vector<long long> height(numNodes+1,0);

        heightFinder(adj,1,0,height);
        solver(adj,1,0,height,ans);
        return ans[1];
    }
};

class TreeDiameterOptimized{
public:

    static void heightFinder(vector<vector<long long>> &adj,long long src,long long par,vector<long long> &height) {
        bool leaf = true;
        long long maxHeightChild = 0;
        for(long long child:adj[src]) {
            if(child != par) {
                leaf = false;
                heightFinder(adj,child,src,height);
                maxHeightChild = max(maxHeightChild, height[child]);
            }
        }

        if(leaf) {
            height[src] = 0;
        } else {
            height[src] = 1+maxHeightChild;
        }
    }

    static void solver(vector<vector<long long>> &adj,long long src,long long par,vector<long long> &height,vector<long long> &ans) {
        long long maxHeightedChild=-1, secondMaxHeightedChild=-1;

        for(long long child: adj[src]) {
            if(child != par) {
                solver(adj,child,src,height,ans);
                if(height[child]>maxHeightedChild) {
                    secondMaxHeightedChild = maxHeightedChild;
                    maxHeightedChild = height[child];
                } else if(height[child]>secondMaxHeightedChild) {
                    secondMaxHeightedChild = height[child];
                }

                ans[src] = max(ans[src],ans[child]);
            }
        }

        if (maxHeightedChild != -1 && secondMaxHeightedChild != -1) {
            ans[src] = max(ans[src],maxHeightedChild + secondMaxHeightedChild + 2);
        } else if (maxHeightedChild != -1) {
            ans[src] = max(ans[src],maxHeightedChild + 1);
        }
    }

    static long long diameter(long long numNodes,vector<vector<long long>> edges) {
        vector<vector<long long>> adj(numNodes+1);

        for(vector<long long> edge:edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<long long> ans(numNodes+1,0);
        vector<long long> height(numNodes+1,0);

        heightFinder(adj,1,0,height);
        solver(adj,1,0,height,ans);
        return *max_element(ans.begin(),ans.end());
    }
};

class TreeDiameterBestOptimized {
public:

    static long long solver(long long src, long long par, vector<vector<long long>> &adj, long long &ans) {
        long long maxdchild1=0,maxdchild2=0;

        for(long long child:adj[src]){
            if(child!=par) {
                long long childDiam = solver(child, src, adj, ans);
                if(childDiam>=maxdchild1){
                    maxdchild2=maxdchild1;
                    maxdchild1=childDiam;
                } else if(childDiam>=maxdchild2){
                    maxdchild2=childDiam;
                }
            }
        }

        ans = max(ans,maxdchild1+maxdchild2);
        return maxdchild1+1;

    }

    static long long diameter(long long numNodes,vector<vector<long long>> edges) {
        vector<vector<long long>> adj(numNodes+1);

        for(vector<long long> edge:edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        long long ans = INT_MIN;
        solver(1,0,adj,ans);

        return ans;
    }
};