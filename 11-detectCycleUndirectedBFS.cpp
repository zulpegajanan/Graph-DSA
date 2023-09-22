
/*
zzzzzzzzzz    uuu       uuu    lll          pppppppp        eeeeeeee
zzzzzzzzzz    uuu       uuu    lll          ppp    ppp      eeeeeeee
      zzz     uuu       uuu    lll          ppp      ppp    eee
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

bool detect(int src, vector<int> adj[], int vis[]) {
    vis[src] = 1;
    queue<pair<int, int>> q;
    q.push({src, -1});

    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for (auto adjcent : adj[node]) {
            if (vis[adjcent] == 0) {
                vis[adjcent] = 1;
                q.push({adjcent, node});
            } else if (parent != adjcent) {
                // yes, this is a cycle
                return true;
            }
        }
    }
    return false;
}

int main() {
    // Creating the graph
    int V = 10;
    vector<int> adj[V];

    // Adding edges to the graph
    adj[0] = {1, 2};
    adj[1] = {0, 2};
    adj[2] = {0, 1, 3};
    adj[3] = {2, 4};
    adj[4] = {3, 5};
    adj[5] = {4, 6};
    adj[6] = {5, 7};
    adj[7] = {6, 8};
    adj[8] = {7, 9};
    adj[9] = {8};

    // Array to track visited nodes
    int vis[V] = {0};

    // Detecting cycles in the graph
    bool hasCycle = false;
    for (int i = 0; i < V; i++) {
        if (vis[i] == 0) {
            if (detect(i, adj, vis)) {
                hasCycle = true;
                break;
            }
        }
    }

    // Printing the result
    if (hasCycle) {
        cout << "The graph contains a cycle." << endl;
    } else {
        cout << "The graph does not contain a cycle." << endl;
    }

    return 0;
}

//TC
//O(V+2E) {2E summetion of degree} + O(V) {for loop in main}

//SC
//O(V)




