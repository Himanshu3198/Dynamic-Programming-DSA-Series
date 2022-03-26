//  time complexity O(n)
//  space complexity O(1)
class Solution {
public:
    int minNumberOperations(vector<int>& target) {
     
//          the idea is increament would be max of two adjacent element
        
        int n=target.size();
         int last=target[0];
        for(int i=1;i<n;i++){
            if(target[i]>target[i-1]){
                last+=(target[i]-target[i-1]);
            }
        }
        return last;
    }
};
