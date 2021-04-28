// Smallest sum contiguous subarray gfg

#include<bits/stdc++.h>
using namespace std;
int main(){


    int arr[]={3, -4, 2, -3, -1, 7, -5};

        int n=sizeof(arr)/sizeof(arr[0]);


        int ans=INT_MAX,csum=INT_MAX;

        for(int i=0;i<n;i++){


            if(csum>0){
                csum=arr[i];
            }
            else{
                csum+=arr[i];
            }

            ans=min(ans,csum);
        }

        cout<<ans<<"\n";
}