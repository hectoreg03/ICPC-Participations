#include<bits/stdc++.h>
using namespace std;
const int mxn=5e4+250;
bool ps[mxn];
vector<int>nms;
 int solve(int n){
 	if(ps[n])return 0;
 	else{
 		if(nms[0]>n)return nms[0]-n;
 		int mx=nms.size()-1,mn=0;
 		while(mn+1!=mx){
 			int md=(mx+mn)/2;
 			if(nms[md]>n){
 				mx=md;
			 }else{
			 	mn=md;
			 }
		 }
		 return nms[mx]-n;
	 }
 }
int main(){
  	int k,p;
  	cin>>k>>p;
  	vector<int>bls;
  	for(int i=0; i<p; i++){
  		int x;
  		cin>>x;
  		bls.push_back(x);
	}
	ps[0]=true;
	for( int i=0; i<mxn; i++){
		if(ps[i]){
			for( int j=0; j<p; j++){
				if(i+bls[j]<mxn){
					ps[i+bls[j]]=true;
				}
			}
			nms.push_back(i);
		}
	}
	for(int i=0; i<k; i++){
		int n;
		cin>>n;
		cout<<solve(n)<<endl;
	}
}