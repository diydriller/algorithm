#include <string>
#include <vector>
#include <climits>
using namespace std;

int solution(vector<int> c) {
    
    if(c.size()==1) return 0;
    
    c.insert(c.begin(),0);
    c.push_back(0);
    int len=c.size();
    int ans=INT_MIN;
    
    for(int i=1;i<len-2;i++){
        int s1=i,e1=i,s2=i+1,e2=i+1,sum1=0,sum2=0;
        
        while(1){
            if(e1==0&&e2==len-1){
                if(sum1==sum2) ans=max(ans,sum1);
                break;
            }
            
            if(e1==0){
                if(sum1==sum2) ans=max(ans,sum1);
                sum2+=c[e2++];
                continue;
            }
            if(e2==len-1){
                if(sum1==sum2) ans=max(ans,sum1);
                sum1+=c[e1--];
                continue;
            }
            
            
            if(sum1==sum2){
                ans=max(ans,sum1);
                sum1+=c[e1--];
                sum2+=c[e2++];
            }
            else if(sum1<sum2){
                sum1+=c[e1--];
            }
            else if(sum1>sum2){
                sum2+=c[e2++];
            }
        }

        
        
        
    }
    

    
    return ans;
    
}
