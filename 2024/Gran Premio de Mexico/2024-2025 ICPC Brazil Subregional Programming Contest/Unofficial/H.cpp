#include<bits/stdc++.h>
using namespace std;
const int mxn = 1e6;

	  vector<long long int> vnn;
bool pos(string m){
	vector<long long int> vm;
	bool un;
 	for(int i=0; i<m.size(); i++){
 		long long int ac=0;
	  	if(m[i]=='1'){
		  	ac=1;
		}
 	 	for(int j=0; j< vm.size(); j++){
 	 		vm[j]*=2;
 	 		vm[j]+=ac;
 	 		ac=vm[j]/mxn;
 	 		vm[j]%=mxn;
		}
		if(ac>0){
		  	vm.push_back(ac);
		}
	}
	/*
	for( int i=vm.size()-1; i>=0; i--){
		cout<<vm[i];
	}
	cout<<endl;
	*/
	for(int j=0; j<vnn.size();j++){	
		long long int ac=0;
		for( int i=vm.size()-1; i>=0; i--){
			ac=(vm[i]+(ac*mxn))%vnn[j];
		}
		if(ac==0)return true;
	}
	return false;
}
 int main(){
 	 vector<int>vm;
 	 vector<int>vn;
 	 string n,m;
 	 cin>>m>>n;
 	 for(int i=0; i<m.size();i++){
 	 	if(m[i]=='*'){
 	 		vm.push_back(i);
		  }
	  }
	  int nv=0;
 	 for(int i=0; i<n.size();i++){
 	 	nv*=2;
 	 	if(n[i]=='1'){
 	 		nv++;
		  }
 	 	if(n[i]=='*'){
 	 		vn.push_back(n.size()-1-i);
		  }
	  }
	  
		for( int j=0; j<(1<<vn.size()); j++){
			int acl =0;
			for(int i=0; i<vn.size();i++){
				if(j&(1<<i)){
					acl+=(1<<vn[i]);
				}
			}
			vnn.push_back(nv+acl);
		}
		/*
		for(int i=0; i<vnn.size();i++){
			cout<<vnn[i]<<" ";
		}
		cout<<endl;*/
	for(int j=0; j<(1<<vm.size()); j++){
		for(int i=0; i<vm.size();i++){
			if(j&(1<<i)){
				m[vm[i]]='1';
			} else{
				m[vm[i]]='0';
			}
		}
		if(pos(m)){
			cout<<m<<endl;
			break;
		}
	}
 }