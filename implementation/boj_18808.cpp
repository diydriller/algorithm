#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

int n,m,k;
vector<vector<int> > st[101];
vector<vector<int> > ans;



bool trans(int x,int y,int idx){
	
	if(x>n||y>m) return false;
	
	for(int i=0;i<=n-x;i++){
		for(int j=0;j<=m-y;j++){
			
			bool check=true;
			
			for(int ii=0;ii<x;ii++){
				for(int jj=0;jj<y;jj++){
					if(st[idx][ii][jj]==1&&ans[i+ii][j+jj]==1){
						check=false;
					}
				}
			}
			
			if(check){
				for(int ii=0;ii<x;ii++){
					for(int jj=0;jj<y;jj++){
						if(st[idx][ii][jj]==1) ans[i+ii][j+jj]=1;
					}
				}
				return true;
			}
			
			
		}
	}
	return false;
}

void rot(int x,int y,int idx){
	
	int t=(x>y?x:y);
	
	vector<vector<int> > tmp;
	for(int i=0;i<t;i++){
		vector<int> ele(t,0);
		tmp.push_back(ele);
	}
	
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			tmp[j][x-1-i]=st[idx][i][j];
		}
	}
	
	for(int i=0;i<t;i++){
		for(int j=0;j<t;j++){
			st[idx][i][j]=tmp[i][j];
		}
	}
	
	
	
	
}



int main(){
	
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<n;i++){
		vector<int> ele(m,0);
		ans.push_back(ele);
	}
	
	for(int i=0;i<k;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		
		int t=(x>y?x:y);
		for(int j=0;j<t;j++){
			vector<int> ele(t,0);
			st[i].push_back(ele);
		}
		
		for(int j=0;j<x;j++){
			for(int k=0;k<y;k++){
				int z;
				scanf("%d",&z);
				st[i][j][k]=z;
			}
		}
		
	
		
		
		
		for(int j=0;j<4;j++){
			if(trans(x,y,i)) break;
			rot(x,y,i);
			swap(x,y);
		}
		
		
		
		
	}
	
	int cnt=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(ans[i][j]==1) cnt++; 
		}
	}
	
	printf("%d",cnt);
	
	
	
	
	
}
