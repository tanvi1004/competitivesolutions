/*

        /////////   //////      ////      ////
        //         //   //     //   //  // //
        //////    //    //    //     //   //
            //   // /// //   //          //
      ////////  //      //  //          //
*/

#include<bits/stdc++.h>
#include<assert.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long ull;
#define Fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fo(i,s,n) for(int i=s;i<n;i++)
#define pb(x) push_back(x);
#define mod 1000000007


int main()
{
    Fast
    int n,sum;
    cin>>n>>sum;
    ll a[n];
    fo(i,0,n)
        cin>>a[i];
    ll dp[sum+1];
    fo(i,0,sum+1)
        dp[i]=sum+1;
    dp[0]=0;
    for(int i=1;i<=sum;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i-a[j]>=0)
            {
                if(dp[i-a[j]]<dp[i])
                    dp[i]=dp[i-a[j]]+1;
            }
                

        }
    }
    if(dp[sum]==sum+1)
        cout<<-1<<endl;
    else
    {
       cout<<dp[sum]<<endl;
    }
    
    
    return 0;
}