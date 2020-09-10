#include<stdio.h>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
int n,m;
vector<int> v;
int num[8];
map<int,int> mm;

void dfs(int d){
	
	if(d==m){
		for(int i=0;i<m;i++){
			printf("%d ",num[i]);
		}
		printf("\n");
		return;
	}
	
	for(int i=0;i<n;i++){
		if(mm[v[i]]==0||(d!=0&&num[d-1]>v[i])) continue;
		mm[v[i]]--;
		num[d]=v[i];
		dfs(d+1);
		mm[v[i]]++;
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
