#include<bits/stdc++.h>
using namespace std;

class Monsters {
public:
    vector<string> pathFinder(vector<string> grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int,int>> q;

        int startX, startY;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]=='A') {
                    startX = i, startY = j;
                } else if(grid[i][j]=='M') {
                    q.push({i,j});
                }
            }
        }


        return {"NO"};
    }
};
