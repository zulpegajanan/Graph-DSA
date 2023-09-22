
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

class Solution {
public:

    int n,m;

    void dfs(int row,int col,vector<vector<int>>& vis,vector<vector<char>>& mat){
        vis[row][col]=1;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};

        for(int i=0;i<4;i++){
            int nrow = delrow[i] + row;
            int ncol = delcol[i] + col;

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                if(!vis[nrow][ncol] && mat[nrow][ncol]=='O'){
                    dfs(nrow,ncol,vis,mat);
                }
            }
        }
    }

    void solve(vector<vector<char>>& mat){
        n=mat.size();
        m=mat[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        //for row
        for(int j=0;j<m;j++){
            // first row
            if(!vis[0][j] && mat[0][j]=='O'){  
                dfs(0,j,vis,mat);
            }
            //last row
            if(!vis[n-1][j] && mat[n-1][j]=='O'){
                dfs(n-1,j,vis,mat);
            }
        }


        //for col
        for(int i=0;i<n;i++){
            // first col
            if(!vis[i][0] && mat[i][0]=='O'){  
                dfs(i,0,vis,mat);
            }
            //last row
            if(!vis[i][m-1] && mat[i][m-1]=='O'){
                dfs(i,m-1,vis,mat);
            }
        }

        //convert valid 'O' into 'X'
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && mat[i][j]=='O'){
                    mat[i][j] = 'X';
                }
            }
        }
    } 
};



int main() {
    vector<vector<char>> mat = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };

    Solution sol;
    sol.solve(mat);

    for (const auto& row : mat) {
        for (char c : row) {
            cout << c << " ";
        }
        cout << endl;
    }

    return 0;
}


//time complexity
//O (n*m)*4  + O (m) + O (N)
//
//space complexity
//O (n*m)

