
//This question is about to count number of subgraph in given graph

//imp  what will be time complexity

//  https://bit.ly/3yR3dIB



#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

void countSubgraphWithBfs(int V, vector<int> adj[]) {
    int vis[V] = {0};
    queue<int> q;

    for (int i = 0; i < V; i++) {
        if (vis[i] == 0) {
            cnt++;
            q.push(i);
            vis[i] = 1;

            while (!q.empty()) {
                int front = q.front();
                q.pop();

                for (auto it : adj[front]) {
                    if (vis[it] == 0) {
                        q.push(it);
                        vis[it] = 1; // Mark the node as visited
                    }
                }
            }
        }
    }
}

int main() {
    int V = 8; // Number of vertices in the graph

    // Adjacency list representation of the graph
    vector<int> adj[V];
    adj[0] = {1};     //gp1
    adj[1] = {0, 2};  //gp1
    adj[2] = {1};     //gp1
    adj[3] = {4};     //gp2
    adj[4] = {3, 5};  //gp2
    adj[5] = {4};     //gp2
    adj[6] = {7};     //gp3
    adj[7] = {6};     //gp3

    countSubgraphWithBfs(V, adj);

    cout << "number of disconnected graph: " << cnt << endl;

    return 0;
}

//
//space complexity O (N) + O (N)
//time complexity : O (N) * O (V+2E) wrong 
//                  O (N) + O (V+2E)  correct 
                  
//WHY ? :                   
//if when all node are single then there is no adj node 
//that why O(N)
