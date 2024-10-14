#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
map<lli, vector<lli> > alp;
map<lli, vector<lli> > err; 
const int mxn=1e7+10;
bool pvs[mxn];
bool ej( lli a, lli b){
	return (abs(a)<abs(b));
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,m;
	cin>>n>>m;
	vector<lli> alum;
	vector<lli> alumpi;
	for( lli i=0; i<n; i++){
		lli x,y;
		cin>>x>>y;
		vector<lli> nm;
		alumpi.push_back(x);
		pvs[x]=true;
		for( lli j=0; j<y; j++){
			 lli aux;
			 cin>>aux;
			 nm.push_back(aux);	
		}
		sort(nm.begin(),nm.end());
		alp.insert({x,nm});
	}
	bool ans=true;
	for( lli i=0; i<m; i++){
		lli x,y;
		cin>>x>>y;
		vector<lli> nm;
		pvs[x]=false;
		for( lli j=0; j<y; j++){
			 lli aux;
			 cin>>aux;
			 nm.push_back(aux);	
		}
		sort(nm.begin(),nm.end());
		if( alp.find(x)== alp.end()){
			for( lli j=0; j<nm.size(); j++){
				nm[j]*=-1;
			}
			err.insert({x,nm});
			alum.push_back(x);
		}else{
			if( alp[x]!= nm){
				lli it=0,i=0;
				vector<lli> psbl;
				for( i=0; i<alp[x].size() && it <nm.size(); i++){
					if(nm[it]==alp[x][i]){
						it++;
					}else{
						if(alp[x][i]>nm[it]){
							psbl.push_back(nm[it]*-1);
							it++;
							i--;
						}else{
							psbl.push_back(alp[x][i]);
						}
					}
				}
				for( ; i<alp[x].size(); i++){
					psbl.push_back(alp[x][i]);
				}
				for( ;it< nm.size(); it++){
					psbl.push_back(nm[it]*-1);
				}
				err.insert({x,psbl});
				alum.push_back(x);
			}
		}
	}
	for( lli i=0; i<alumpi.size(); i++){
		if(pvs[alumpi[i]]==true){
			alum.push_back(alumpi[i]);
			err.insert({alumpi[i],alp[alumpi[i]]});
		}
	}
	if( alum.empty()){
		cout<<"GREAT WORK! NO MISTAKES FOUND!"<<endl;
	}else{
		lli notr=0, miss=0;
		sort(alum.begin(),alum.end());
		for( lli i=0; i<alum.size(); i++){
			lli x=alum[i];
			if(!err[x].empty()){
			cout<<x<<" ";
			sort(err[x].begin(),err[x].end(),ej);
			for( lli j=0; j<err[x].size(); j++){
				if(err[x][j]>0){
					cout<<"+"<<err[x][j];
					miss++;
				}else{
					cout<<err[x][j];
					notr++;
				}
				if(j+1<err[x].size())cout<<" ";
			}
			cout<<endl;
			}
		}
		cout<<"MISTAKES IN "<<alum.size()<<" STUDENTS: "<<notr<<" NOT REQUESTED, "<<miss<<" MISSED"<<endl;
	}
}
