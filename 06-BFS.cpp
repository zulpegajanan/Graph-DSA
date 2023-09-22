
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

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    int vis[V] = {0};
    queue<int> q;
    vector<int> bfs;

    q.push(0);
    vis[0] = 1;

    while (!q.empty()) {
        int front = q.front();
        q.pop();
        bfs.push_back(front);

        for (auto it : adj[front]) {
            if (vis[it] == 0) {
                q.push(it);
                vis[it] = 1; // Mark the node as visited
            }
        }
    }

    return bfs;
}


int main() {
    int V = 5; // Number of vertices in the graph

    // Adjacency list representation of the graph
    vector<int> adj[V];
    adj[0] = {1, 2};
    adj[1] = {2, 3};
    adj[2] = {3, 4};
    adj[3] = {4};
    adj[4] = {};

    vector<int> bfsTraversal = bfsOfGraph(V, adj);

    cout << "BFS Traversal: ";
    for (int node : bfsTraversal) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}

