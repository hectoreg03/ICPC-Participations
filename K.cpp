#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int>ans;
	for( int i=0;i<n; i++){
		ans.clear();
	string a;
	bool se=true;
	cin>>a;
	int x=0,t=a.size();
	t=a.size();
	if(int(a[t-1]-'0')%2==0){
		ans.push_back(2);
	}else se=false;
	for( int i=0; i<t;i++){
		x+=(a[i]-'0');
		x%=3;
	}
	if(x==0){
		ans.push_back(3);
	} else se=false;
	if(t>0){
		x=a[t-1]-'0';
		if(t>1){
			x+=(int(a[t-2]-'0'))*10;;
		}
	}
	if(x%4==0){
		ans.push_back(4);
	}
	if(a[t-1]=='5'||a[t-1]=='0'){
		ans.push_back(5);
	}
	if(se)ans.push_back(6);
	if(ans.empty())cout<<-1<<endl;
	else{
		for( int i=0; i<ans.size(); i++){
			cout<<ans[i];
			if(i+1<ans.size())cout<<" ";
		}
		cout<<endl;
	}
	}
}
