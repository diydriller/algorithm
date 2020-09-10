#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int n,m;
vector<int> v;
bool check[8];

void dfs(int x,int d){
	
	if(d==m){
		for(int i=0;i<n;i++){
			if(check[i]) printf("%d ",v[i]); 
		}
		printf("\n");
		return;
	}
	
	
	for(int i=x;i<n;i++){
		if(check[i]) continue;
		check[i]=true;
		dfs(i+1,d+1);
		check[i]=false;	
	}
}



int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		int p;
		scanf("%d",&p);
		v.push_back(p);
	}
	
	sort(v.begin(),v.end());
	
	dfs(0,0);
	
	
	
	
	
}
