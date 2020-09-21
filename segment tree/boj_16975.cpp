#include<cstdio>
#include<cstdlib>
#include<cstring>
typedef long long int ll;
int n,m;
ll *mat,*tree,*lazy;


ll init(int s,int e,int node){
	
	if(s==e) return tree[node]=mat[s]; 
	
	int mid=(s+e)/2;
	return tree[node]=init(s,mid,node*2)+init(mid+1,e,node*2+1);
}

void update(int s,int e,int node,int l,int r,ll val){
	
	if(l>e||r<s) return;
	if(l<=s&&e<=r){
		lazy[node]+=val;
		return;
	}
	int mid=(s+e)/2;
	update(s,mid,node*2,l,r,val);
	update(mid+1,e,node*2+1,l,r,val);
}


void print(int s,int e,int node,int idx,ll acc){
	if(idx<s||idx>e) return;
	
	if(s==e){
		printf("%lld\n",tree[node]+acc+lazy[node]);
		return;
	}
	int mid=(s+e)/2;
	print(s,mid,node*2,idx,acc+lazy[node]);
	print(mid+1,e,node*2+1,idx,acc+lazy[node]);
	
	
}


int main(){
	scanf("%d",&n);
	
	mat=(ll*)malloc(sizeof(ll)*n);
	for(int i=0;i<n;i++) scanf("%lld",&mat[i]);
	
	tree=(ll*)malloc(sizeof(ll)*4*n);
	lazy=(ll*)malloc(sizeof(ll)*4*n);
	for(int i=0;i<4*n;i++) lazy[i]=0;
	
	init(0,n-1,1);
	
	scanf("%d",&m);
	while(m--){
		int p;
		scanf("%d",&p);
		
		if(p==1){
			int i,j;
			ll k;
			scanf("%d %d %lld",&i,&j,&k);
			update(0,n-1,1,i-1,j-1,k);
		}
		else if(p==2){
			int x;
			scanf("%d",&x);
			print(0,n-1,1,x-1,0);
		}
		
	}
	
	
	
	
	
}
