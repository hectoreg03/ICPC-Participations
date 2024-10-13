#include<bits/stdc++.h>
using namespace std;
int par( int x, int sl){
	if(x<=30){
		int b=30-x, nsl=(sl+30)%7;
		if(nsl>=0&&nsl<=4) return b;
		else{
			if(nsl==6) return b+1;
			else return b+2;
		}
	} else{
		if(sl==0){
			x%=91;
			if(x==0||x==30||x==60)return 0;
			else{
				if(x>60)return par(x-60,4);
				else{
					if(x>30)return par(x-30,2);
					else return par(x,0);
				}
			}
		}
		if(sl==1){
			return par(x-30,sl+2);
		}
		if(sl==2){
			return par(x-30,sl+2);
		}
		
		if(sl==3){
			if(x==32) return 0;
			else return par(x-32,0);
			
		}
		if(sl==4){
			if(x==31)return 0;
			else return par(x-31,0);
		}
	}
}
int solve(int x, int sm){
	int org=sm-(x%7);
	if(org<0)org+=7;
	return par(x,org);
}
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string a; int n;
	cin>>a>>n;
	int sm;
	if(a=="Mon")sm=0;
	if(a=="Tue")sm=1;
	if(a=="Wed")sm=2;
	if(a=="Thu")sm=3;
	if(a=="Fri")sm=4;
	if(a=="Sat")sm=5;
	if(a=="Sun")sm=6;
	int ans=35,x;
	for( int i=0; i<n; i++){
		cin>>x;
		ans=min(ans,solve(x,sm));
	}
	cout<<ans;
}