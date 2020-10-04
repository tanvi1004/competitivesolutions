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
vector<int> dp(10000,-1);

int solve(int n)
{
    if(dp[n]!=-1)
        return dp[n];
    else
    {
        vector<int>a;
        int x=n;
        while(x>0)
        {
            a.push_back(x%10);
            x/=10;
        }
        int l=a.
    }
    
    
    
}
int main()
{
    Fast
    int n;
    cin>>n;
    dp[0]=0;
    solve(n);

    return 0;
}