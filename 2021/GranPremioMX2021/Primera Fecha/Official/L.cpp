#include<bits/stdc++.h>
using namespace std;
string ans;
typedef long long int lli;
void sol( lli m){
	if(m==1){
	ans+="2";	
	}else{
		if(m%2==1){
			ans+="(2*";
			sol(m-1);
			ans+=")";
			return;
		}else{
			ans+="(";
			sol(m/2);
			ans+=")^2";
			return;
		}
	}
}
int main(){
	lli n,m;
	cin>>n;
	for( int i=0; i<n; i++){
		cin>>m;
		sol(m);
		cout<<ans<<endl;
		ans="";
	}
}