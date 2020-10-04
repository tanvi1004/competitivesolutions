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
    ll n,m,k;
    cin>>n>>m>>k;
    ll a[n],b[m];
    fo(i,0,n)
        cin>>a[i];
    fo(i,0,m)
        cin>>b[i];
    sort(b,b+m);
    sort(a,a+n);
    int i=0,j=0;
    int count=0;
    while(i<n&&j<m)
    {
        
        if(((b[j])<=a[i]+k)&&((b[j])>=a[i]-k))
        {
            count++;
            i++;
            j++;
            
        }
        else 
        {
            if(b[j]<a[i]-k)
            {
                j++;
            }
            else 
            {
                i++;
            }
            
        }
        
    

    }
    cout<<count<<endl;
    
   
    return 0;
}