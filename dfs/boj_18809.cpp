#include<cstdio>
#include<vector>
#include<queue>
#include<iostream>
using namespace std;

int n,m,g,r;
int land[51][51];
vector<pair<int,int> > spot;
vector<bool> visited;

int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int ans=0;

struct info{
	int x;
	int y;
	int t;
};

void bfs(){
	queue<info> q;
	pair<int,int> t_land[51][51];
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			t_land[i][j]=make_pair(land[i][j],0);
		}
	}
	
	for(int i=0;i<spot.size();i++){
		int x=spot[i].first;
		int y=spot[i].second;
		if(t_land[x][y].first>=3){
			q.push({x,y,0});
		}
	}
	
	
	int res=0;
	
	while(!q.empty()){
		int x=q.front().x;
		int y=q.front().y;
		int t=q.front().t;
		
		q.pop();
		
		for(int i=0;i<4;i++){
			int xx=x+dx[i];
			int yy=y+dy[i];
			
			if(xx<0||xx>=n||yy<0||yy>=m) continue;
			if(t_land[x][y].first==3){
				if(t_land[xx][yy].first==4&&t_land[xx][yy].second==t+1){
					t_land[xx][yy].first=5;
					res++;
				}
				else if(t_land[xx][yy].first>=1&&t_land[xx][yy].first<=2){
					t_land[xx][yy].first=3;
					t_land[xx][yy].second=t+1;
					q.push({xx,yy,t+1});
				}
			}
			else if(t_land[x][y].first==4){
				if(t_land[xx][yy].first==3&&t_land[xx][yy].second==t+1){
					t_land[xx][yy].first=5;
					res++;
				}
				else if(t_land[xx][yy].first>=1&&t_land[xx][yy].first<=2){
					t_land[xx][yy].first=4;
					t_land[xx][yy].second=t+1;
					q.push({xx,yy,t+1});
				}
			}
			
		}
		
	}
	
	
	if(res>ans) ans=res;
	
	
}


void dfs_r(int d,int x){
	if(d==r){
		
		bfs();
		
		return;
	}
	for(int i=x;i<spot.size();i++){
		if(visited[i]) continue;
		visited[i]=true;
		land[spot[i].first][spot[i].second]=4;
		dfs_r(d+1,i+1);
		visited[i]=false;
		land[spot[i].first][spot[i].second]=2;
	}
}



void dfs_g(int d,int x){
	if(d==g){

		dfs_r(0,0);
		return;
	}
	for(int i=x;i<spot.size();i++){
		if(visited[i]) continue;
		visited[i]=true;
		land[spot[i].first][spot[i].second]=3;
		dfs_g(d+1,i+1);
		visited[i]=false;
		land[spot[i].first][spot[i].second]=2;
	}
}


int main(){

	scanf("%d %d %d %d",&n,&m,&g,&r);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int p;
			scanf("%d",&p);
			land[i][j]=p;
			if(p==2){
				spot.push_back({i,j});
			}
		}
	}
	visited=vector<bool>(spot.size(),false);
	dfs_g(0,0);
	
	
	printf("%d",ans);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
