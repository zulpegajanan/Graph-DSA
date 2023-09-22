
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
//set<string> st;
void solve(int ind, string num, vector<char>& ans) {
    if (ind >= num.size()) {
        string ss(ans.begin(), ans.end());
        cout << ss << " ";
//			st.insert(ss);
        return;
    }
    ans.push_back(num[ind]);
    solve(ind + 1, num, ans);
    if (ind + 1 < num.size()) {
        int val = (num[ind] - '0') * 10 + (num[ind + 1] - '0');
        if (val <= 26) {
            ans.push_back(num[ind + 1]);
            solve(ind + 2, num, ans);
        }
    }
    ans.pop_back(); 
}

int main() {
    int num = 520103;
    string str = to_string(num);
    vector<char> ans;
    solve(0, str, ans);
//    cout<<st.size();
    return 0;
}

