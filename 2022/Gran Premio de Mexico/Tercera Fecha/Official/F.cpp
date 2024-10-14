#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	map<string,int> x;
	string nv;
	
		string best;
		int mxn=0;
	for( int i=0; i<n; i++){
		cin>>nv;
		int as;
		for( int j=0; j<nv.size(); j++){
			if(nv[j]=='*'){
				as=j;
			}
		}
		for(char nl='a'; nl<='z'; nl++){
			nv[as]=nl;
			if(x.find(nv)==x.end()){
				x[nv]=0;
			}
			x[nv]=x[nv]+1;
			if(x[nv]>mxn||(x[nv]==mxn&& best > nv)){
				best=nv;
				mxn=x[nv];
			}
		}
		
	}
	cout<<best<<" "<<mxn<<endl;
}