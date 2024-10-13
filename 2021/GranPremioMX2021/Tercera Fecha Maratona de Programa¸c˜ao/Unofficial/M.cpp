#include<bits/stdc++.h>
using namespace std;
const int mxn=1e5+10;
bool al[mxn];
vector<vector<int> > x;
vector<int> qr;
vector<int> lm;
void dfs( int ac){
	lm.push_back(ac);
	for( int i=0; i<x[ac].size(); ++i){
		dfs(x[ac][i]);
	}
	return;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,v,r,ac=1;
	cin>>n;
	x.resize(n+2);
	for( int i=0; i<n; ++i){
		cin>>v;
		cin>>r;
		if(v==1){
			x[r-1].push_back(ac);
			++ac;
		}else{
			qr.push_back(r-1);
		}
	}
	dfs(0);
	ac=0;
	for( int i=0; i<qr.size(); ++i){
		al[qr[i]]=true;
		while(al[lm[ac]]==true){
			++ac;
		}
		cout<<lm[ac]+1<<endl;
	}
}