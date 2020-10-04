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
    ll a[n];
    fo(i,0,n)
    {
        cin>>a[i];
    }
    int maxi=0;
    fo(i,0,n)
    {
        map<ll,int>s;
        s.insert(pair<ll,int>(a[i],i));
        fo(j,i+1,n)
        {
            if(s.find(a[j])==s.end())
            {
                break;
            }
            else
            {
                s.insert(a[j]);
            }
            
            
        }
        
        cout<<i<<endl;
        int l=s.size();
        for(auto it=s.begin();it!=s.end();it++)
        {
            cout<<*it<<" ";
        }
        cout<<endl;
        maxi=max(maxi,l);

    }
    //cout<<maxi;
    return 0;
}