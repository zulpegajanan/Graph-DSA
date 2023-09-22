#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    void dfs2(int node, vector<int>& vis, vector<vector<int>>& adj,vector<int>& temp) {
        vis[node] = 1;
        temp.push_back(node);
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs2(it, vis, adj,temp);
            }
        }
    }
    
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adj, stack<int>& st) {
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, vis, adj, st);
            }
        }
        st.push(node);
    }
    
    int kosaraju(int V, vector<vector<int>>& adj) {
        vector<int> vis(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, adj, st);
            }
        }
    
        vector<vector<int>> adjR(V);
        vector<int> visR(V, 0);
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                adjR[it].push_back(i);
            }
        }
    	vector<vector<int>> ans;
        int scc = 0;
        while (!st.empty()) {
            int tp = st.top();
            st.pop();
            
            if (!visR[tp]) {
            	vector<int> temp;
                dfs2(tp, visR, adjR,temp);
                scc++;
                ans.push_back(temp);
            }
        }
        
        cout<<endl<<"Strongly Connected Components - Kosaraju's Algorithm"<<endl;
        for(auto it: ans){
        	for(auto itt:it){
        		cout<<itt<<" ";
			}
			cout<<endl;
		}
		
		int maxCycle=0;
		for(int i=0;i<ans.size();i++){
			int sz = ans[i].size();
			maxCycle=max(maxCycle,sz);
		}
		cout<<"maximum cycle length : "<<maxCycle<<endl;
		
		
        return scc;
    }
};

int main() {
    int V=8, E=10;
    cout << "Enter the number of vertices: ";
    cout << V<<endl;
    cout << "Enter the number of edges: ";
    cout << E<<endl;
    
    vector<vector<int>> adj(V);
    cout << "Enter the edges (source and destination):" << endl;

    
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(3);
    adj[3].push_back(4);
    adj[4].push_back(7);
    adj[6].push_back(7);
    adj[6].push_back(4);
    adj[5].push_back(6);
    adj[4].push_back(5);
    
    
    for (int i = 0; i < V; i++) {
        cout<<i<<"==>";
        for(auto it:adj[i]){
        	cout<<it<<" ";
		}
		cout<<endl;
    }
    
    
    Solution obj;
    int num_scc = obj.kosaraju(V, adj);
    
    cout << "Number of Strongly Connected Components: " << num_scc << endl;

    return 0;
}

