#include<bits/stdc++.h>
using namespace std;
string rn;
int cst[510][510][260];
int solve(int prin, int fin, int lft){
    //cout<<"Solve"<<prin<<" "<<prin<<" "<<fin<<endl;
	if(lft==0)return 0;
	if(prin<0)return 5000;
	if(fin>=rn.size())return 5000;
	if(lft>1+prin||lft>rn.size()-lft)return 5000;
	if(cst[prin][fin][lft]!=-1){
	    return cst[prin][fin][lft];
	}
	int ans=5000;
	ans= min(ans, ((rn[prin]==rn[fin])?0:1)+solve(prin-1,fin+1,lft-1));
	if(prin-1>=0){
		if(cst[prin-1][fin][lft]==-1)
			ans= min(ans, solve(prin-1,fin,lft));
		else
			ans = min(ans,cst[prin-1][fin][lft]);
	}
	if(fin+1<rn.size()){
		if(cst[prin][fin+1][lft]==-1)
			ans= min(ans, solve(prin,fin+1,lft));
		else
			ans = min(ans,cst[prin][fin+1][lft]);
	}
	if(prin-1>=0&&fin+1<rn.size()){
		if(cst[prin-1][fin+1][lft]==-1)
			ans= min(ans, solve(prin-1,fin+1,lft));
		else
			ans = min(ans,cst[prin-1][fin+1][lft]);
	}
	//ans= min(ans, solve(prin-1,fin,lft));
	//ans= min(ans, solve(prin,fin+1,lft));
	//ans= min(ans, solve(prin-1,fin+1,lft));
	cst[prin][fin][lft]=ans;
	return cst[prin][fin][lft];
}
 int main(){
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 	int n,k;
 	cin>>n>>k;
 	cin>>rn;
 	int ans=5000;
 	memset(cst,-1,sizeof(cst));
 	for( int i=0; i<n; ++i){
 		int tAns=0;
 		if(k%2==0){
 			tAns=min(solve(i-1,i,k/2),solve(i,i+1,k/2));
		 }else{
		 	tAns = solve(i-1,i+1,k/2);
		 }
		 ans=min(ans,tAns);
	 }
	 cout<<ans<<endl;
 	
 }