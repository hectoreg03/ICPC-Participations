#include<bits/stdc++.h>
using namespace std;
bool ar[30];
vector<string > a;
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;cin>>n;
	string x;
	for( int i=0; i<n; ++i){
		cin>>x;
		ar[x[0]-'A']=true;
		a.push_back(x);	
	}
	bool ans=false,wrd;
	for( int i=0; i<n&&ans==false; ++i){
		wrd=true;
		for( int j=0; j<a[i].size()&&wrd; ++j){
			wrd&=ar[a[i][j]-'A'];
		}	
		if(wrd)ans=true;
	}
	if(ans)cout<<"Y";
	else cout<<"N";
}