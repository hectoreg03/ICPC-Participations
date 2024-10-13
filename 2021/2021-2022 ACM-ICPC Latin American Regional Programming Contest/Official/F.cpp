#include<bits/stdc++.h>
using namespace std;
const int mxn=3e5+10;
bool pv[mxn];
vector<vector<int>> grp;
void dfs( int a, int n){
	if(pv[a]==true)return;
	pv[a]=true;
	for( int i=0; i<grp[a].size(); i++){
		if(grp[a][i]!=n)dfs(grp[a][i],n);
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	grp.resize(n+1);
	int x,y;
	for( int i=0; i<m;i++){
		cin>>x>>y;
		grp[x].push_back(y);
		grp[y].push_back(x);
	}
	dfs(n-1,n);
	for( int i=1; i<=n; i++){
		if(pv[i])cout<<"B";
		else cout<<"A";
	}
}