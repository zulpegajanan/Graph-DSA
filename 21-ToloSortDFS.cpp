
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

class Solution
{
	public:
	
	void dfs(int node,int vis[],stack<int>& st,vector<int> adj[]){
	    vis[node]=1;
	    
	    for(auto it:adj[node]){
	        if(!vis[it]){
	            dfs(it,vis,st,adj);
	        }
	    }
	   st.push(node);
	}
	
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[])
	{
	    // code here
	    int vis[V]={0};
	    stack<int> res;
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            dfs(i,vis,res,adj);
	        }
	    }
	    vector<int> ans;
	    while(!res.empty()){
	        ans.push_back(res.top());
	        res.pop();
	    }
	    return ans;
	}
};

int main() {
    int V = 6; // number of vertices
    vector<int> adj[V];

    // Add edges to the adjacency list
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    Solution obj;
    vector<int> result = obj.topoSort(V, adj);

    // Print the vertices in topological order
    cout << "Topological order: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
