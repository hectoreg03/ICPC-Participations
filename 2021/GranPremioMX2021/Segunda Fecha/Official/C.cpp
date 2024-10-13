#include<bits/stdc++.h>
using namespace std;
const int mxn=1e6+10;
int ar[mxn];
int mn[mxn];
void solve( string x){
	int t=x.size(),ans=-1,mnl;
	if(x[0]=='B')ar[0]=1;
	else ar[0]=-1;
	for( int i=1; i<t; i++){
		ar[i]=ar[i-1];
		if(x[i]=='B')ar[i]=ar[i-1]+1;
	else ar[i]=ar[i-1]-1;
	}
	mn[t]=ar[t-1];
	for( int i=t-1; i>=0; i--){
		mn[i]=min(ar[i],mn[i+1]);
	}
	if(mn[0]>=0)ans=0;
	else{
		mnl=ar[0];
		for( int i=1; i<t&&ans==-1; i++){
			if(mn[i]>=ar[i-1])ans=i;
		}
	}
	cout<<ans<<endl;
}
int main(){
	string a;
	int t;
	cin>>t;
	while(t--){
		cin>>a;
		solve(a);
	}
}