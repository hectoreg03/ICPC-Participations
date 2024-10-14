#include<bits/stdc++.h>
using namespace std;
int main(){
	 int n;
	 cin>>n;
	  int h,w;
	  cin>>h>>w;
	  char x;
	 for( int i=0; i<n; i++){
	 	cin>>x;
	 	if(h>0 &&( w==0 ||x=='Y')){
	 		h--;
	 		cout<<"Y ";
	 		w++;
		 } else cout<<"N ";
		 
	 	cin>>x;
	 	if(w>0 &&( h==0 ||x=='Y')){
	 		h++;
	 		cout<<"Y"<<endl;
	 		w--;
		 } else cout<<"N"<<endl;
		 
	 }
}