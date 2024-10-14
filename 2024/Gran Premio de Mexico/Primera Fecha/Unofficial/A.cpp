#include<bits/stdc++.h>
using namespace std;
 int main(){
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	vector<	vector<int>> tab;
	tab.resize(n);
	for( int i=0; i<n; i++){
		tab[i].resize(n);
		cin>>tab[0][i];
		if(i>0){
			tab[1][i-1]=abs(tab[0][i]-tab[0][i-1]);
			//cout<<tab[1][i-1]<<" ";
		}
	}
	//cout<<endl;
	for( int i=2; i<n; i++){
		for( int j=0; j+i<n; j++){
			tab[i][j]=min(min(tab[i-1][j],tab[i-1][j+1]),abs(tab[0][j]-tab[0][j+i]));
			//cout<<tab[i][j]<<" ";	
		}
		//cout<<endl;
	}
	int q;
	cin>>q;
	for( int i=0; i<q; i++){
		 int l,r;
		 cin>>l>>r;
		 int df=r-l;
		 cout<<tab[df][l-1]<<endl;
	}
}
	