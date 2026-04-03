#include <bits/stdc++.h>
using namespace std;

// Removed #define int long long to strictly control memory.
// We will use standard 32-bit ints for the grid and long long only where needed.
#define FAST ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int MOD = 1e9 + 7;

void fileIO() {
#ifndef ONLINE_JUDGE
    freopen("saleh.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

const int MAX_CELLS = 1000005;
const int MAX_LOG = 11; // Since max min(N, M) is 1000. log2(1000) is < 10.

// Statically allocated global arrays. Zero allocation overhead during runtime!
int32_t st[MAX_LOG][MAX_CELLS];
int32_t lg2_arr[MAX_CELLS];

void solve() {
    int n, m;
    cin >> n >> m;

    // Read directly into the base level of our flattened Sparse Table
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> st[0][i * m + j];
        }
    }

    int max_k = min(n, m);
    int max_log = (max_k <= 1) ? 1 : lg2_arr[max_k] + 1;

    // Build the Sparse Table combining squares
    for (int p = 1; p < max_log; p++) {
        int len = 1 << (p - 1);
        for (int i = 0; i + (1 << p) <= n; i++) {
            for (int j = 0; j + (1 << p) <= m; j++) {

                // 1D Flattened indices
                int id1 = i * m + j;
                int id2 = (i + len) * m + j;
                int id3 = i * m + (j + len);
                int id4 = (i + len) * m + (j + len);

                st[p][id1] = std::gcd(
                    std::gcd(st[p - 1][id1], st[p - 1][id2]),
                    std::gcd(st[p - 1][id3], st[p - 1][id4])
                );
            }
        }
    }

    int q;
    cin >> q;

    long long ans = 1; // Use long long to prevent overflow before modulo
    while (q--) {
        int x, y, k;
        cin >> x >> y >> k;
        --x; --y;

        // Prevent out of bounds queries
        if (k == 0 || x + k > n || y + k > m) continue;

        int p = lg2_arr[k];
        int len = 1 << p;

        // 1D Flattened indices for query
        int id1 = x * m + y;
        int id2 = (x + k - len) * m + y;
        int id3 = x * m + (y + k - len);
        int id4 = (x + k - len) * m + (y + k - len);

        long long val = std::gcd(
            std::gcd(st[p][id1], st[p][id2]),
            std::gcd(st[p][id3], st[p][id4])
        );

        ans = (ans * val) % MOD;
    }
    cout << ans << '\n';
}

void sieve() {
    lg2_arr[0] = lg2_arr[1] = 0;
    for (int i = 2; i < MAX_CELLS; i++) {
        lg2_arr[i] = lg2_arr[i >> 1] + 1;
    }
}

int main() {
    FAST
    fileIO();
    sieve();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
