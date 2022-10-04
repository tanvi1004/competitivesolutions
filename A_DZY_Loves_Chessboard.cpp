// /*
//         /////////  /////      ////     ///
//         //        //   //    //  // // //
//         //////   //    //   //   //   //
//             //  // /// //  //        //
//       //////// //      // //        //
// */

// #include <bits/stdc++.h>
// using namespace std;

// typedef long long int ll;
// typedef unsigned long long ull;
// typedef pair<int, int> pii;
// typedef pair<ll, ll> pll;
// typedef vector<int> vi;
// typedef vector<ll> vl;

// #define Fast                          \
//     ios_base::sync_with_stdio(false); \
//     cin.tie(NULL);                    \
//     cout.tie(0);
// #define rep(i, s, n) for (int i = s; i < n; i++)
// #define For(i, s, l) for (int i = l; i >= s; i--)
// #define mod 1000000007
// #define deb(x) cout << #x << "=" << x << endl
// #define deb2(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl
// #define umap unordered_map
// #define pb(x) push_back(x)
// #define all(x) (x).begin(), (x).end()
// #define lb() lower_bound()
// #define ub() upper_bound()
// #define S second
// #define F first
// #define PI 3.14159265358979323846
// #define bits_all_odds 0X55555555
// #define bits_all_even 0XAAAAAAAA
// #define fix(num, dig) cout << fixed << setprecision(dig) << num
// //fill(all(vec), 1);to fill vector with a number
// //if (S.count(key)) returns 1 if set or map contain key else return 0
// ll nCr(ll n, ll r)
// {
//     r = min(r, n - r);
//     if (r < 0)
//         return 0;
//     if (r == 0)
//         return 1;
//     ll ans = 1;
//     for (ll i = 1; i <= r; i++)
//     {
//         ans = ans * (n - i + 1) / i;
//     }
//     return ans;
// }
// ll logn(int val, int base) { return (val > base - 1) ? 1 + logn(val / base, base) : 0; }
// //ll logn(int val, int base) { return (base > val - 1) ? 1 + logn(base / val, val) : 0; }
// ll power(ll a, ll b)
// {
//     if (b == 1)
//         return a;
//     if (b == 0)
//         return 1;
//     ll m1 = power(a, b / 2);
//     if (b % 2)
//         return m1 * m1 * a;
//     return m1 * m1;
// }
// bool isprime(ll a)
// {
//     if (a <= 1)
//         return false;
//     if (a == 2 || a == 3)
//         return true;
//     if (a % 2 == 0 || a % 3 == 0)
//         return false;
//     for (ll i = 5; i * i <= a; i = i + 6)
//     {
//         if (a % i == 0 || a % (i + 2) == 0)
//             return false;
//     }
//     return true;
// }
// /*********************/ /*********************/ /*********************/ /*********************/ //
// //vl adj[(int)2e6 + 9];
// map<pair<ll, ll>, vector<pair<ll, ll>>> adj;
// //vector<bool> vis((int)2e6 + 9,false);
// map<pair<ll,ll>,bool>vis;
// bool check(int i, int j, int n, int m)
// {
//     if (i >= 0 && i < n && j >= 0 && j < m)
//     {
//         return true;
//     }
//     return false;
// }

// void solve()
// {
//     ll n, m;
//     cin >> n >> m;
//     char a[1000][1000];
//     rep(i, 0, n)
//             rep(j, 0, m)
//                 cin >>
//         a[i][j];
//     bool f=0;
//     pair<ll,ll>s={-1,-1};
//     rep(i, 0, n)
//         rep(j, 0, m)
//     {
//         pair<ll, ll> p = {i, j};

//         if (a[i][j] == '.')
//         {
//             if(!f)
//             {
//                 s={i,j};
//                 f=1;
//             }
//             if (check(i, j + 1, n, m))
//             {
//                 if (a[i][j + 1] == '.')
//                 {
//                     pair<ll, ll> pn = {i, j + 1};
//                     adj[p].pb(pn);
//                     adj[pn].pb(p);
//                 }
//             }
//             if (check(i, j - 1, n, m))
//             {
//                 if (a[i][j - 1] == '.')
//                 {
//                     pair<ll, ll> pn = {i, j - 1};
//                     adj[p].pb(pn);
//                     adj[pn].pb(p);
//                 }
//             }
//             if (check(i - 1, j, n, m))
//             {
//                 if (a[i - 1][j] == '.')
//                 {
//                     pair<ll, ll> pn = {i - 1, j};
//                     adj[p].pb(pn);
//                     adj[pn].pb(p);
//                 }
//             }
//             if (check(i + 1, j, n, m))
//             {
//                 if (a[i + 1][j] == '.')
//                 {
//                     pair<ll, ll> pn = {i + 1, j};
//                     adj[p].pb(pn);
//                     adj[pn].pb(p);
//                 }
//             }
//         }
//     }
//             char g='B';
//     rep(i,0,n)
//     {
//         rep(j,0,m)
//         {
//             if(!vis[{i,j}])
//             {
//             if(a[i][j]=='.')
//             {
//                 a[i][j]=g;
//                 if(g=='B')
//                     g='W';
//                 else
//                     g='B';
//                 //cout<<i<<","<<j<<"->"<<endl;
//             for(auto k:adj[{i,j}])
//             {
//                 if(!vis[k])
//                 a[k.first][k.first]=g;
//                 //cout<<k.first<<","<<k.second<<" ";
//             }
//             }
//             //cout<<endl;
//         }
//         }
//     }
//     rep(i,0,n)
//     {
//         rep(j,0,m)
//             cout<<a[i][j];
//         cout<<endl;
//     }
// //     if(s.first==-1)
// //     {
// //         rep(i,0,n)
// //         {
// //             rep(j,0,m)
// //             {
// //                 cout<<a[i][j];
// //             }
// //             cout<<endl;
// //         }
// //         return;
// //     }
// //     rep(i,0,n)
// //     {
// //         rep(j,0,m)
// //         {

