#include<bits/stdc++.h>
using namespace std;
const long long int mxn =110;
const long long int mod =1e9+7;
vector<vector<long long int>> mult(vector<vector<long long int>> a,vector<vector<long long int>> b){
	vector<vector<long long int>> ans;
	ans.resize(a.size());
	for( long long int i=0; i<a.size(); i++){
		ans[i].resize(a.size());
		for( long long int j=0; j<a.size(); j++){
			ans[i][j]=0;
			for( long long int k=0; k<a.size(); k++){
				ans[i][j]=(ans[i][j]+(a[i][k]*b[k][j])%mod)%mod;
			}
		}
	}
	return ans;	
}
vector<vector<long long int>> nms(vector<vector<long long int>> a, long long int b ){
	if(b==1)return a;
	if(b%2==0) return nms(mult(a,a),b/2);
	else return mult(nms(mult(a,a),b/2),a);
}
int main(){
  	long long int n,m,k;
  	cin>>n>>m>>k;
	vector<vector<long long int >>mat(n,vector<long long int> (n,0));	
  	for( long long int i=0; i<m; i++){
  		long long int a,b;
  		cin>>a>>b;
  		a--;
  		b--;
  		mat[a][b]=1;
  		mat[b][a]=1;
	}
	vector<long long int> ans(n,0);
	vector<long long int> aux(n,0);
	ans[0]=1;
	mat= nms(mat,k);
	for( long long int j=0; j<n; j++){
		aux[j]=0;
		for(long long int l=0; l<n; l++){
			aux[j]=(aux[j]+((mat[l][j]*ans[l])%mod))%mod;
		}
	}
	for( long long int j=0; j<n; j++){
		ans[j]=aux[j];
	}
	long long int fans=0;
	
	for( long long int j=0; j<n; j++){
		fans=(ans[j]+fans)%mod;
	}
	cout<<fans<<endl;
}