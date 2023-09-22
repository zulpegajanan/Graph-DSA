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
#include <stack>

using namespace std;

void dfs(vector<vector<int>>& graph, int v, vector<bool>& visited, vector<int>& traversal) {
    visited[v] = true;
    traversal.push_back(v);

    for (int neighbor : graph[v]) {
        if (!visited[neighbor]) {
            dfs(graph, neighbor, visited, traversal);
        }
    }
}

vector<int> dfsTraversal(int numVertices, vector<pair<int, int>>& edges) {
    vector<vector<int>> graph(numVertices);
    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> visited(numVertices, false);
    vector<int> traversal;
    dfs(graph, 0, visited, traversal);
    return traversal;
}

int main() {
    // Input
    int numVertices = 10;
    vector<pair<int, int>> edges = {
        {0, 1}, {0, 2}, {0, 4}, {0, 8},
        {1, 5}, {1, 6}, {1, 9},
        {2, 4},
        {3, 7}, {3, 8},
        {5, 8},
        {6, 7}, {6, 9}
    };

    // Perform DFS traversal
    vector<int> result = dfsTraversal(numVertices, edges);

    // Print the correct output
    for (int vertex : result) {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}



