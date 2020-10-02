#include<cstdio>
#include<climits>
#include<algorithm>
#include<iostream>
using namespace std;
int n;
int mat[1001][3];
int dp[1001][3];

int main(){
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++){
			scanf("%d",&mat[i][j]);
		}
	}
	
	int ans=INT_MAX;
	
	//first r
	dp[1][0]=mat[1][0];
	dp[2][1]=dp[1][0]+mat[2][1];
	dp[2][2]=dp[1][0]+mat[2][2];
	
	if(n>2){
		
		dp[3][0]=min(dp[2][1],dp[2][2])+mat[3][0];
		dp[3][1]=dp[2][2]+mat[3][1];
		dp[3][2]=dp[2][1]+mat[3][2];
	
		for(int i=4;i<=n;i++){
			dp[i][0]=min(dp[i-1][1],dp[i-1][2])+mat[i][0];
			dp[i][1]=min(dp[i-1][0],dp[i-1][2])+mat[i][1];
			dp[i][2]=min(dp[i-1][0],dp[i-1][1])+mat[i][2];
		}
	}
	ans=min(ans,min(dp[n][1],dp[n][2]));
	
	//first g
	dp[1][1]=mat[1][1];
	dp[2][0]=dp[1][1]+mat[2][0];
	dp[2][2]=dp[1][1]+mat[2][2];
	
	if(n>2){
		dp[3][1]=min(dp[2][0],dp[2][2])+mat[3][1];
		dp[3][0]=dp[2][2]+mat[3][0];
		dp[3][2]=dp[2][0]+mat[3][2];
	
	
		for(int i=4;i<=n;i++){
			dp[i][0]=min(dp[i-1][1],dp[i-1][2])+mat[i][0];
			dp[i][1]=min(dp[i-1][0],dp[i-1][2])+mat[i][1];
			dp[i][2]=min(dp[i-1][0],dp[i-1][1])+mat[i][2];
		}
		
	}
	ans=min(ans,min(dp[n][0],dp[n][2]));

		
	//first b
	dp[1][2]=mat[1][2];
	dp[2][0]=dp[1][2]+mat[2][0];
	dp[2][1]=dp[1][2]+mat[2][1];
	
	if(n>2){
		dp[3][2]=min(dp[2][0],dp[2][1])+mat[3][2];
		dp[3][0]=dp[2][1]+mat[3][0];
		dp[3][1]=dp[2][0]+mat[3][1];

		for(int i=4;i<=n;i++){
			dp[i][0]=min(dp[i-1][1],dp[i-1][2])+mat[i][0];
			dp[i][1]=min(dp[i-1][0],dp[i-1][2])+mat[i][1];
			dp[i][2]=min(dp[i-1][0],dp[i-1][1])+mat[i][2];
		}	
	}
	ans=min(ans,min(dp[n][0],dp[n][1]));

	
	printf("%d",ans);
	
	
	
	
	
	
	
	
	
}
