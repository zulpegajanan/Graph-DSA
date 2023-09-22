
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


//Flood Fill Algorithm
// https://leetcode.com/problems/flood-fill/

#include <bits/stdc++.h>
using namespace std;

void dfs(int row,int col,int iniColor,int newColor,vector<vector<int>>& ans,vector<vector<int>>& image){
        
    ans[row][col]=newColor;
    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};
    for(int i=0;i<4;i++){
        int nrow= delrow[i]+row;
        int ncol= delcol[i]+col;
        if(nrow>=0 && ncol>=0 && nrow<ans.size() && ncol<ans[0].size()){
            if(image[nrow][ncol]==iniColor && ans[nrow][ncol] != newColor){
                dfs(nrow,ncol,iniColor,newColor,ans,image);
            }
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int iniColor=image[sr][sc];
    vector<vector<int>>ans = image;
    dfs(sr,sc,iniColor,newColor,ans,image);    
    return ans;    
}


int main() {
    vector<vector<int>> image = {
        {1, 2, 1},
        {1, 3, 3},
        {3, 3, 1}
    };

    int sr = 2;
    int sc = 0;
    int newColor = 9;

    vector<vector<int>> result = floodFill(image, sr, sc, newColor);

    cout << "Modified Image:" << endl;
    for (const auto& row : result) {
        for (const auto& pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }

    return 0;
}

space complexity
O (m*n){ans} + O(m*n){recurdion stack} + O(4) * 2 {delcol+delrow}

time complexity 
O (m*n) + O (m*n) * 4
= O (m*n)


