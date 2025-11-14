// better time complexity then original templet 
// https://codeforces.com/blog/entry/61203 -> blog about it 
// if you have strict time -> use this 
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define endl '\n'
#define FAST ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int MOD = 1e9 + 7;
const int INF = 1e18 + 7;
const int MOD2 = 1e9 + 9;

void fileIO() {
#ifndef ONLINE_JUDGE
    freopen("saleh.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

const int N = 2e5 + 5;
vector<int> blk;
const int M = 1e6 + 5;
int sq = sqrtl(N) + 1;
vector<int> v;
vector<int> ans;
int res;
const int infinity = (int) 1e9 + 42;
const int64_t llInfinity = (int64_t) 1e18 + 256;
const int module = (int) 1e9 + 7;
const long double eps = 1e-8;
using namespace chrono;
mt19937_64 randGen(system_clock().now().time_since_epoch().count());

inline void raiseError(string errorCode) {
    cerr << "Error : " << errorCode << endl;
    exit(42);
}

inline int64_t gilbertOrder(int x, int y, int pow, int rotate) {
    if (pow == 0) return 0;
    int hpow = 1 << (pow - 1);
    int seg = (x < hpow) ? ((y < hpow) ? 0 : 3) : ((y < hpow) ? 1 : 2);
    seg = (seg + rotate) & 3;
    static const int rotateDelta[4] = {3, 0, 0, 1};
    int nx = x & (hpow - 1), ny = y & (hpow - 1);
    int nrot = (rotate + rotateDelta[seg]) & 3;
    int64_t sub = 1LL << (2 * pow - 2);
    int64_t res = seg * sub;
    int64_t add = gilbertOrder(nx, ny, pow - 1, nrot);
    return res + ((seg == 1 || seg == 2) ? add : (sub - add - 1));
}

struct qu {
    int l, r, idx;
    int64_t ord;

    inline void calcOrder() {
        ord = gilbertOrder(l, r, 21, 0);
    }
};

vector<qu> que;
vector<int> vis;

inline bool operator<(const qu &a, const qu &b) {
    return a.ord < b.ord;
}


void add(int idx) {
}

void remove_(int idx) {
}

void mo_algo() {
    sort(que.begin(), que.end());
    int L = 0, R = -1;

    for (auto &q: que) {
        while (L > q.l) add(--L);
        while (R < q.r) add(++R);
        while (L < q.l) remove_(L++);
        while (R > q.r) remove_(R--);

        ans[q.idx] = res;
    }
}

void solve() {
    int n, q;
    cin >> n >> q;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    que.resize(q);
    ans.resize(q);
    vis = vector<int>(M);
    res = 0;
    for (int i = 0; i < q; i++) {
        cin >> que[i].l >> que[i].r;
        que[i].l--, que[i].r--;
        que[i].idx = i;
    }
    for (int i = 0; i < q; i++)
        que[i].calcOrder();
    mo_algo();
    for (int i = 0; i < q; i++)
        cout << ans[i] << '\n';
}


int32_t main() {
    FAST
    fileIO();
    int t = 1;
    // cout << fixed << setprecision(8);
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

