
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

int main(){
	// part 1
	vector<int> a{0,0,1,1};
	vector<int> b{0,1,0,1};
	cout<<"1. TABLE\n";
	cout<<"a"<<"\t"<<"b"<<"\t"<<"a&b"<<"\t"<<"a|b"<<"\t"<<"a^b"<<endl;
	
	for(int i=0;i<4;i++){
		cout<<a[i]<<"\t"<<b[i]<<"\t"<<(a[i] & b[i])<<"\t"<<(a[i] | b[i])<<"\t"<<(a[i] ^ b[i])<<endl;
	}
	
	
	// part 2
	cout<<endl;
	cout<<"Number(6) to Bitset(base-4) Conversion"<<endl;
	int num1=6;
	bitset<4> itob(6);
	cout<<itob;
	
	//part 3
	cout<<endl;
	cout<<"VICE_VERSA of {Number(6) to Bitset(base-4) Conversion}"<<endl;
	int rnum1=(int) itob.to_ulong();
	cout<<rnum1;
	
	//part 4 
	cout<<endl;
	cout<<"Convert Binary string '101010' into bitset(bitset- 6)"<<endl;
	string s="101010";
	bitset<6> stob(s);
	cout<<stob;
	cout<<"\n\\\_--->(NOTE)--->";
	cout<<"stob[0]:"<<stob[0]<<" but "<<"s[0]:"<<s[0];
	
	//Part 5
	cout<<endl;
	cout<<"convert bitset into binary string format"<<endl;
	string str =(string) stob.to_string();
	cout<<str;
	
	
	//part 6
	cout<<endl<<"count set bit 101010==>";
	int n = stob.count();
	cout<<n<<endl;
	
	//part 7
	//any()
	bitset<4> x(8);
	cout<<"\nany bit is set : "<<x.any();
	bitset<4> y(0);
	cout<<"\nany bit is set : "<<x.all();
	
	
	//set all bit as set
	auto k =stob.set(1)
	
	
	
	return 0;
}

