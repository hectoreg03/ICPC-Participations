#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
	lli n,t,ft;
	int x,dr;
	bool db=false;
	cin>>n;
	vector<pair<lli,int>> rd;
	for( int i=0; i<n; i++){
		cin>>t>>x;
		rd.push_back({t,x});
	}
	ft=10+rd[0].first;dr=rd[0].second;
	for( int i=0; i<n; i++){
		if(ft<rd[i].first){
			if(db){
				db=false;
				ft+=10;
				dr=(1-dr);
				if(dr==rd[i].second){
					ft=rd[i].first+10;
				}else{
					db=true;
				}
			}else{
				ft=rd[i].first+10;
				dr=rd[i].second;
			}
		}else{
			if(dr==rd[i].second){
				ft=rd[i].first+10;
			}else{
				db=true;
			}	
		}
	}
	if(db==true)ft+=10;
	cout<<ft<<endl;
}