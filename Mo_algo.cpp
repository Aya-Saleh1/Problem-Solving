#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define endl '\n'
#define FAST ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int MOD = 1e9 + 7;
const int INF = 1e18 + 7;
const int MOD2 = 1e9 + 9;
const int N = 2e5 + 5;
vector<int> blk;
vector<int> f;
const int M = 1e6 + 5;
int sq = sqrtl(N) + 1;
vector<int > v;
vector<int> ans;
int res ;

struct qu {
    int l, r, q_idx, blk_idx;

    qu() {
    }
    qu(int l, int r, int q_idx) {
        this->l = l;
        this->r = r;
        this->q_idx = q_idx;
        blk_idx = l / sq;
    }

    inline pair<int, int> toPair() const {
        return make_pair(l / sq, ((l / sq) & 1) ? -r : +r);
    }

};
inline bool operator<(const qu &a, const qu &b) {
    return a.toPair() < b.toPair();
}
vector<qu> que;
vector<int> vis;
void add(int idx) {}
void remove(int idx) {}

void mo_algo() {
    sort(que.begin(), que.end() );
    int l = 0, r = -1;
    for (int i = 0; i < que.size(); i++) {
        while (l < que[i].l)remove(l++);
        while (l > que[i].l)add(--l);
        while (r < que[i].r)add(++r);
        while (r > que[i].r)remove(r--);
        ans[que[i].q_idx] = res;
    }
}

void solve() {
    int n, q;
    cin >> n >> q;
    v = vector<int> (n);
    que = vector<qu>(q);
    ans = vector<int>(q);
    vis = vector<int> (M);
    res =0 ;
    for (int i = 0; i < n; i++)cin >> v[i];
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        que[i] = {--l, --r, i};
    }
    mo_algo();
    for (int i = 0; i < q; i++) {
        cout << ans[i] << '\n';
    }
}


int32_t main() {
    FAST
    // fileIO();
    int t = 1;
    // cout << fixed << setprecision(8);
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
