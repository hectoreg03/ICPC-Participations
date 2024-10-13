#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<long long int> ml;
	long long int a,b,c,x,pv;
	cin>>a>>b>>c;
	for( int i=0; i<c; i++){
		cin>>x;
		ml.push_back(x);
	}
	pv=0;x=0;
	for( int i=0; i<c; i++){
		x=max(x,ml[i]-pv);
		pv=ml[i];
	}
	x=max(x,b-pv);
	if(x>=a)cout<<"Y"<<endl;
	else cout<<"N"<<endl;
}