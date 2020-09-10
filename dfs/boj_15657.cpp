#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;
int n,m;
vector<int> v;
int num[8];

void dfs(int d){
	
	if(d==m){
		for(int i=0;i<m;i++){
			printf("%d ",num[i]);
		}
		printf("\n");
		return;
	}
	
	for(int i=0;i<n;i++){
		if(d!=0&&num[d-1]>v[i])  continue;
		num[d]=v[i];
		dfs(d+1);
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
