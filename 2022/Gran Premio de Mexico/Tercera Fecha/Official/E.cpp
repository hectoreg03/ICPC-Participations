#include<bits/stdc++.h>
using namespace std;
const int mxn=1e6+10;
int ar[mxn];
int main(){
	int n,x;
	int ans=0;
	cin>>n; 
	for( int i=0; i<n; i++){
		cin>>x;
		if(ar[x]>0){
			ar[x]--;
			ar[x-1]++;
		}
		else{
			ar[x-1]++;
			ans++;
		}
	}
	cout<<ans;
}