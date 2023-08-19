class Solution {
public:
   
    int dp[1001][1001];
    int solve(string &s1,string &s2,int i,int j,unordered_map<char,int>&mp){
        
        if(i==s1.size() || j==s2.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int curr=0;
        if(s1[i]==s2[j]){
            
            curr=mp[s1[i]]+solve(s1,s2,i+1,j+1,mp);
        }else{
            curr=max(solve(s1,s2,i,j+1,mp),solve(s1,s2,i+1,j,mp));
        }
        return dp[i][j]=curr;   
    }
    int minimumDeleteSum(string s1, string s2) {
       
        memset(dp,-1,sizeof(dp));
        int tot=0;
         unordered_map<char,int>mp;
        int  ptr=97;
    
        for(char c='a';c<='z';c++){
            mp[c]=ptr++;
        }
        ptr=65;
        for(char c='A';c<='Z';c++){
            mp[c]=ptr++;
        }
        for(auto &it:s1) tot+=(mp[it]);
        for(auto &it:s2) tot+=(mp[it]);
        int res=tot-2*solve(s1,s2,0,0,mp);
        return res;
        
    }                   
};

// ***********tabuluation**********************
int minimumDeleteSum(string s1, string s2) {
       
        memset(dp,0,sizeof(dp));
        int tot=0,n=s1.size(),m=s2.size();
        unordered_map<char,int>mp;
        int  ptr=97;
    
        for(char c='a';c<='z';c++){
            mp[c]=ptr++;
        }
        ptr=65;
        for(char c='A';c<='Z';c++){
            mp[c]=ptr++;
        }
        for(auto &it:s1) tot+=(mp[it]);
        for(auto &it:s2) tot+=(mp[it]);
          
         for(int i=n-1;i>=0;i--){
             for(int j=m-1;j>=0;j--){
                 int curr=0;
                 if(s1[i]==s2[j]){
                     curr=mp[s1[i]]+dp[i+1][j+1];
                 }else{
                     curr=max(dp[i][j+1],dp[i+1][j]);
                 }
                 dp[i][j]=curr;
             }
         }
        int res=tot-2*dp[0][0];
        return res;
        
    }                   
};
