#include <cstdio>
#include <vector>
#include <map>
#include <climits>
#include <iostream>
#include <cmath>
using namespace std;

pair<int,int> dir[9];
int ans=INT_MIN;
vector<vector<pair<int,int> > > box;

void fish_move(){
	map<int,pair<int,int> > m;
	map<int,pair<int,int> > ::iterator it;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			m.insert({box[i][j].first,make_pair(i,j)});
		}
	}
	
	for(it=m.begin();it!=m.end();it++){
		if(it->first==-1||it->first==0) continue;
		int x=it->second.first;
		int y=it->second.second;
		int d=box[x][y].second;
		int xx,yy;
		
		for(int i=0;i<8;i++){
			xx=x+dir[d].first;
			yy=y+dir[d].second;
			if(xx<0||xx>=4||yy<0||yy>=4){
				d=((d+1)%9==0?1:(d+1)%9);
				box[x][y].second=d;
				continue;
			}
			if(box[xx][yy].first==-1){
				d=((d+1)%9==0?1:(d+1)%9);
				box[x][y].second=d;
				continue;				
			}
			
			int t_n=box[xx][yy].first;
			int t_d=box[xx][yy].second;
			it->second.first=xx;
			it->second.second=yy;
			m[t_n].first=x;
			m[t_n].second=y;
			box[xx][yy].first=it->first;
			box[xx][yy].second=d;
			box[x][y].first=t_n;
			box[x][y].second=t_d;
			break;						
		}
	}
}


void dfs(int x,int y,int sum){
	
	
	sum+=box[x][y].first;
	if(sum>ans) ans=sum;
	
	box[x][y].first=-1;
	int d=box[x][y].second;
	fish_move();
	
	vector<vector<pair<int,int> > > _box;
	_box.assign(box.begin(),box.end());
	
	
	vector<pair<int,int> > pos;
	int xx=x,yy=y;
	while(1){
		xx+=dir[d].first;
		yy+=dir[d].second;
		if(xx<0||xx>=4||yy<0||yy>=4) break;
		pos.push_back({xx,yy});
	}
	

	
	for(int i=0;i<pos.size();i++){
		int xx=pos[i].first;
		int yy=pos[i].second;
		
		if(box[xx][yy].first!=0){
			box[x][y].first=0;
			dfs(xx,yy,sum);
			box.assign(_box.begin(),_box.end());
		}
	}
}


int main(){
	
	
	
	for(int i=0;i<4;i++){
		vector<pair<int,int> > ele(4);
		box.push_back(ele);
		
		for(int j=0;j<4;j++){
			int p,q;
			scanf("%d %d",&p,&q);
			box[i][j]=make_pair(p,q);
		}
	}
	
	dir[1]=make_pair(-1,0);
	dir[2]=make_pair(-1,-1);
	dir[3]=make_pair(0,-1);
	dir[4]=make_pair(1,-1);
	dir[5]=make_pair(1,0);
	dir[6]=make_pair(1,1);
	dir[7]=make_pair(0,1);
	dir[8]=make_pair(-1,1);
	
	
	
	
	dfs(0,0,0);
	printf("%d",ans);
}
