// Maximum difference of zeros and ones in binary string  gfg||leetcode

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:	
	int maxSubstring(string S)
	{
	    // Your code goes here
	  
	    
	   int n=S.length();
	   
	   int val,csum=0,ans=0;
	   
	   
	   for(int i=0;i<n;i++){
	       
	       
	       if(S[i]=='0'){
	           
	           val=1;
	       }
	       else{
	           val=-1;
	       }
	       
	       if(csum>0){
	           
	           csum+=val;
	       }
	       else{
	           csum=val;
	       }
	       
	       if(csum>ans){
	           ans=csum;
	       }
	   }
	   
	   if(ans<=0){
	       ans=-1;
	   }
	   
	   return ans;
	 
	}
};



int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}
