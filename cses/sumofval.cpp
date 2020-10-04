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
    ll n,x;
    cin>>n>>x;
    map<ll,int>mp;
    ll a[n];
    fo(i,0,n)
    {
        //ll a;
        cin>>a[i];
        mp.insert(pair<ll,int>(a[i],i+1));
    }

    fo(i,0,n)
    {
       ll temp=x-a[i];
       auto it=mp.find(temp);
       if(it!=mp.end()&&it->second!=i+1)
       {
           cout<<i+1<<" "<<it->second;
           return 0;
       }


    }
    cout<<"IMPOSSIBLE";

    return 0;
}