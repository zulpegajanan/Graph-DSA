
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

vector<int> solve(int n, int k) {
    vector<int> arr(k, 0);
    for (int i = 1; ; i++) {
        int add = i;
        if (n == 0) return arr;
        if (n < i) {
            add = n; // Corrected variable name from "add" to "add = n"
        }
        n -= add; // Corrected missing semicolon
        arr[i % k] += add; // Corrected variable name "num" to "arr"
    }
}

int main() {
    int n, k;
    cin >> n >> k; // Input values for n and k

    vector<int> result = solve(n, k);

    for (int i : result) {
        cout << i << " ";
    }
    
    return 0;
}


