
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

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& a) {
        vector<pair<long long, long long>> adj[n];
        // it -> from to weight
        for(auto it:a){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        vector<long long> ways(n, 0);
        vector<long long> dist(n, LONG_MAX);
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq; // dist node
        pq.push({0, 0});
        dist[0] = 0;
        ways[0] = 1;
        while(!pq.empty()){
            long long d = pq.top().first;
            long long node = pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                long long wt = it.second;
                long long adjnode = it.first;
                if(d + wt < dist[adjnode]){
                    dist[adjnode] = d + wt;
                    ways[adjnode] = ways[node];
                    pq.push({ dist[adjnode], adjnode});
                }
                else if(d + wt == dist[adjnode])
                         ways[adjnode]=((ways[adjnode] % 1000000007 + ways[node]) % 1000000007) % 1000000007;
            }
        }
        return ways[n - 1] % 1000000007;
    }
};

int main() {
    int n; // Number of nodes
    cin >> n;
    vector<vector<int>> a; // Edges and weights
    for (int i = 0; i < n; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        a.push_back({from, to, weight});
    }

    Solution solution;
    int result = solution.countPaths(n, a);
    cout << "Number of ways to reach node " << n - 1 << ": " << result << endl;

    return 0;
}

