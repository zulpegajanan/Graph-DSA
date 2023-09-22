
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


#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src) {
        // create adj list
        vector<int> adj[N];
        // Undirected Graph
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int Dist[N];
        for (int i = 0; i < N; i++) {
            Dist[i] = INT_MAX;
        }

        Dist[src] = 0;
        queue<int> q;
        q.push(src);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto it : adj[node]) {
                if (Dist[node] + 1 < Dist[it]) {
                    Dist[it] = Dist[node] + 1;
                    q.push(it);
                }
            }
        }

        vector<int> ans(N, -1);
        for (int i = 0; i < N; i++) {
            if (Dist[i] != INT_MAX) {
                ans[i] = Dist[i];
            }
        }
        return ans;
    }
};

int main() {
    int N, M, src;
    cout << "Enter the number of vertices: ";
    cin >> N;
    cout << "Enter the number of edges: ";
    cin >> M;
    cout << "Enter the source vertex: ";
    cin >> src;

    vector<vector<int>> edges(M, vector<int>(2));
    cout << "Enter the edges (vertex1 vertex2):" << endl;
    for (int i = 0; i < M; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    Solution obj;
    vector<int> result = obj.shortestPath(edges, N, M, src);

    cout << "Shortest path distances from source " << src << " to each vertex:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Distance to vertex " << i << ": ";
        if (result[i] == -1) {
            cout << "Not reachable" << endl;
        } else {
            cout << result[i] << endl;
        }
    }

    return 0;
}

