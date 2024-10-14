#include<bits/stdc++.h>
using namespace std;
 int main(){
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 	int n;
 	cin>>n;
 	int x;
 	vector<int> tr;
 	for( int i=0; i<n; ++i){
 		 cin>>x;
	 	tr.push_back(x);
	 }
	 sort(tr.begin(), tr.end());
	 if(tr.size()==1)cout<<"Alicius"<<endl;
	 else{
	 	int ord=0, pv=0;
	 	while(ord<tr.size()&&tr[ord]-pv<=1){
	 		pv=tr[ord];
	 		++ord;
		 }
	 	if(pv!=tr.size()){
	 		pv++;
		 } 
 		if(pv%2==1)cout<<"Alicius"<<endl;
 		else cout<<"Bobius"<<endl;
	}
 }