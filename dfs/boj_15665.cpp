#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int n,m;
vector<int> v;
map<int,int> mm;
int num[8];

void dfs(int d){
	
	if(d==m){
		for(int i=0;i<m;i++){
			printf("%d ",num[i]);
		}
		printf("\n");
		return;
	}
	
	for(int i=0;i<mm.size();i++){
		num[d]=v[i];
		dfs(d+1);
	}
	
}



int main(){
	
	scanf("%d %d",&n,&m);
	
	for(int i=0;i<n;i++){
		int p;
		scanf("%d",&p);
		
		mm[p]++;
		if(mm[p]==1) v.push_back(p);
	}
	
	sort(v.begin(),v.end());
	
	dfs(0);
	
}
