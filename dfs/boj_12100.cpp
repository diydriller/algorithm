#include<cstdio>
#include<vector>
#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

int n,ans=INT_MIN;
vector<vector<int> > mat;

void up(){
	for(int j=0;j<n;j++){
		for(int i=0;i<n;i++){
			if(mat[i][j]==0) continue;
			
			int k;
			for(k=i;k>=1;k--){
				if(mat[k-1][j]!=0) break;
			}
			if(k!=i){
				mat[k][j]=mat[i][j];
				mat[i][j]=0;
			}
		}
	}
	
	for(int j=0;j<n;j++){
		for(int i=1;i<n;){
			if(mat[i][j]==mat[i-1][j]){
				mat[i-1][j]*=2;
				mat[i][j]=0;
				i+=2;
			}
			else i++;
		}
	}

	for(int j=0;j<n;j++){
		for(int i=0;i<n;i++){
			if(mat[i][j]==0) continue;
			
			int k;
			for(k=i;k>=1;k--){
				if(mat[k-1][j]!=0) break;
			}
			if(k!=i){
				mat[k][j]=mat[i][j];
				mat[i][j]=0;
			}
		}
	}
}

void left(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(mat[i][j]==0) continue;
			
			int k;
			for(k=j;k>=1;k--){
				if(mat[i][k-1]!=0) break;
			}
			if(k!=j){
				mat[i][k]=mat[i][j];
				mat[i][j]=0;
			}
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=1;j<n;){
			if(mat[i][j]==mat[i][j-1]){
				mat[i][j-1]*=2;
				mat[i][j]=0;
				j+=2;
			}
			else j++;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(mat[i][j]==0) continue;
			
			int k;
			for(k=j;k>=1;k--){
				if(mat[i][k-1]!=0) break;
			}
			if(k!=j){
				mat[i][k]=mat[i][j];
				mat[i][j]=0;
			}
		}
	}
}

void right(){

	for(int i=0;i<n;i++){
		for(int j=n-1;j>=0;j--){
			if(mat[i][j]==0) continue;
			
			int k;
			for(k=j;k<n-1;k++){
				if(mat[i][k+1]!=0) break;
			}
			if(k!=j){
				mat[i][k]=mat[i][j];
				mat[i][j]=0;
			}
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=n-2;j>=0;){
			if(mat[i][j]==mat[i][j+1]){
				mat[i][j+1]*=2;
				mat[i][j]=0;
				j-=2;
			}
			else j--;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=n-1;j>=0;j--){
			if(mat[i][j]==0) continue;
			
			int k;
			for(k=j;k<n-1;k++){
				if(mat[i][k+1]!=0) break;
			}
			if(k!=j){
				mat[i][k]=mat[i][j];
				mat[i][j]=0;
			}
		}
	}
}

void down(){
	for(int j=0;j<n;j++){
		for(int i=n-1;i>=0;i--){
			if(mat[i][j]==0) continue;
			
			int k;
			for(k=i;k<n-1;k++){
				if(mat[k+1][j]!=0) break;
			}
			if(k!=i){
				mat[k][j]=mat[i][j];
				mat[i][j]=0;
			}
		}
	}
	
	for(int j=0;j<n;j++){
		for(int i=n-2;i>=0;){
			if(mat[i][j]==mat[i+1][j]){
				mat[i+1][j]*=2;
				mat[i][j]=0;
				i-=2;
			}
			else i--;
		}
	}

	for(int j=0;j<n;j++){
		for(int i=n-1;i>=0;i--){
			if(mat[i][j]==0) continue;
			
			int k;
			for(k=i;k<n-1;k++){
				if(mat[k+1][j]!=0) break;
			}
			if(k!=i){
				mat[k][j]=mat[i][j];
				mat[i][j]=0;
			}
		}
	}	
}

void dfs(int d){
	if(d==5){
		
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(ans<mat[i][j]) ans=mat[i][j];
			}
		}
		
		return;
	}
	vector<vector<int> > _mat;
	_mat.assign(mat.begin(),mat.end());
	
	up();
	dfs(d+1);
	mat.assign(_mat.begin(),_mat.end());
	left();
	dfs(d+1);
	mat.assign(_mat.begin(),_mat.end());
	right();
	dfs(d+1);
	mat.assign(_mat.begin(),_mat.end());
	down();
	dfs(d+1);
	mat.assign(_mat.begin(),_mat.end());
	
}


int main(){
	
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		vector<int> ele(n,0);
		mat.push_back(ele);
		for(int j=0;j<n;j++){
			int p;
			scanf("%d",&p);
			mat[i][j]=p;
		}
	}
	
	dfs(0);
	
	cout<<ans;
	
	
	
	
	
	
	
	
	
	
	
	
	
}
