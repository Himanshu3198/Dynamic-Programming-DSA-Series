// 241. Different Ways to Add Parentheses

class Solution {
public:
    unordered_map<string,vector<int>>dp;
    
    
      int evaluate(int x,char c,int y){
          
          
          if(c=='+') return x+y;
          
          if(c=='-') return x-y;
          
          if(c=='*')  return x*y;
          
          return 0;
      }
    
     vector<int>solve(string exp){
         
           if(dp.find(exp)!=dp.end()){
               
               return dp[exp];
           }
         vector<int>res;
         
         for(int i=0;i<exp.length();i++){
             
               
             if(!isdigit(exp[i])){
                 
                 
                 vector<int>left=solve(exp.substr(0,i));
                 vector<int>right=solve(exp.substr(i+1));
                 
                 
                 for(auto x:left){
                     
                     for(auto y:right){
                         
                         
                         int ans=evaluate(x,exp[i],y);
                         
                         res.push_back(ans);
                     }
                 }
             }
         }
         
         if(res.size()==0){ 
             res.push_back(stoi(exp));
         }
           dp[exp]=res;
         return res;
     }
    
    vector<int> diffWaysToCompute(string exp) {
        
        
       return solve(exp);
    }
};
