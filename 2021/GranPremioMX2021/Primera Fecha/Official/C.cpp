#include<bits/stdc++.h>
using namespace std;
const int mxn=1e6+10;
typedef long long int lli;
lli ar[mxn];
bool pv[mxn];
int main(){
	for( int i=0; i<mxn; i++)pv[i]=false;
	ar[0]=0;
	ar[1]=0;
	for( lli i=2; i<mxn; i++){
		ar[i]=ar[i-1];
		if(pv[i]==false){
			ar[i]++;
			for( lli j= i*i; j<=mxn; j+=i){
				pv[j]=true;
			}
		}
	}
	lli n,x,y;
	cin>>n;
	for( int i=0; i<n; i++){
		cin>>x>>y;
		cout<<ar[y]-ar[x-1]<<endl;
	}
}