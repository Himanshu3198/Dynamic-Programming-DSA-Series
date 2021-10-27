class Solution {
public:
    int getMaxLen(vector<int>& a) {
     
        
          int n=a.size();
        
         
        
        int i=0,ans=0;
        
        while(i<n){
            
            
            int j=i,cnt=0,first=-1,last=-1;
            
            while(i<n and a[i]!=0){
                
                cnt+=a[i]<0;
                
                if(a[i]<0){
                    
                    if(first==-1)
                       first=i;
                    
                     last=i;
                }
              
                i++;
            }
            
            if(cnt%2){
                
                ans=max({ans,i-first-1,last-j});
            }
            else{
                
                ans=max(ans,i-j);
            }
            
            while(i<n and a[i]==0) ++i;
            
            
        }
        
        return ans;
        
        
    }
};
