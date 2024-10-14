#include<bits/stdc++.h>
using namespace std;
int k;
void solve( string ac, vector<pair<char,int> > otro, int obj){
	if( ac!="" && ac.size()==obj) k--;
	if( k>0){
		for( int i=0; i<otro.size() && k>=0; i++){
			if( otro[i].second >0){
				otro[i].second--;
				solve(ac+otro[i].first,otro,obj);
				otro[i].second++;
			}
		}	
	} else{
		if( k==0){
			cout<<ac<<endl;
		}
	}
	
}
const int mxn=1e6+10;
long long int fact[mxn];
int main(){
	fact[0]=1;
	for( int i=1; i<11; i++){
		fact[i]=fact[i-1]*i;
	}
	vector<pair<char,int> > otro;
	int n;
	cin>>n>>k;
	string x;
	cin>>x;
	sort(x.begin(),x.end());
	char nm=x[0];
	int ca=0;
	for( int i=0; i<n; i++){
		if( x[i]==nm)ca++;
		else{
			otro.push_back({nm,ca});
			nm=x[i];
			ca=1;
		}
	}
	otro.push_back({nm,ca});
	int it=1;
	string org="";
	for( it=1; it<n&&k>fact[it]; it++){
			k-=fact[it];
	}
	solve("",otro, it);
}