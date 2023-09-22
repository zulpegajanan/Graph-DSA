
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

    bool dfs(int node, int col, int color[],vector<vector<int>>& adj ){
        color[node]=col;
        for(auto it : adj[node]){
            if(color[it]==-1){
                if(dfs(it,!col,color,adj)==false) return false;
            }
            else if(color[it]==col){
                return false;
            }
        }
        return true;
    }


    bool isBipartite(vector<vector<int>>& adj) {
        int V=adj.size();
        int color[V];
        for(int i=0;i<V;i++){
            color[i]=-1;
        }
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(dfs(i,0,color,adj)==false){
                    return false;
                }
            }
        }
        return true;
    }
};


int main() {
    Solution solution;

    vector<vector<int>> adj1 = {
        {1, 3},
        {0, 2},
        {1, 3},
        {0, 2}
    };
    bool isBipartite1 = solution.isBipartite(adj1);
    cout<<"Example1:"<<endl;

    if (isBipartite1) {
        cout << "The graph is bipartite." << endl;
    } else {
        cout << "The graph is not bipartite." << endl;
    }
	
    vector<vector<int>> adj2 = {
        {1, 3},
        {0, 2, 3},
        {1, 3},
        {0, 1, 2}
    };
    bool isBipartite2 = solution.isBipartite(adj2);
    cout<<"Example2:"<<endl;

    if (isBipartite2) {
        cout << "The graph is bipartite." << endl;
    } else {
        cout << "The graph is not bipartite." << endl;
    }

    return 0;
}




