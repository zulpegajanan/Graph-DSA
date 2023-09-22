
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


void encypt(string &str,int val){
	
	for(int i=0;i<str.size();i++){
		str[i]=str[i]+val;
	}
	cout<<str<<endl;
}

void decrypt(string &str,int val){
	for(int i=0;i<str.size();i++){
		str[i]=str[i]-val;
	}
	cout<<str<<endl;
}



int main(){
	cout<<" welcome to cryptoWorld... "<<endl;
	cout<<endl;
	
	string s;
	int num;
	cout<<": enter your string ";
	cin>>s;
	cout<<": enter your number ";
	cin>>num;
	
	
	encypt(s,num);
	decrypt(s,num);
	
}

