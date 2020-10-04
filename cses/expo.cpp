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

ll powera(ull a,ull b)
{
    a=a%(Mod-1);
    b=b%(Mod-1);
    if(a==0&&b==0)
        return 1;
    if(a<=1)
        return a;
    else
    {
        
        ll ans=1;
        while(b>0)
        {
            if(b%2)
                ans=(ans*a)%(Mod-1);
            b=b/2;
            a=(a*a)%(Mod-1);
        }
        return ans%(Mod-1);

    }
    
}


ll power(ull a,ull b)
{
    a=a%Mod;
    b=b%Mod;
    if(a==0&&b==0)
        return 1;
    if(a<=1)
        return a;
    else
    {
        
        ll ans=1;
        while(b>0)
        {
            if(b%2)
                ans=(ans*a)%Mod;
            b=b/2;
            a=(a*a)%Mod;
        }
        return ans%Mod;

    }
    
}

int main()
{
    Fast
    int t;
    cin>>t;
    while(t--)
    {
        ull a,b,c;
        cin>>a>>b>>c;
        cout<<power(a,(powera(b,c)))<<endl;
    }
    return 0;
}