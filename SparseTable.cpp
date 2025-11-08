#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX_N=200005;
const int LOG=21;
int a[MAX_N];
int m[MAX_N][LOG];
int bin_log[MAX_N];
ll query(int l,int r){
    int len=r-l+1;
    int k=bin_log[len];
    return min(m[l][k],m[r-(1<<k)+1][k]);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        bin_log[1] = 0;
        for (int i = 2; i <= n; i++) {
            bin_log[i] = bin_log[i / 2] + 1;
        }
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            m[i][0] = a[i];
        }
        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i + (1 << k) - 1 < n; i++) {
                m[i][k] = min(m[i][k - 1], m[i + (1 << (k - 1))][k - 1]);
            }
        }
        while (q--) {
            int l, r;
            cin >> l >> r;
            if (l > r)swap(l, r);
            l--;
            r--;
            cout << query(l, r) << '\n';
        }
    }
}
