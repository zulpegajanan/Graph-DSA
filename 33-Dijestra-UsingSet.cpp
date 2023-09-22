
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
#include <set>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        set<pair<int, int>> st;
        vector<int> dist(V, INT_MAX);
        dist[S] = 0;
        st.insert({0, S});

        while (!st.empty()) {
            auto itr = *st.begin();
            st.erase(st.begin());
            int d = itr.first;
            int node = itr.second;
            for (auto it : adj[node]) {
                int nodenbr = it[0];
                int nodeweight = it[1];
                if (d + nodeweight < dist[nodenbr]) {
                    dist[nodenbr] = d + nodeweight;
                    st.insert({dist[nodenbr], nodenbr});
                }
            }
        }

        return dist;
    }
};

int main() {
    int V = 5; // Number of vertices
    int S = 0; // Source vertex

    vector<vector<int>> adj[V]; // Adjacency list representation of the graph

    // Add edges to the adjacency list
    adj[0].push_back({{1, 2}});
    adj[0].push_back({{2, 4}});
    adj[1].push_back({{2, 1}});
    adj[1].push_back({{3, 7}});
    adj[2].push_back({{3, 3}});
    adj[2].push_back({{4, 5}});
    adj[3].push_back({{4, 2}});

    Solution obj;
    vector<int> shortestDistances = obj.dijkstra(V, adj, S);

    cout << "Shortest distances from vertex " << S << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << ": " << shortestDistances[i] << endl;
    }

    return 0;
}

