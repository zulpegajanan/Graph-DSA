
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


// https://bit.ly/3oT9Ndg

// 0 represent water
// 1 represent land

// 0 1 1 0 
// 0 1 1 0
// 0 0 1 0
// 0 0 0 0
// 1 1 0 1

//ans=3



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void bfs(int row, int col, vector<vector<int>> &vis,vector<vector<char>>& grid){
        vis[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});
        int n=grid.size();
        int m=grid[0].size();

        while(!q.empty()){
            // current co-ordinate
            int crow = q.front().first;
            int ccol = q.front().second;
            q.pop();

            // expand all 8 neighbour
            for(int drow=-1;drow<2;drow++){
                for(int dcol=-1;dcol<2;dcol++){
                    int nbr_row = drow + crow;
                    int nbr_col = dcol + ccol;
                    if(nbr_row >=0 && nbr_row < n && nbr_col>=0  && nbr_col<m){
                        if(grid[nbr_row][nbr_col]=='1' && vis[nbr_row][nbr_col]==0){
                            vis[nbr_row][nbr_col]=1;
                            q.push({nbr_row,nbr_col});

                        }
                    }
                }
            }

        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int count=0;

        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(!vis[row][col] && grid[row][col]=='1'){
                    count++;
                    bfs(row,col,vis,grid);
                }
            }
        }
        return count;
    }
};


int main() {
    vector<vector<char>> grid = {
        {'0', '1', '1', '0'},
        {'0', '1', '1', '0'},
        {'0', '0', '1', '0'},
        {'0', '0', '0', '0'},
        {'1', '1', '0', '1'}
    };

    Solution solution;
    int numIslands = solution.numIslands(grid);
    cout << "Number of islands: " << numIslands << endl;

    return 0;
}


//space complexity
//O (N*N)
//
//time complexity
//n^2 + (n^2)*8  = n^2 

