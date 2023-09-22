
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

vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
    vector<pair<int,int>> adj[n+1]; // one-based indexing

    for(auto it : edges){
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> parent(n+1);
    vector<int> dist(n+1, INT_MAX);

    for(int i=1; i<=n; i++){
        parent[i] = i;
    }

    dist[1] = 0;
    pq.push({0, 1}); // Add the source node to the priority queue

    while(!pq.empty()){
        auto it = pq.top();
        pq.pop(); // Remove the top element from the priority queue
        int node = it.second;
        int dis = it.first;

        // Process the neighboring nodes
        for(auto nbr : adj[node]){
            if(dis + nbr.second < dist[nbr.first]){
                pq.push({dis + nbr.second, nbr.first});
                dist[nbr.first] = dis + nbr.second;
                parent[nbr.first] = node;
            }
        }
    }

    vector<int> neg(1, -1);
    if(dist[n] == INT_MAX)
        return neg;

    vector<int> path;
    int node = n;
    while(parent[node] != node){
        path.push_back(node);
        node = parent[node];
    }

    path.push_back(1);
    reverse(path.begin(), path.end());
    return path;
}


int main() {
    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    vector<vector<int>> edges(m, vector<int>(3));
    cout << "Enter the edges (node1 node2 weight): " << endl;
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    vector<int> shortest = shortestPath(n, m, edges);

    cout << "Shortest path: ";
    for (int node : shortest) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
