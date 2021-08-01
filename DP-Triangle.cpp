// 120. Triangle

class Solution {
public:
    
     /* the idea is to used bottom up dp eg
     
        4   1  8    10+min(4,1)      
           6  5  7  5+min(6,5)=10     
            3  4    2+  min(3,4)=5   
              2    2                   */  
    int minimumTotal(vector<vector<int>>& tri) {
        
                
         vector<int> res = tri.back();
        
        
          for(int i=tri.size()-2;i>=0;i--){
              
              for(int j=0;j<tri[i].size();j++){
                  
                  res[j]=tri[i][j]+min(res[j],res[j+1]);
              }
          }
        
        return res[0];
    }
};
