#include<bits/stdc++.h>
using namespace std;
 int main(){
	int n;
	cin>>n;
	 int a,b,c;
	for( int i=0; i<n; i++){
		for( int j=0; j<n; j++){
			if(i==0){
				if(j==0){
					cin>>a;
				}
				if(j==1){
					cin>>b;
				}
				if(j>=2){
					int x;
					cin>>x;
				}
			}else
			if(i==1){
				if(j==0){
					cin>>c;
				}else{
					int x;
					cin>>x;
				}
			} else{
				int x;
				cin>>x;
			}
		}
	}
	if(a<b&&a<c)cout<<0<<endl;
	if(a<b&&a>c)cout<<3<<endl;
	if(a>b&&a<c)cout<<1<<endl;
	if(a>b&&a>c)cout<<2<<endl;	
}