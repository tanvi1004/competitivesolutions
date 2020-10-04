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

void solve(int n ,ll a[],ll sum)
{
    ll dp[sum+1]={INT_MAX};
    dp[0]=0;
    for(int i=1;i<=sum;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[j]<=i)
            { 
                ll k=dp[i-a[j]];
                if(k!=INT_MAX && k+1<dp[i])
                    dp[i]=k+1;
            }
        }
    }
    /*fo(i,0,sum+1)
        cout<<dp[i]<<" ";*/
    
    if(dp[sum]==sum+1)
        cout<<-1;
    else
    {
       cout<<dp[sum];
    }
    

}
int main()
{
    Fast
    int n,sum;
    cin>>n>>sum;
    ll a[n];
    fo(i,0,n)
        cin>>a[i];
    solve(n,a,sum);
    return 0;
}