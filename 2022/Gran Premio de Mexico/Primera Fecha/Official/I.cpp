#include<bits/stdc++.h>
 using namespace std;
  int main(){
  	long long int n,aux;
  	cin>>n;
  	aux=n;
  	vector<int> nm;
  	while(aux>0){
  		if(aux%10>0)
  			nm.push_back(aux%10);
  		aux/=10;
	  }
	int ans=0;
	for( int i=0; i<nm.size(); i++){
		if(n%nm[i]==0)ans++;
	}
	cout<<ans<<endl;
  }