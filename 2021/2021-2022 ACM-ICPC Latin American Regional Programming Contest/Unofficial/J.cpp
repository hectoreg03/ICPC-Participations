#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
const int mxn=1e5+10;
bool pv[mxn];
vector<pair<pair<int,int>,int> > pts;
int h,w;
bool comp(int x1,int x2,int y1,int y2){
	bool pnt1=false, pnt2=false;
	if(x1==0||y1==0||y1==h||x1==w)pnt1=true;
	if(x2==0||y2==0||y2==h||x2==w)pnt2=true;
	return (pnt1&&pnt2);
}
bool ord(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
	if(a.f.s==0){
		if( b.f.s==0)return a.f.f<b.f.f;
		else return true;
	}else{
		if(b.f.s==0)return false;
		else{
			//Numero 2
			if(a.f.f==w){
				if( b.f.f==w)return a.f.s<b.f.s;
				else return true;
			}else{
				if(b.f.f==w)return false;
				else{
					// Numero 3
					if(a.f.s==h){
						if( b.f.s==h)return a.f.f>b.f.f;
						else return true;
					}else{
						if(b.f.s==h)return false;
						else{
							return a.f.s>b.f.s;	
						}
					}	
				}
			}	
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>w>>h>>n;
	int x1,x2,y1,y2;
	for( int i=0; i<n; ++i){
		cin>>x1>>y1>>x2>>y2;
		if(comp(x1,x2,y1,y2)){
			pts.push_back({{x1,y1},i});
			pts.push_back({{x2,y2},i});
		}
	}
	sort(pts.begin(),pts.end(),ord);
	stack<int> cl;
	bool ans=true;
	for( int i=0; i<pts.size(); ++i){
		if(pv[pts[i].second]==false){
			cl.push(pts[i].second);
			pv[pts[i].second]=true;
		}else{
			if(cl.top()!=pts[i].second){
				ans=false;
				break;
			}else{
				cl.pop();
			}
		}
	}
	if(ans==true)cout<<"Y";
	else cout<<"N";
}