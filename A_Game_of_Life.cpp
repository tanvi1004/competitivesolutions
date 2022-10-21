/*
        /////////  /////      ////     ///
        //        //   //    //  // // //
        //////   //    //   //   //   //
            //  // /// //  //        //
      //////// //      // //        //
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

#define Fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(0);
#define rep(i, s, n) for (ll i = s; i < n; i++)
#define For(i, s, l) for (ll i = l; i >= s; i--)
#define mod 1000000007
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl
#define umap unordered_map
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define lb() lower_bound()
#define ub() upper_bound()
#define S second
#define F first
#define PI 3.14159265358979323846
#define bits_all_odds 0X55555555
#define bits_all_even 0XAAAAAAAA
#define fix(num, dig) cout << fixed << setprecision(dig) << num
//fill(all(vec), 1);to fill vector with a number
//if (S.count(key)) returns 1 if set or map contain key else return 0
ll nCr(ll n, ll r)
{
    r = min(r, n - r);
    if (r < 0)
        return 0;
    if (r == 0)
        return 1;
    ll ans = 1;
    for (ll i = 1; i <= r; i++)
    {
        ans = ans * (n - i + 1) / i;
    }
    return ans;
}
ll logn(int val, int base) { return (val > base - 1) ? 1 + logn(val / base, base) : 0; }
//ll logn(int val, int base) { return (base > val - 1) ? 1 + logn(base / val, val) : 0; }
ll power(ll a, ll b)
{
    if (b == 1)
        return a;
    if (b == 0)
        return 1;
    ll m1 = power(a, b / 2);
    if (b % 2)
        return m1 * m1 * a;
    return m1 * m1;
}
bool isprime(ll a)
{
    if (a <= 1)
        return false;
    if (a == 2 || a == 3)
        return true;
    if (a % 2 == 0 || a % 3 == 0)
        return false;
    for (ll i = 5; i * i <= a; i = i + 6)
    {
        if (a % i == 0 || a % (i + 2) == 0)
            return false;
    }
    return true;
}
/*********************/ /*********************/ /*********************/ /*********************/ //
void solve()
{
    ll n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    
    vector<pair<ll,ll>>x;
    ll k=0;
    int f=0;
    ll o=0;
    rep(i,0,n)
    {
        if(s[i]=='1')
        {
            f=1;
            o++;
        }
        if(s[i]=='1'&&k>0)
        {
            
            x.pb(make_pair(o,k));
            k==0;
        }
        else if(s[i]=='0')
        {
            o=0;
            k++;
        }
    }
    if(k>0)
    {
        x.pb(make_pair(o,k));
    }
    if(f==0)
    {
        cout<<s<<endl;
        return;
    }
    
    rep(i,0,x.size())
    {
        rep(j,0,x[i].first)
            cout<<1;
        ll z=min(x[i].second-1,m);
        rep(i,0,z)
            cout<<1;
        
    }

    
}

signed main()
{
    Fast
        ll t;

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}