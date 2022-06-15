class Solution {
public:
    
    int dp[1001];
    bool isValid(string &s,string &t){
          int x=s.size(),y=t.size();
        if((y-x)>1 || x==y ) return false;
        
        for(int i=0;i<t.size();i++){
            
            string temp=t.substr(0,i)+t.substr(i+1,y-i-1);
            if(temp==s) return true;
        }
        return false;
    }
    int solve(vector<string>&words,int idx){
        
         if(idx>=words.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
       
        
        int cnt=1;
        for(int i=idx+1;i<words.size();i++){
            
            if(isValid(words[idx],words[i])){
                cnt=max(cnt,1+solve(words,i));
            }
        }
        return dp[idx]=cnt;
    }
    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(),words.end(),[&](string a,string b){
            return a.size()<b.size();
        });
        memset(dp,-1,sizeof(dp));
        int maxRes=1;
        for(int i=0;i<words.size();i++){
            
            maxRes=max(maxRes,solve(words,i));
        }
        return maxRes;
        
        
        
    }
};
