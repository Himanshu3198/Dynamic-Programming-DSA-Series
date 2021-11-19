class Solution {
public:
   
    
    int findSubstringInWraproundString(string p) {

           vector<int>freq(26,0);
        
           int maxlen=1;
        
        for(int i=0;i<p.length();i++){
             
            if(i>0 and (p[i]-p[i-1]==1 or p[i-1]-p[i]==25) ){
                maxlen++;
            }
              else{
                   maxlen=1;
              } 
               
            
            freq[p[i]-'a']=max(freq[p[i]-'a'],maxlen);
        }
               
              int res=0;
               for(auto it:freq) res+=it;
               
               return res;
               
        
    }
};
