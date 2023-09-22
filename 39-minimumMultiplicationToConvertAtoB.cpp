
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

using namespace std;

class Solution {
public:
    int mod = 100000;
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        queue<pair<int,int>> q;
        q.push({0,start});
        vector<int> dist(1e5,1e9);
        //as starting distance is 0;
        dist[start] = 0;
        while(!q.empty()){
            auto it = q.front();
            int op = it.first;
            int from = it.second;
            if(from==end) return op;
            q.pop();
            for(int i = 0;i<arr.size();i++){
                int to = (from*arr[i])%mod;
                if(op+1<dist[to]){
                    dist[to] = op + 1;
                    q.push({op+1,to});
                }
            }
        }
        return dist[end]==1e9?-1:dist[end];
    }
};

int main() {
    Solution solution;
    vector<int> arr = {2, 3, 5};
    int start = 2;
    int end = 11;
    int result = solution.minimumMultiplications(arr, start, end);
    cout << "Minimum multiplications required: " << result << endl;
    return 0;
}


