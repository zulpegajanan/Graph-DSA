
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
#include <queue>
#include <climits>

using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, INT_MAX);
    dist[S] = 0;
    pq.push({0, S});

    while (!pq.empty()) {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node]) {
            int d = it[1];
            int nbr = it[0];
            if (d + dis < dist[nbr]) {
                dist[nbr] = d + dis;
                pq.push({dist[nbr], nbr});
            }
        }
    }
    return dist;
}

int main() {
    int V = 5;  // Number of vertices
    vector<vector<int>> adj[V];  // Adjacency list representation of the graph

    // Adding edges to the graph
    adj[0].push_back({1, 1});  // Edge from node 0 to node 1 with weight 1
    adj[0].push_back({2, 4});  // Edge from node 0 to node 2 with weight 4
    adj[1].push_back({2, 2});  // Edge from node 1 to node 2 with weight 2
    adj[1].push_back({3, 5});  // Edge from node 1 to node 3 with weight 5
    adj[2].push_back({3, 1});  // Edge from node 2 to node 3 with weight 1
    adj[2].push_back({4, 3});  // Edge from node 2 to node 4 with weight 3
    adj[3].push_back({4, 2});  // Edge from node 3 to node 4 with weight 2

    int startNode = 0;  // Starting node for Dijkstra's algorithm

    vector<int> shortestDistances = dijkstra(V, adj, startNode);

    cout << "Shortest distances from node " << startNode << ":" << endl;
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << ": " << shortestDistances[i] << endl;
    }

    return 0;
}

