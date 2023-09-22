
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

class Solution{
    public:
    
    vector<int> topoSort(int V,vector<int> adj[]){
        vector<int> indegree(V,0);
        for(int i=0;i<V;i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
            
        }
        
        return topo;
    }
    
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int> adj[K];
        
        for(int i=0;i<N-1;i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            int len = min(s1.size(),s2.size());
            for(int j=0;j<len;j++){
                if(s1[j]!=s2[j]){
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
            
        }
        
        
        vector<int> ans= topoSort(K,adj);
        string strr;
        for(int i=0;i<ans.size();i++){
            strr.push_back(char(ans[i]+'a'));
        }
        return strr;
    }
};


int main() {
    int N, K;
    cout << "Enter the number of words: ";
    cin >> N;
    cout << "Enter the number of alphabets: ";
    cin >> K;
    
    string dict[N];
    
    for (int i = 0; i < N; i++) {
    	cout << "Enter the word"<<" "<<i<<" : ";
        cin >> dict[i];
    }
    
    Solution obj;
    string order = obj.findOrder(dict, N, K);
    
    cout << "The order of alphabets: " << order << endl;

    return 0;
}
