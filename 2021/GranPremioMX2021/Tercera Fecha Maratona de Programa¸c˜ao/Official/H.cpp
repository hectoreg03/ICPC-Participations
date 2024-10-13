#include<bits/stdc++.h>
using namespace std;
const int mxn=1e5+10;
typedef long long int lli;
int main(){
	vector<vector<lli> > ml;
	vector<lli> ord;
	vector<int> it;
	lli n,k,a,b;
	cin>>n>>k;
	ml.resize(k);
	it.resize(k);
	for( int i=0; i<n; i++){
		cin>>a>>b;
		ml[b-1].push_back(a);
		ord.push_back(b-1);
	}
	for( int i=0; i<k; i++){
		it[i]=0;
		sort(ml[i].begin(),ml[i].end());
	}
	for( int i=0; i<n; i++){
		b=ord[i];
		ord[i]=ml[b][it[b]];
		it[b]++;
	}
	bool ans=true;
	for( int i=1; i<n; i++){
		if(ord[i-1]>ord[i])ans=false;
	}
	if(ans==false)cout<<"N"<<endl;
	else cout<<"Y"<<endl;
	
}