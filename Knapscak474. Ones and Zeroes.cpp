//    memoization
class Solution {
public:
         int dp[102][102][602];
       vector<int> count(string s){
           
           vector<int>freq(2,0);
           
           for(auto it:s){
               
               freq[it-'0']++;
           }
           
           return freq;
           
           
       }
    
    
        int helper(vector<string>&s,int zeros,int ones,int idx){
            
            if(idx==s.size() or zeros+ones==0){
                return 0;
            }
            
           if( dp[zeros][ones][idx]!=-1){
               
               return dp[zeros][ones][idx];
           }
            vector<int>freq=count(s[idx]);
            
              int pick=0;
            if(zeros>=freq[0] and ones>=freq[1]){
                
                pick=1+helper(s,zeros-freq[0],ones-freq[1],idx+1);
                
            }
            
            int notpick=helper(s,zeros,ones,idx+1);
            
         return   dp[zeros][ones][idx]=max(pick,notpick);
            
            
        }
        
       
    int findMaxForm(vector<string>& s, int m, int n) {
        
                 int size=s.size();
                  
        
              memset(dp,-1,sizeof(dp));
        
           return helper(s,m,n,0);
         
    }
};



//  tabular dp

class Solution {
public:
       vector<int> count(string s){
           
           vector<int>freq(2,0);
           
           for(auto it:s){
               
               freq[it-'0']++;
           }
           
           return freq;
           
           
       }
    

        
       
    int findMaxForm(vector<string>& s, int m, int n) {
        
                 int size=s.size();
                  
                 int dp[m+1][n+1];
              memset(dp,0,sizeof(dp));
        
        
           for(int i=0;i<size;i++){
               
               
               vector<int>freq=count(s[i]);
               for(int j=m;j>=freq[0];j--){
                   
                   
                   for(int k=n;k>=freq[1];k--){
                       
                       dp[j][k]=max( dp[j-freq[0]][k-freq[1]]+1,dp[j][k]);
                   }
               }
           }
        
        
     
        
        return dp[m][n];
          
        
        
            
         
    }
};
