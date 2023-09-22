
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
 int isNegativeWeightCycle(int V, vector<vector<int>>edges){
        // Code here
        vector<int>dist(V,1e8);
        for(int i=0;i<V;i++){
            dist[i] =0;
            for(auto it : edges){
                int u = it[0];
                int v = it[1];
                int edW = it[2];
                
                if( dist[u] != 1e8 && dist[u] + edW < dist[v])
                dist[v] = dist[u] + edW;
            }
        }
        for(int i=0;i<V;i++){
            for(auto it : edges){
                int u = it[0];
                int v = it[1];
                int edW = it[2];
                
                if( dist[u] != 1e8 && dist[u] + edW < dist[v])
                return 1;
            }
        }
        return 0;
    }
int main() {
    int V = 4; // Number of vertices

    vector<vector<int>> edges; // Edges of the graph
    edges.push_back({0, 1, -1});
    edges.push_back({1, 2, -1});
    edges.push_back({2, 3, -1});
    edges.push_back({3, 0, -1});

    int hasNegativeCycle = isNegativeWeightCycle(V, edges);
    if (hasNegativeCycle)
        cout << "Case 1: The graph contains a negative weight cycle." << endl;
    else
        cout << "Case 2: The graph does not contain a negative weight cycle." << endl;

    return 0;
}

