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
#define Mod 1000000007

int main()
{
    Fast
    int n;
    cin>>n;
    double a[n];//,count=0;
    fo(i,0,n)
    {
        cin>>a[i];
        //count+=a[i];
    }
   // count=floor(count/n);
   sort(a,a+n);
    ll x=0; 
    if(n%2)
    {
        x=(n+1)/2;
    }
    else
    {
        x=n/2;
    }
    
    ull ans=0;
    fo(i,0,n)
    {
        ans+=abs(a[i]-a[x]);
    }
    cout<<ans;
    return 0;
}