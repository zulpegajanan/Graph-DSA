
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

using namespace std;

void BellmanFord(int n, vector<vector<int>>& edges) {
    vector<int> dist(n, INT_MAX);
    dist[0] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int d = it[2];

            if (dist[u] != INT_MAX && dist[u] + d < dist[v]) {
                dist[v] = dist[u] + d;
            }
        }
        cout<<"\n at "<<i+1 << "leve"<<endl;
        for(int ele :dist){
        	if(ele==INT_MAX){
        		cout<<-1<<" ";
			}
			else{
				cout<<ele<<" ";
			}
        	
		}
    }

    
}

int main() {
    int n,m; // Number of vertices
    cout << "Enter the number of vertices: ";
    cin >> n;
	cout << "Enter the number of edges: ";
    cin >> m;
    vector<vector<int>> edges; // Edges of the graph
    cout << "Enter the edges (u, v, d):" << endl;
    for (int i = 0; i < m ; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        edges.push_back({u, v, d});
    }

    BellmanFord(n, edges);
    

    return 0;
}


