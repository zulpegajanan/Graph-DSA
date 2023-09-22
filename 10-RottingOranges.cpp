
/*
zzzzzzzzzz    uuu       uuu    lll          pppppppp        eeeeeeee
zzzzzzzzzz    uuu       uuu    lll          ppp    ppp      eeeeeeee
       zzz    uuu       uuu    lll          ppp      ppp    eee
     zzz      uuu       uuu    lll          ppp       ppp   eee
    zzz       uuu       uuu    lll          ppp      ppp    eeeeeeee
   zzz        uuu       uuu    lll          ppp    ppp      eeeeeeee
  zzz         uuu       uuu    lll          pppppppp        eee
zzz            uuu     uuu     lll          ppp             eee
zzzzzzzzzz      uuu   uuu      lllllllll    ppp             eeeeeeee
zzzzzzzzzz         uuu         lllllllll    ppp             eeeeeeee
*/

/*

https://leetcode.com/problems/rotting-oranges/

You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

*/


#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
int n, m;
int delRow[4] = {-1, 0, 1, 0};
int delCol[4] = {0, 1, 0, -1};

int orangesRotting(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        queue<pair<pair<int, int>, int>> q;   //q[[x,y],time]
        vector<vector<int>> vis;

        vis.resize(n, vector<int>(m, 0)); // Resize and initialize vis vector

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
                else {
                    vis[i][j] = 0;
                }
            }
        }

        int tn = 0;
        while(!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tn = max(tn, t);
            q.pop();
            for(int i = 0; i < 4; i++) {
                int nrow = r + delRow[i];
                int ncol = c + delCol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1) {
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 2;
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(vis[i][j] != 2 && grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return tn;
    }



int main() {
    vector<vector<int>> grid = {
        {2, 1, 1},
        {0, 1, 1},
        {1, 0, 1}
    };
    int counto = orangesRotting(grid);
    cout<<"case 01: "<<counto<<endl;
    
    
    vector<vector<int>> grid2 = {
        {2, 1, 1},
        {0, 1, 1},
        {0, 0, 1}
    };
    int counto2 = orangesRotting(grid2);
    cout<<"case 02: "<<counto2<<endl;
    
    
    return 0;
}


