#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli ar[22];
lli lft[40];
 string conv( lli a){
	string ans="";
	while(a>0){
		if(a&1){
			ans+="1";
		}else{
			ans+="0";
		}
		a/=2;
	}
	for( int i=0; i+i<ans.size(); i++){
		swap(ans[i],ans[ans.size()-1-i]);
	}
	return ans;
}
lli rev( string n){
	lli x=0;
	for( int i=0; i<n.size(); i++){
		x*=2;
		if(n[i]=='1'){
			x+=1;
		}
	}
	return x;
}
vector<string> allStrings;
vector<long long int> allNumbers;
void precalc(){
	vector<string> ac;
	ac.push_back("1");
	for( lli i=0; i<16; i++){
		string aux;
		int t=ac.size();
		for( int j=0; j<t; j++){
			aux=ac[j];
			for( int k=ac[j].size()-1; k>=0; k--){
				aux+=ac[j][k];
			}
			allStrings.push_back(aux);
			aux=ac[j]+"0";
			for( int k=ac[j].size()-1; k>=0; k--){
				aux+=ac[j][k];
			}
			allStrings.push_back(aux);
			aux[ac[j].size()]='1';
			allStrings.push_back(aux);
			ac.push_back(ac[j]+"0");
			ac[j]+="1";
		}
	}
	//allStrings.push_back("0");
	allStrings.push_back("1");
	for( int i=0; i<allStrings.size(); i++){
		allNumbers.push_back(rev(allStrings[i]));
	}
	sort(allNumbers.begin(),allNumbers.end());
	/*for(int i=0; i<10; i++){
			cout<<allNumbers[i]<<" ";
	}	
	cout<<endl;*/
}
lli f( lli a){
	if(a==-1)return 0;
	int mn=0,mx=allNumbers.size();
	if(a==0)return 0;
	else{
		while(mn+1!=mx){
			int md=(mx+mn)/2;
			if(a>=allNumbers[md]){
				mn=md;
			}else{
				mx=md;
			}
		}
		return mx;
	}
}
int main(){
	precalc();
	int n;
	cin>>n;
	for( int i=0; i<n; i++){
		lli a,b;
		cin>>a>>b;
		cout<<f(b)-f(a-1)<<endl;
	}
}
