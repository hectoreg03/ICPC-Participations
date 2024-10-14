#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli ar[22];
lli gdc( lli a, lli b){
	if (b==0) return a;
	else{
		return gdc(b,a%b);
	}
}
lli rev( lli a, lli x){
	lli us= 0, as=1;
	int ca=0;
	for( lli i=0; i<=20; i++){
		if( a & (1<<i)){
			ca++;
			us=gdc(us,ar[i]);
		}
	}
	as=us;
	for( lli i=0; i<=20; i++){
		if( a & (1<<i)){
			as*=ar[i]/us;
		}
	}
	if(ca%2==0) return -(x/as);
	else return (x/as);
}
int main(){
	lli n,x,aux;
	cin>>n>>x;
	aux=1<<n;
	lli ans=0;
	for( int i=0; i<n; i++){
		cin>>ar[i];
	}
	for(lli i =1; i<aux; i++){
		ans+=rev(i,x);
	}
	cout<<ans<<endl;
}
