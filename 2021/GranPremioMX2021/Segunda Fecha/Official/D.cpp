#include<iostream>
using namespace std;
typedef long long int lli;
int main(){
	lli c,r,s,ans,l; int t;
	cin>>t;
	while(t--){
		cin>>c>>r>>s;
		ans=c/s;
		l=c%s;
		if(l!=0){
			if(r%s==0)ans++;
			else if((l+(r%s))>s)ans++;
		}
		cout<<ans<<" ";
		c=c-(r*(s-1));
		c=max(c,0ll);
		ans=(c+(s-1))/s;
		cout<<ans<<endl;
	}
}