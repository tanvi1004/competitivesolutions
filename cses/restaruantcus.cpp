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

ll maximum(ll a, ll b)
{
    if(a>b)
        swap(a,b);
    return b;
}

ll minimum(ll a, ll b)
{
    if(a<b)
        swap(a,b);
    return b;
}

int main()
{
    Fast
    int n;
    cin>>n;
    //vector<pair<int,int>>q(n);
    ll a[n];
    ll d[n];
    fo(i,0,n)
    {
        cin>>a[i];
        cin>>d[i];
    }
    sort(a,a+n,greater<ll>());
    sort(d,d+n,greater<ll>());
    
    stack<ll>arr;
    stack<ll>dp;
    fo(i,0,n)
    {
        arr.push(a[i]);
        dp.push(d[i]);
    }
   /* fo(i,0,n)
    {
        cout<<dp.top()<<" ";
        cout<<arr.top()<<" "<<endl;
        arr.pop();
        dp.pop();
    }*/
    ll m=2*n;
    ll cur=0,ans=0,i=arr.top();
    while(m--)
    {
        //cout<<"hi";
        if(!arr.empty())
        {
            if(i==arr.top())
            {
                cur++;
                //cout<<"arr"<<endl;
                arr.pop();
                //cout<<"curr="<<cur<<endl;
            }
        }
        if(!dp.empty())
        {
        //ans=max(ans,cur);
            if(i==dp.top())
            {
                cur--;
                dp.pop();
              //  cout<<"dp"<<endl;
            //    cout<<"curr="<<cur<<endl;
            }
        }
            //cout<<"curr="<<cur<<endl;
        if(!arr.empty())
            i=minimum(arr.top(),dp.top());
        else if(!dp.empty())
        {
            i=dp.top();
        }
        
        ans=maximum(ans,cur);
        //cout<<"ans="<<ans<<endl;
    }
    cout<<ans<<endl;
   // cout<<dp.top()<<endl;
    return 0;
}