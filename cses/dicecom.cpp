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

ll solve(ll n ,int a[])
{
    ll dp[n+2]={0};
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<6;j++)
        {
            if(i-a[j]>=0)
                dp[i]+=(dp[i-a[j]])%mod;
            dp[i]=dp[i]%mod;
        }

    }
    return dp[n]%mod;
    

}

int main()
{
    Fast
    ll n;
    cin>>n;
    int a[6]={1,2,3,4,5,6};
    cout<<solve(n,a)<<endl;

    return 0;
}