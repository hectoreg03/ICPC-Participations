#include<bits/stdc++.h>
 using namespace std; 
 int main(){
 	int pv=1,ac=1;
	 	int n;
	 	cin>>n;
	 	n--;
	 	while(n){
	 		swap(pv,ac);
			 ac+=pv;
			 n--;
		 }
		cout<<ac<<endl;
 }