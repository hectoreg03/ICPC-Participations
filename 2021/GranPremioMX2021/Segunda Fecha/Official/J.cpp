#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
priority_queue<pair<lli,lli>,std::vector<pair<lli,lli>>,greater<pair<lli,lli> > > ord;
vector<pair<lli,pair<lli,lli> > > act;
int main(){
	int n,c;
	lli t,h,d,ti,ans;
	cin>>n>>t;
	for( int i=0; i<n; i++){
		cin>>h>>d>>c;
		for( int j=0; j<c; j++){
			cin>>ti;
			act.push_back({ti,{h,d}});
		}
	}
	sort(act.begin(),act.end());
	ans=0;
	for( int i=0; i<act.size(); i++){
		ti=act[i].first;
		h=act[i].second.first;
		d=act[i].second.second;
		if(!ord.empty()){
			while(!ord.empty()&&ti>=ord.top().first){
				ans=max(ans,ord.top().second);
				ord.pop();
			}
		}
		ord.push({ti+d,ans+h});
	}
	while(!ord.empty()){
				ans=max(ans,ord.top().second);
				ord.pop();
	}
	cout<<ans<<endl;
}