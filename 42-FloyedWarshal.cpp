
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

	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int n=matrix.size();
	    int m=matrix[0].size();
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(matrix[i][j]==-1){
	                matrix[i][j]=1e9;
	            }
	        }
	    }
	    
	    for(int via=0;via<m;via++){
	         for(int i=0;i<n;i++){
		        for(int j=0;j<m;j++){
		            matrix[i][j]=min(matrix[i][j],matrix[i][via]+matrix[via][j]);
		        }
		    }
	    }
	 			   
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(matrix[i][j]==1e9){
	                matrix[i][j]=-1;
	            }
	        }
	    }
	    
	}

	int main() {
	    vector<vector<int>> matrix = {
	        {0, 2, -1, -1},
	        {1, 0, 3, -1},
			{-1, -1, 0, -1},
	        {3, 5, 4, 0}
	    };
	
	    shortest_distance(matrix);
	
	    cout << "Shortest distances after applying the algorithm:" << endl;
	    for (const auto& row : matrix) {
	        for (int value : row) {
	            cout << value << " ";
	        }
	        cout << endl;
	    }
	
	    return 0;
	}
