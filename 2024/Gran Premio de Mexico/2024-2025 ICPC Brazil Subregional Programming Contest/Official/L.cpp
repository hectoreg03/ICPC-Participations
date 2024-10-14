#include<bits/stdc++.h>
using namespace std; 
int bits[32];
int main(){
int n;
vector<int> ar;
cin>>n;
for( int i=0; i<n; i++){
	int x;
	cin>>x;
	for( int j=0; x>=(1<<j); j++){
		if(x&(1<<j))
			bits[j]++;
	}
}	

ar.resize(n,0);
for( int i=0; i<n; i++){
	for( int j=0; j<=30; j++){
		if(bits[j]>0){
			ar[i]|=(1<<j);
			bits[j]--;
		}
	}
}
for( int i=0; i<n; i++){
	cout<<ar[i]<<" ";
}
cout<<endl;
}