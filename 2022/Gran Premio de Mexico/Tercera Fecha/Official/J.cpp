#include<bits/stdc++.h>
using namespace std;
int val(int x){
	if( x> 10)return 10;
	else{
		return x;
	}
}
bool vic( int a, int b){
	if(a>23 && b<=23)return true;
	if(b==23)return true;
	return false;
}
int pos[14];
int main(){
	for( int i=0; i<=13; i++){
		pos[i]=4;
	}
	int n;
	cin>>n;
	int a=0,b=0;
	cin>>a;
	pos[a]--;
	a=val(a);
	int x;
	cin>>x;
	a+=val(x);
	pos[x]--;
	cin>>b;
	pos[b]--;
	b=val(b);
	cin>>x;
	b+=val(x);
	pos[x]--;
	for( int i=0; i<n; i++){
		cin>>x;
		pos[x]--;
		a+=val(x);
		b+=val(x);
	}
	int ans=-1;
	for( int i=13;i>0; i--){
		if(vic(a+val(i),b+val(i)) && pos[i]>0){
			ans=i;
		}
	}
	cout<<ans<<endl;
}