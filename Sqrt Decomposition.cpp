// BASE ZERO
#include <bits/stdc++.h>
 
using namespace std;
#define ll long long
const int SQ = 708;
int n, q, arr[500005];
vector<vector<int>> x(710);
 
void process() // static
{
    for (int i = 0; i < n; ++i) {
        x[i / SQ].push_back(arr[i]);
    }
    for (int i = 0; i < n; i += SQ) {
        sort(x[i / SQ].begin(), x[i / SQ].end());
    }
}
 
void update(int idx, int v) //dynamic
{
    int block = idx / SQ;
    auto it = lower_bound(x[block].begin(), x[block].end(), arr[idx]);
    *it = v;
    arr[idx] = v;
    sort(x[block].begin(), x[block].end());
}
 
int query(int l, int r, int v) {
    int ans = 0;
    while (l <= r) {
        if (l % SQ == 0 && l + SQ <= r) //block
        {
            ans += x[l / SQ].end() - lower_bound(x[l / SQ].begin(), x[l / SQ].end(), v);  //update
            l += SQ;
        } else  // some element
        {
            ans += (arr[l] >= v);   //update
            l++;
        }
    }
    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        process();
        cin >> q;
        int ch;
        for (int i = 0; i < q; i++) {
            cin >> ch;
            if (ch) {
                int idx, v;
                cin >> idx >> v;
                update(idx - 1, v);
            } else {
                int l, r, v;
                cin >> l >> r >> v;
                cout << query(l - 1, r - 1, v) << '\n';
            }
        }
    }
}
// for queries and uodate on dynamic range queries 
/////
const int N = 5e5 + 1 ;
vector<vector<int>> x;
vector<int> blk;
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    int sz = sqrt(n) + 1 ;
    x = vector<vector<int>>(sz + 1 );
    blk = vector<int> (sz + 1 );
    for (int i = 0; i < n; i++)cin >> v[i];
 auto build = [&]() {
     for (int i = 0 ; i < n ; i++){
         x[i / sz].push_back(v[i]);
         blk[i / sz ] += v[i];
     }
 };
     auto query = [&](int l , int r )-> int {
         int ans = 0 ;
         while (l <= r ) {
             if (l % sz == 0 && l + sz - 1 <= r ) {
                 ans += blk[l / sz];
                 l+= sz;
             }else {
             ans += v[l];
                 l++;
             }
         }
         return ans ;
     };
    auto update  = [&](int val , int pos) {
        blk[pos / sz ] -= v[pos];
        blk[pos / sz] += val ;
        v[pos] = val ;
        x[pos / sz][pos % sz] = val ;
    };
    build();
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int pos, val;
            cin >> pos >> val;
          update(val , --pos);
        } else {
            int l, r;
            cin >> l >> r;
            --l, --r;
            cout << query(l , r ) << '\n';
        }
    }
}
//////
