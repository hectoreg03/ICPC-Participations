#include<bits/stdc++.h>
using namespace std;
 int main(){
 	 int n,k,e;
 	 cin>>n>>k>>e;
 	 int ans=4;
 	 bool ar[n+1];
 	 for( int i=0; i<=n; i++){
 	 	ar[i]=true;
	  }
	  ar[k]=false;
	  int dffs[10][2]{{0,0},{1,0},{0,1},{1,1},{2,0},{0,2},{2,1},{1,2},{3,0},{0,3}};
	  int l,x,y;
	  l=n-(e+k);
 	 for( int i=0; i<10; i++){
 	 	for( int j=0; j<4; j++){
		  	if(e-j-dffs[i][0]>=0&&ar[e-j-dffs[i][0]]==true && ar[j] == true && (j!= e-j-dffs[i][0] || e-j-dffs[i][0] ==0)){
		  		if(e-j-dffs[i][0]>0)ar[e-j-dffs[i][0]]= false;
		  		if(j>0)ar[j]=false;
	 	 		for( int k =0; k<7; k++){
	 	 			if(l-k-dffs[i][1]>=0 &&ar[l-k-dffs[i][1]]==true && ar[k] == true && (k!= l-k-dffs[i][1] || l-k-dffs[i][1] ==0)){
	 	 				ans = min(ans, dffs[i][0]+dffs[i][1]);
					  }
					  //cout<<dffs[i][0]<<" "<<e<<" "<<j<<" "<<dffs[i][1]<<" "<<l<<" "<<k<<endl;
				}
				ar[e-j-dffs[i][0]]= true;
				ar[j]= true;
			}
		}
	  }
	cout<<ans;
 }