#include<bits/stdc++.h>
 using namespace std;
const int mxnp = 1e6+10;
 bool pr[mxnp];
 int ca[mxnp];
 vector<int> prm;
 const long long int mod = 1e9+7;
 long long int exp( long long int a, long long int b){
 	//cout<<a<<" ";
 	if(b==0)return 1;
 	if(b==1)return a;
 	if(b%2==1)return (a*(exp((a*a)%mod,b/2)))%mod;
 	else return exp((a*a)%mod, b/2);
 }
 void prcal(){
 	for( int i=2; i*i<=mxnp;i++){
 		if(pr[i]==false){
 			//cout<<i<<endl;
 			prm.push_back(i);
 			for( int j=i; j<mxnp; j+=i){
 				pr[j]=true;
			 }
		 }
	 }
 }
 void gene( int x){
 	vector<int>mp;
 	for( int i=0; x>prm[i]&&i<prm.size(); i++){
 		if(x%prm[i]==0){
 			mp.push_back(prm[i]);
 			while(x%prm[i]==0){
 				x/=prm[i];
			 }
		 }
	 }
	 if(x>1){
	 	mp.push_back(x);
	 }
	 for( int i=1; i<(1<<mp.size()); i++){
	 	int ac=1;
	 	for( int j=0; j<mp.size(); j++){
	 		if(i&(1<<j)){
	 			ac*=mp[j];
			 }
		 }
		if(ac<mxnp){
			ca[ac]++;
		}
	 }
	 
 }
 long long int solve( int x){
 	vector<int>mp;
 	for( int i=0; x>prm[i]&&i<prm.size(); i++){
 		if(x%prm[i]==0){
 			mp.push_back(prm[i]);
 			while(x%prm[i]==0){
 				x/=prm[i];
			 }
		 }
	 }
	 if(x>1){
	 	mp.push_back(x);
	 }
	 long long int ans=0;
	 for( int i=1; i<(1<<mp.size()); i++){
	 	int ac=1,cb=0;
	 	for( int j=0; j<mp.size(); j++){
	 		if(i&(1<<j)){
	 			cb++;
	 			ac*=mp[j];
			 }
		 }
		if(ac<mxnp){
			if(cb%2==1)ans+=ca[ac];
			else ans-=ca[ac];
		}
	 }
	 return ans;
	 
 }
  int main(){
  	prcal();
  	 int n;
  	 cin>>n;
  	 for( int i=0; i<n;i++){
  	 	 int x;
  	 	 cin>>x;
  	 	 gene(x);
	   }
	   int q;
	   cin>>q;
	   for(int i=0; i<q; i++){
	   	int x;
	   	cin>>x;
	   	cout<<exp(2,n-solve(x))<<endl;
	   }
  }