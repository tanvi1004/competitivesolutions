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

ll solve(ll a[],ll n,ll x)
{
    ll count=0;
    ll *head=a,*tail=a+n-1;
    while(tail>=head)
    {
        
        if((*tail)+(*head)<=x)
        {
            head++;
            tail--;
            count++;
        }
        else 
        {
            tail--;
            count++;
        }

    }
    return count;
}

int main()
{
    Fast
    ll n,x;
    cin>>n>>x;
    ll a[n];
    fo(i,0,n)
        cin>>a[i];
    sort(a,a+n);
    cout<<solve(a,n,x)<<endl;
    return 0;
}