// //         }
// //     }
// //     queue<pair<ll,ll>>q;
// //     q.push(s);
// //     char o='B';
// //     while(!q.empty())
// //     {
// //         s=q.front();
// //         q.pop();

// //         // if(a[s.first][s.second]=='B')
// //         //         {
// //         //             a[i.first][i.second]=='W';
// //         //         }
// //         //         else if(a[s.first][s.second]=='W')
// //         //         {
// //         //              a[i.first][i.second]=='B';
// //         //         }
// //         //         if(a[s.first][s.second]=='.')
// //         //         {
// //         //             a[s.first][s.second]='B';
// //         //         }
// //         for(auto i:adj[s])
// //         {

// //             if(!vis[i])
// //             {
// //                 vis[i]=true;
// //                 q.push(i);
// //             }

// //         }

// //     }

// //  rep(i,0,n)
// //         {
// //             rep(j,0,m)
// //             {
// //                 cout<<a[i][j];
// //             }
// //             cout<<endl;
// //         }
// //         return;
// }

// int main()
// {
//     Fast
//         ll t;

//     // #ifndef ONLINE_JUDGE
//     //     freopen("input.txt", "r", stdin);
//     //     freopen("output.txt", "w", stdout);
//     // #endif

//     t = 1;
//     // cin >> t;
//     for (int i = 1; i <= t; i++)
//     {
//         //cout << "Case #" << i << ": ";
//         solve();
//     }

//     return 0;
// }
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
#define rep(i, s, n) for (int i = s; i < n; i++)
#define For(i, s, l) for (int i = l; i >= s; i--)
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
    ll n, m;
    cin >> n >> m;

   vector<string>a;
    char b[n][m];
    char o = 'B';
    int f = 1;
    rep(i, 0, n)
        rep(j, 0, m)
    {
        string s;
        cin>>s;
        
        a.pb(s);
        if (f)
        {
            b[i][j] = 'B';
        }
        else
        {
            b[i][j] = 'W';
        }
        f ^= 1;
        if(m%2==0&&j==m-1)
            f^=1;
    }
    rep(i,0,n)
        rep(j,0,m)
        {
            if(a[i][j]=='.')
            {
                a[i][j]=b[i][j];
            }
        }
    // char g = 'B';
    // rep(i, 0, n)
    // {
    //     rep(j, 0, m)
    //     {
    //         if (i == 0 && a[i][j] == '.')
    //         {
    //             a[i][j] = g;
    //             if (g == 'B')
    //                 g = 'W';
    //             else
    //                 g = 'B';
    //             continue;
    //         }
    //         else
    //         {
    //             if (a[i - 1][j] == 'B' || a[i - 1][j] == 'W')
    //             {

    //                 if (a[i - 1][j] == 'B' && a[i][j] == '.')
    //                 {
    //                     a[i][j] = 'W';
    //                     g = 'W';
    //                 }
    //                 else if (a[i - 1][j] == 'W' && a[i][j] == '.')
    //                 {
    //                     a[i][j] = 'B';
    //                     g = 'B';
    //                 }
    //                 else if (a[i][j] == '.')
    //                 {
    //                     //deb2(i,j);
    //                     //  deb(g);
    //                     a[i][j] = g;
    //                 }

    //                 if (g == 'B')
    //                     g = 'W';
    //                 else
    //                     g = 'B';
    //             }
    //             else if (a[i][j] == '.')
    //             {
    //                 if (a[i][j] == '.')
    //                 {
    //                     //deb2(i,j);
    //                     //  deb(g);
    //                     a[i][j] = g;
    //                 }

    //                 if (g == 'B')
    //                     g = 'W';
    //                 else
    //                     g = 'B';
    //             }
    //         }
    //     }
    // }
    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            if (a[i][j] == '.')
            {
                deb2(i, j);
            }
            cout
                << a[i][j];
        }
        cout << endl;
    }
}

int main()
{
    Fast
        ll t;

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++)
    {
        //cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}