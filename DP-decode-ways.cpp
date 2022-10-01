
// 91. Decode Ways

class Solution {
public:
    int numDecodings(string s) {
        
        
        int n=s.length();
        
        vector<int>dp(n+1,0);
    
        dp[0]=1;
         if(s[0]!='0'){
             dp[1]=1;
         }
     
        for(int i=2;i<=n;i++){
            
            
            int oneDigit=s[i-1]-'0';
            int twoDigit=(s[i-2]-'0')*10+(s[i-1]-'0');
            
            
            if(oneDigit>=1 and oneDigit<=9){
                dp[i]+=dp[i-1];
            }
            
            if(twoDigit>=10 and twoDigit<=26){
                dp[i]+=dp[i-2];
            }
        }
        
        for(auto it:dp){
            cout<<it<<" ";
        }
        
        return dp[n];
    }
};

//  memoization

class Solution {
   
    public int numDecodings(String s) {
        int [] dp=new int[s.length()+1];
        return solve(dp,s,0);
    }
    public  int solve(int []dp,String s,int idx){
        if(idx==s.length()) return 1;
        if(dp[idx]!=0) return dp[idx];
        if(s.charAt(idx)=='0') return 0;
        int ans=solve(dp,s,idx+1);
        if(s.charAt(idx)=='1' && idx+1<s.length() && s.charAt(idx+1)<='9'){
            ans+=solve(dp,s,idx+2);
        }else if(s.charAt(idx)=='2' && idx+1<s.length() && s.charAt(idx+1)<='6'){
            ans+=solve(dp,s,idx+2);
        }
        return dp[idx]=ans;
    }
}
