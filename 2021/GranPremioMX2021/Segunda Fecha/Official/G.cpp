#include<bits/stdc++.h>
using namespace std;
const int mxn=1010;
char tb[mxn][mxn];
int ans[mxn][mxn];
vector<pair<int,int>> pr[30];
int mv[8][2]{{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
bool vl( int x,int y, int n, int m, char l){
	if(l>'Z')return false;
	if(0>x||x>=n)return false;
	if(0>y||y>=m)return false;
	if(tb[x][y]!=l+1)return false;
	return true;
}
int main(){
	int n,m,mx;
	cin>>n>>m;
	for( int i=0; i<n; i++){
		for( int j=0; j<m; j++){
			cin>>tb[i][j];
			ans[i][j]=1;
			pr[tb[i][j]-'A'].push_back({i,j});
		}
	}
	int x,y;
	for( int i=0; i<30; i++){
		for( int j=0; j<pr[i].size(); j++){
			x=pr[i][j].first;
			y=pr[i][j].second;
			for( int z=0; z<8; z++){
				if(vl(x+mv[z][0],y+mv[z][1],n,m,tb[x][y])){
					ans[x+mv[z][0]][y+mv[z][1]]=max(ans[x][y]+1,ans[x+mv[z][0]][y+mv[z][1]]);
				}
			}
		}
	}
	mx=1;
	for( int i=0; i<n; i++){
		for( int j=0; j<m; j++){
			mx=max(mx,ans[i][j]);
		}
	}
	cout<<mx<<endl;
}