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
    int  n;
    cin>>n;
    vector<pair<ll,ll>>a(n);
    fo(i,0,n)
    {
        cin>>a[i].second;
        cin>>a[i].first;
    }
    sort(a.begin(),a.end());
    ll count=0, entry=0;
    fo(i,0,n)
    {
        if(a[i].second>=entry)
        {
            count++;
            entry=a[i].first;
        }
    }


    cout<<count<<endl;
    return 0;
}