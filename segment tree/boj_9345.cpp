#include<cstdio>
#include<cstdlib>
#include<vector>
using namespace std;
typedef long long int ll;

int n,k;
vector<pair<ll,ll> > tree;
vector<ll> mat;

pair<ll,ll> init(int s,int e,int node){
	if(s==e){
		tree[node].first=tree[node].second=mat[s];
		return tree[node];
	}
	
	int mid=(s+e)/2;
	pair<ll,ll> f1=init(s,mid,node*2);
	pair<ll,ll> f2=init(mid+1,e,node*2+1);
	
	tree[node].first=min(f1.first,f2.first);
	tree[node].second=max(f1.second,f2.second);
	return tree[node];
}

pair<ll,ll> update(int s,int e,int node,int idx,ll val){
	
	if(s>idx||e<idx) return tree[node];
	
	if(s==e){
		tree[node].first=tree[node].second=val;
		return tree[node];
	}
	
	int mid=(s+e)/2;
	pair<ll,ll> f1=update(s,mid,2*node,idx,val);
	pair<ll,ll> f2=update(mid+1,e,2*node+1,idx,val);
	tree[node].first=min(f1.first,f2.first);
	tree[node].second=max(f1.second,f2.second);
	return tree[node];
}


pair<ll,ll> minmax(int s,int e,int node,int l,int r){
	if(r<s||l>e) return make_pair(INT_MAX,INT_MIN);
	if(l<=s&&e<=r) return tree[node];
	
	int mid=(s+e)/2;
	pair<ll,ll> f1=minmax(s,mid,node*2,l,r);
	pair<ll,ll> f2=minmax(mid+1,e,node*2+1,l,r);
	
	return make_pair(min(f1.first,f2.first),max(f1.second,f2.second));
	
}

void ex(){
	scanf("%d %d",&n,&k);
	
	mat.assign(n,0);
	tree.assign(4*n,make_pair(0,0));
	
	for(int i=0;i<n;i++){
		mat[i]=i;
	}
	
	init(0,n-1,1);
	
	for(int i=0;i<k;i++){
		int p;
		scanf("%d",&p);
		if(p==1){
			int q,r;
			scanf("%d %d",&q,&r);
			pair<ll,ll> t=minmax(0,n-1,1,q,r);
			if(t.first==q&&t.second==r)	printf("YES\n");
			else printf("NO\n"); 
		}
		else if(p==0){
			int q,r;
			scanf("%d %d",&q,&r);
			
			update(0,n-1,1,q,mat[r]);
			update(0,n-1,1,r,mat[q]);
			
			ll t=mat[q];
			mat[q]=mat[r];
			mat[r]=t;

		}
		
	}
	mat.clear();
	tree.clear();
	
}


int main(){
	int t;
	scanf("%d",&t);
	
	while(t--){
		ex();
	}
	
}
