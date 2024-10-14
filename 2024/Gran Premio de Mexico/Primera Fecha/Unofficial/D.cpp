#include<bits/stdc++.h>
using namespace std;
const int mod =1e9+7;
 int main(){
 	 int n;
 	 cin>>n;
 	 long long int ans=0;
 	 for( int i=1; 3*i<=n; i++){
 	 	long long int bmx=(n-i*3)/2;
 	 	long long int cmax=min(i-1,n-3*i);
 	 	long long int bmn=(n-3*i-cmax)/2;
 	 	long long int aux=0;
 	 	if(cmax%2==1){
 	 		aux+=((((1+bmn)*(cmax+1))%mod)+((((bmx-bmn)*(cmax+1))/2)%mod))%mod;
		  }else{
		  	int bmx2=(n-i*3-1)/2;
 	 		aux+=((((1+bmn)*(cmax))%mod)+((((bmx2-bmn)*(cmax))/2)%mod)+bmx+1)%mod;
		  }
		  ans=(ans+aux)%mod;
 	 	//cout<<i<<": "<<aux<<endl;
	  }
	  cout<<ans<<endl;
 }