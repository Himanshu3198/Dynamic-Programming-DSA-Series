class Solution {
public:
    
    /*  complexity O(nlog(n))
        space complexity O(n) since we are using extra vector space
        
        Appproach : The idea is to sort envelopes width in increasing order if the two 
                     envelopes has same width then sort then envelopes by its height in 
                      decreasing order  after that just do standard LIS of O(Nlog(N)) type
                      
        */
    
  static bool cmp(const vector<int>&v1,const vector<int>&v2){
         
         if(v1[0]==v2[0]) {
       
            return v1[1]>v2[1];
        }
   
      return v1[0]<v2[0];
     }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
    sort(envelopes.begin(),envelopes.end(),cmp);
              
        vector<int>dp;
        dp.push_back(envelopes[0][1]);

       int n=envelopes.size();
     
       for(int i=1;i<n;i++){
   
         if(dp.back()<envelopes[i][1]){
  
           dp.push_back(envelopes[i][1]);
          }else{
             auto it=lower_bound(dp.begin(),dp.end(),envelopes[i][1]);
                *it=envelopes[i][1];
          }
         }

    return dp.size();
     
    }
};
