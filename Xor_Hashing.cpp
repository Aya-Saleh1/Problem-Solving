#include <bits/stdc++.h>
 
using namespace std;
using ull = unsigned long long;
 
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL);
 
    int n, Q;
    cin >> n >> Q;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    vector<ull> rnd(n + 1);
    mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
    for (int v = 1; v <= n; v++) {
        rnd[v] = rng();
    }
    vector<ull> px(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        px[i] = px[i - 1] ^ rnd[A[i]];
    }
    vector<ull> perm_hash(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        perm_hash[i] = perm_hash[i - 1] ^ rnd[i];
    }
    while (Q--) {
        int l, r;
        cin >> l >> r;
        int len = r - l + 1;
        ull range_hash = px[r] ^ px[l - 1];
        if (range_hash == perm_hash[len]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
