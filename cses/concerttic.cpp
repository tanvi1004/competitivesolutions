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
    int n,m;
    cin>>n>>m;
    vector<ll>h{n},t{m};
    fo(i,0,n)
        cin>>h[i];
    fo(i,0,m)
        cin>>t[i];
    sort(h.begin(),h.end(),greater<ll>());
    sort(t.begin(),t.end(),greater<ll>());
    

    return 0;
}