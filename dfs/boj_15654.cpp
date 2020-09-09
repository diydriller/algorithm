#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;
int n,m;
vector<int> v;
bool check[10001];
int num[8];

void dfs(int d){
	
	if(d==m){
		for(int i=0;i<m;i++){
			printf("%d ",num[i]);
		}
		printf("\n");
		return;
	}
	
	
	for(int i=0;i<v.size();i++){
		if(check[v[i]]) continue;
		check[v[i]]=true;
		num[d]=v[i];
		dfs(d+1);
		check[v[i]]=false;
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
	
	dfs(0);
	
	
	
	
	
	
}
