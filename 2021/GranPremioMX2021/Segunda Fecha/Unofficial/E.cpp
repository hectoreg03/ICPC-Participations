#include<bits/stdc++.h>
using namespace std;
const int mxn=2e6+10;
typedef long long int lli;
lli ar[mxn];
lli sm[mxn];
bool tr( int md, lli lm, int n){
	lli ps;
	for( int i=1; i<=n; i++){
		ps=sm[i+md-1]-sm[i-1];
		if(ps>lm){
			return false;
		}
	}
	return true;
}
lli tmr( int md, lli lm, int n){
	lli ps;
	for( int i=1 ; i<=n; i++){
		ps=sm[i+md-1]-sm[i-1];
		if(ps>lm)return i;
	}
}
void bns( int mn, int mx, int n, lli mxn){
	int md=(mx+mn)/2;
	if(md==mn){
		cout<<md<<" ";
		cout<<tmr(mx,mxn,n)<<endl;
		return;
	}
	if(tr(md, mxn, n)){
		bns(md,mx,n,mxn);
	}else{
		bns(mn,md,n,mxn);
	}
}
int main(){
	int n;
	cin>>n;
	string a;
	cin>>a;
	lli mxn=0;
	for(int i=0; i<a.size()-1; i++){
		mxn*=10;
		mxn+=a[i]-'0';
	}
	if(a[a.size()-1]=='M')mxn*=1ll;
	if(a[a.size()-1]=='G')mxn*=1024ll;
	if(a[a.size()-1]=='T')mxn*=1048576ll;
	for( int i=1; i<=n; i++){
		cin>>ar[i];
		ar[i+n]=ar[i];
	}
	sm[0]=0ll;
	for( int i=1; i<=2ll*n; i++){
		sm[i]=sm[i-1]+ar[i];
	}
	if(mxn>=sm[n])cout<<n<<" "<<-1<<endl;
	else{
		bns(1,n,n, mxn);
	}
}