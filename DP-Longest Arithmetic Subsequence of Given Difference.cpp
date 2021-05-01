// 1218. Longest Arithmetic Subsequence of Given Difference

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
          map<int,int>mp;
        int n=arr.size();
        vector<int>a(n,1);
        mp[arr[0]]=1;
        for(int i=1;i<n;i++)
        {
            if(mp[arr[i]-diff]!=0)
                a[i]=a[mp[arr[i]-diff]-1]+1;
            mp[arr[i]]=i+1;
        }
       
        return *max_element(a.begin(),a.end());
    }
};
