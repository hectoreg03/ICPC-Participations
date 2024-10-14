#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,x,y;
	cin>>n>>x>>y;
		int ans=0;
	if (((~x+1)&x)==((~y+1)&y)){
		n--;
		while((1<<n)>((~x+1)&x)){
			n--;
			ans++;
		}
	}else{
		ans=n;
	}
	cout<<ans;
}