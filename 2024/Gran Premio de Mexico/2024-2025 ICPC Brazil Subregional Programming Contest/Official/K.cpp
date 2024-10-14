#include<bits/stdc++.h>
 using namespace std;
 vector<int>dul;
 vector<int>b1;
 bool bolsasUsadas[110];
 vector<int>b2;
 bool bn[5050][100];
 bool res[5050][100];
 bool solve( int ind, int sm){
  	//cout<<ind<<" "<<sm<<endl;
 	if(sm==0)return true;
  	if(sm<0)return false;
  	if(ind>=dul.size())return false;
  	if(bn[sm][ind])return res[sm][ind];
  	bn[sm][ind]=true;
  	b1.push_back(ind);
	bool tmp=solve(ind+1,sm-dul[ind]);
	if(tmp==true){
		res[sm][ind]=true;
		return true;
	}
	else{
		b1.pop_back();
	}
	tmp= solve(ind+1,sm);
	res[sm][ind]=tmp;
	
	return tmp;
 }
 int main(){
  	int n,sm=0;
  	cin>>n;
  	for( int i=0; i<n; i++){
  		int x;
  		cin>>x;
  		dul.push_back(x);
  		sm+=x;
 	}
	bool pos =solve(0,sm/2);
	if( pos == false||sm%2==1){
		cout<<-1<<endl;
	}else{
		for( int i=0; i<b1.size(); i++){
			bolsasUsadas[b1[i]]=true;
		}
		for( int i=0; i<n; i++){
			if(bolsasUsadas[i]==false){
				b2.push_back(i);
			}
		}
		sort(b1.rbegin(),b1.rend());
		sort(b2.rbegin(),b2.rend());
		int sma=0,smb=0, it2=0;
		for( int i=0; i<b1.size(); i++){
			cout<<dul[b1[i]]<<" ";
			sma+=dul[b1[i]];
			while(sma>smb&&it2<b2.size()){
				cout<<dul[b2[it2]]<<" ";
				smb+=dul[b2[it2]];
				it2++;
			}
		}
		while(sma>smb&&it2<b2.size()){
			cout<<dul[b2[it2]]<<" ";
			smb+=dul[b2[it2]];
			it2++;
		}
		cout<<endl;
	}
 }
