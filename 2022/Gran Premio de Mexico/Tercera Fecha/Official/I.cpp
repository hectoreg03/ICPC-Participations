#include <bits/stdc++.h>
using namespace std;
int main(){
    int x;
    bool ans=false;
    for( int i=0; i<8; i++){
    	cin>>x;
    	if(x==9)ans=true;
	}
	if(!ans)cout<<"S"<<endl;
	else cout<<"F"<<endl;
}
