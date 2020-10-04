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
#define pb(x) push_back(x);
#define mod 1000000007


int main()
{
    Fast
    
  int n, x;
  cin >> n >> x;
  vector<int> a(n), d(x + 1);
  for (int i = 0; i < n; i++) cin >> a[i];
  d[0] = 1;
  for (int c : a)
    for (int i = 1; i <= x; i++)
      if (c <= i) d[i] = (d[i] + d[i - c]) % 1000000007;
  cout << d[x] << "\n";

    return 0;
}