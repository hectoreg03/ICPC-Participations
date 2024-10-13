#include<iostream>
using namespace std;
typedef long long int lli;
int per( lli n){
	if(n<10)return 0;
	int ans=0;
	lli l;
	while(n>=10){
		ans++;
		l=1;
		while(n>0){
			l*=n%10;
			n/=10;
		}
		swap(l,n);
	}
	return ans;
}
int main(){
	int t;
	cin>>t;
	lli x;
	while(t--){
		cin>>x;
		cout<<per(x)<<endl;
	}
}