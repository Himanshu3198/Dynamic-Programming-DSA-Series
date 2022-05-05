
class Solution {
public:
/*  the main goal of this problem is to make valid combination of the boxes
    (if we pick  first two boxes then configuration of boxes should be like 
    this height[i-1]<=height[i] && width[i-1]<=width[i] && breath[i-1]<=breath[i]
    we can achive this by sorting the boxex by sum of sides in increasing order
    and then we need to maximize height so we sort l b h so that we can get 
    max height at last index then just do standard LIS to find maximum
    stacking order.
    
    time complexity O(2nlog(n)+n*n)
    space complexity O(n)
    */
    int maxHeight(vector<vector<int>>& cuboids) {
           int n=cuboids.size(); 
           sort(cuboids.begin(),cuboids.end(),[](auto &a,auto &b){
                   return (a[0]+a[1]+a[2])<(b[0]+b[1]+b[2]);
           });
          for(int i=0;i<n;i++){
              sort(cuboids[i].begin(),cuboids[i].end());
              // cout<<cuboids[i][0]<<" "<<cuboids[i][1]<<" "<<cuboids[i][2]<<"\n";
            
          }
         vector<int>lis(n,0);
         lis[0]=cuboids[0][2];
          for(int i=0;i<n;i++){
              for(int j=0;j<i;j++){
                  if(cuboids[i][0]>=cuboids[j][0] && cuboids[i][1]>=cuboids[j][1] && cuboids[i][2]>=cuboids[j][2]){
                      lis[i]=max(lis[i],lis[j]+cuboids[i][2]);
                  }else lis[i]= max(lis[i],cuboids[i][2]);
              }
          }
          return *max_element(lis.begin(),lis.end());     
    }
    
};
