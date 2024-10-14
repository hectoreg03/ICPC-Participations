#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	string a;
	cin>>a;
	int ans=0;
	for( int i=1; i<a.size(); i++){
		if(a[i]=='a'){
			
		if(a[i-1]=='a'|| a[i-1]=='c'){
			a[i]='c';
		}
		}
	}
	for( int i=a.size()-2; i>=0; i--){
		if(a[i]=='a'){
			
		if(a[i+1]=='a'|| a[i+1]=='c'){
			a[i]='c';
		}
		}
	}
	for( int i=0; i<n; i++){
		if(a[i]=='c')ans++;
	}
	cout<<ans;
}