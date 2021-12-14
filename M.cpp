#include<bits/stdc++.h>
using namespace std;
const int cir=360;
bool ar[1000];
bool rnd[1000];
int pr(int x, int sm, int ac, int org){
	if(rnd[x]==true)return (ac)/2;
	rnd[x]=true;
	if(ar[x]==false){
		return ((ac)/2) + pr((x+sm)%cir,sm,0,org);
	}else{
		return pr((x+sm)%cir,sm,ac+1,org);
	}
}
int main(){
	int n,m,prc,ans;
	cin>>n;
	bool mv;
	for( int i=0; i<1000; i++)ar[i]=false;
	for( int i=0; i<n; i++){
		cin>>m;
		ar[m]=true;
	}
	ans=0;
	for( int i=1; i<cir; i++){
		prc=0;
		memset(rnd,false,sizeof(rnd));
		for( int j=0; j<cir; j++){
			if(rnd[j]==false&&ar[j]==false){
			    m=pr(j,i,0,j);
			    if(m>0)prc+=m;
			}
		}
		for( int j=0; j<cir; j++){
			if(rnd[j]==false){
			    m=pr(j,i,0,j);
			    if(m>0)prc+=m;
			}
		}
		ans=max(prc,ans);
	}
	cout<<ans;
}
