#include<bits/stdc++.h>
using namespace std;
const long long int mxn = 1e6+10;
long long int arr[mxn][2];
long long int mps[110][2];
long long int con[110][110];
long long int pos[110];
//pair< long long long long , long long long long> cmb()
void solve(long long int a, long long int b, long long int n){
	vector<long long int>opcs;
	for( long long int i=0; i<n;i++){
		long long int aux;
		aux=(arr[a][i/50]&(1ll<<(i%50)));
		if(aux&&pos[i]==-2){
			pos[i]=-1;
			opcs.push_back(i);
		}
	}
	bool ans = false;
	for( long long int i=0; i< opcs.size()&&ans==false;i++){
		long long int ac= opcs[i];
		if(arr[b][ac/50]&(1ll<<(ac%50))){
			vector<long long int> auxv;
			auxv.push_back(b);
			auxv.push_back(ac+1);
			long long int acc=ac;
			while(pos[acc]!=-1){
				auxv.push_back(con[acc][pos[acc]]);
				acc=pos[acc];
				auxv.push_back(acc+1);
			}
			auxv.push_back(a);
			cout<<(auxv.size()+1)/2<<endl;
			for( long long int j=auxv.size()-1; j>=0; j--){
				cout<<auxv[j]<<" ";
			}
			cout<<endl;
			ans = true;
			break;
		} else{
			for(long long int j=0; j<n;j++){
				if(con[ac][j]!=0&&pos[j]==-2){
					pos[j]=ac;
					opcs.push_back(j);
				}
			}	
		}
	}
	if( ans ==false){
		cout<<-1<<endl;
	}
}
int main(){
	long long int n,m;
	cin>>n>>m;
	for(long long int i=0; i<n;i++){
		long long int l;
		cin>>l;
		//cout<<"Valor de i:"<<i<<" "<<l<<": ";
		for( long long int j=0;j<l;j++){
			long long int x;
			cin>>x;
			//cout<<x<<" ";
			long long int aux = (mps[i][0]^arr[x][0])&arr[x][0];
			mps[i][0]|=arr[x][0];
			//if(i==0&&j==0)
			//cout<<aux<<endl;
			if(aux>0){
				for(long long int i2=0;aux>=(1ll<<i2); i2++){
					if(aux&(1ll<<i2)){
						con[i][i2]=x;
						con[i2][i]=x;
					}
				}
			}
			aux =  (mps[i][1]^arr[x][1])&arr[x][1];
			mps[i][1]|=arr[x][1];
			if(aux>0){
				for(long long int i2=0;aux>=(1ll<<i2); i2++){
					if(aux&(1ll<<i2)){
						con[i][i2+50]=x;
						con[i2+50][i]=x;
					}
				}
			}
			if(i<50){
				arr[x][0]|=(1ll<<i);
			}else{
				arr[x][1]|=(1ll<<(i%50));
			}
			//cout<<" Procesado ";
		}
		//cout<<endl;
	}
	/*
	for( long long i=0; i<n;i++){
		for( long long j=0; j<n; j++){
			cout<<con[i][j]<<" ";
		}
		cout<<endl;
	}
	*/
	long long int q;
	cin>>q;
	for( long long int i=0; i< q; i++){
		long long int a, b;
		cin>>a>>b;
		for( long long int j=0; j<110; j++){
			pos[j]=-2;
		}
		solve(a,b,n);
	}
}