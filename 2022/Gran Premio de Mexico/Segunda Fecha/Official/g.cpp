#include<bits/stdc++.h>
using namespace std;
const int mxn=1e6+10;
typedef long long int lli;
lli dist[mxn];
lli esp[mxn];
lli arr[mxn][2];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	for( int i=0; i+1<n; i++){
		cin>>dist[i];
	}
	for( int i=0; i<n; i++){
		cin>>esp[i];
	}
	for( int i=0; i<n; i++){
		if( i==0){
			arr[i][0]=0;
			arr[n-1-i][1]=0;
		} else{
			arr[i][0]=arr[i-1][0]+esp[i-1]+dist[i-1];
			arr[n-1-i][1]=arr[n-1-(i-1)][1]+ esp[n-1-(i-1)]+ dist[n-2-(i-1)];
		}
	}
	lli ans=0;
	for( int i=0; i<n; i++){
		ans=max(ans,min(arr[i][0],arr[i][1])+ esp[i]- max(arr[i][0],arr[i][1]));
		//cout<<arr[i][0]<<" "<<arr[i][1]<<endl;
	}
	cout<<ans<<endl;
}
