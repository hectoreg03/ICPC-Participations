#include<bits/stdc++.h>
using namespace std;
 int main(){
 	int a,b,c;
 	int a2,b2,c2;
 	cin>>a>>b>>c;
 	cin>>a2>>b2>>c2;
 	int mxn=(a/a2)*(b/b2)*(c/c2);
 	if(mxn<((a/a2)*(c/b2)*(b/c2)))mxn=(a/a2)*(c/b2)*(b/c2);
 	if(mxn<((b/a2)*(a/b2)*(c/c2)))mxn=(b/a2)*(a/b2)*(c/c2);
 	if(mxn<((b/a2)*(c/b2)*(a/c2)))mxn=(b/a2)*(c/b2)*(a/c2);
 	if(mxn<((c/a2)*(a/b2)*(b/c2)))mxn=(c/a2)*(a/b2)*(b/c2);
 	if(mxn<((c/a2)*(b/b2)*(a/c2)))mxn=(c/a2)*(b/b2)*(a/c2);
 	cout<<mxn<<endl;
 }