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


void solve(int n,int x,int a[])
{
    ll dp[x+1]={0};
    dp[0]=1;
    for(int i=1;i<=x;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i-a[j]>=0)
            {
                dp[i]+=(dp[i-a[j]]%mod);
                dp[i]=dp[i]%mod;
            }
        }
    }
    cout<<dp[x]<<endl;
}

int main()
{
    Fast
    int n,x;
    cin>>n>>x;
    int a[n];
    fo(i,0,n)
        cin>>a[i];
    solve(n,x,a);
    
    return 0;
}