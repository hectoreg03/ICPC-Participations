#include<bits/stdc++.h>
using namespace std;
int n,m;
int pos[200][200];
int rf[200][200];
const int mxn=1e4+10;
pair<int,int> posc[mxn];
int dfs(int v){
	priority_queue <int> vl;
	vl.push(v);
	 int va;
	 int mov[4][2]{{1,0},{-1,0},{0,1},{0,-1}};
	  int ans=1;
	while(!vl.empty()){
		va= vl.top();vl.pop();
	  	int x=posc[va].first, y=posc[va].second;
	  	for( int i=0; i<4; i++){
	  		if(x+mov[i][0]<n&& x+mov[i][0]>=0&&y+mov[i][1]<m&& y+mov[i][1]>=0 && rf[x+mov[i][0]][y+mov[i][1]]!= v && pos[x+mov[i][0]][y+mov[i][1]] > va){
	  			vl.push(pos[x+mov[i][0]][y+mov[i][1]]);
	  			rf[x+mov[i][0]][y+mov[i][1]]=v;
	  			ans++;
			  }
		  }
	}
	return ans;
}
 int main(){
 	 cin>>n>>m;
 	 for( int i=0; i<n; i++){
 	 	for( int j=0; j<m; j++){
 	 		cin>>pos[i][j];
 	 		posc[pos[i][j]]={i,j};
 	 		rf[i][j]=pos[i][j];
		  }
	  }
	  int fans=1,ps;
	  for( int i=1; i<=n*m; i++){
	  	int x=posc[i].first, y=posc[i].second;
	  	if(rf[x][y]==i){
	  		ps=dfs(i);
	  		//cout<<ps<<" ";
	  		if(fans<ps)fans=ps;
		  }
	  }
	  cout<<fans;
 }