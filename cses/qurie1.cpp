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
    int n,q;
    cin>>n>>q;
    ull arr[n];
    fo(i,0,n)
    {
       cin>>arr[i];
       if(i!=0)
        {
            arr[i]+=arr[i-1];
        }
    }
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        ull ans=0;
        if(a>=2)
            cout<<arr[b-1]-arr[a-2]<<endl;
        else
        {
            cout<<arr[b-1]<<endl;
        }
        
       // cout<<ans<<endl;
    }

    return 0;
}