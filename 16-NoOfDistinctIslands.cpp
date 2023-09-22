
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


#include <bits/stdc++.h>
using namespace std;



int m,n;

class Solution {
  public:
  
    void dfs(int row,int col,int row0,int col0,vector<vector<int>>& vis ,vector<vector<int>>& grid,vector<pair<int,int>>& vec){
        vis[row][col]=1;
        vec.push_back({col-col0 , row-row0});
        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0,-1,0,1};
        
        for(int i=0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            
            if(nrow<n && nrow>=0 && ncol>=0 && ncol<m){
                if(!vis[nrow][ncol] && grid[nrow][ncol]==1){
                    dfs(nrow,ncol,row0,col0,vis,grid,vec);
                }
            }
        }
        
    }
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        n= grid.size();
        m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>> st;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]){
                    vector<pair<int,int>> vec;
                    dfs(i,j,i,j,vis,grid,vec);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};

int main() {
    vector<vector<int>> grid = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 1, 1}
    };

    Solution solution;
    int distinctIslands = solution.countDistinctIslands(grid);

    cout << "Number of distinct islands: " << distinctIslands << endl;

    return 0;
}



//time complexity
//n*m*log(set length=n*m) + m*m*4;
