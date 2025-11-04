#include <bits/stdc++.h>
 
using namespace std;
#define ll long long
// change the N if needed 
const int N = 3e5 + 5;
#define fr first
#define sc second
int B1 = 31, B2 = 53, MOD1 = 1e9 + 7, MOD2 = 1e9 + 9;
int pw1[N], pw2[N];
 
struct pair_hash {
    size_t operator()(const pair<int, int> &p) const {
        return 1LL * p.first * 1000000007 + p.second;
    }
};
 
struct Hash {
private:
    vector<pair<int, int>> prefix, suffix;
    int n;
 
    void hash_prefix(const string &str) {
        int h1 = 0, h2 = 0;
        prefix.clear();
        prefix.reserve(str.size());
        for (char i: str) {
            h1 = (1LL * h1 * B1) % MOD1;
            h1 = (h1 + i) % MOD1;
            h2 = (1LL * h2 * B2) % MOD2;
            h2 = (h2 + i) % MOD2;
            prefix.emplace_back(h1, h2);
        }
    }
 
    void hash_suffix(const string &str) {
        int h1 = 0, h2 = 0;
        suffix.assign(n, {});
        for (int i = n - 1; i >= 0; i--) {
            h1 = (1LL * h1 * B1) % MOD1;
            h1 = (h1 + str[i]) % MOD1;
            h2 = (1LL * h2 * B2) % MOD2;
            h2 = (h2 + str[i]) % MOD2;
            suffix[i] = {h1, h2};
        }
    }
 
public:
    Hash() {}
 
    Hash(const string &s) { build(s); }
 
    void build(const string &s) {
        assert(B1);
        n = s.size();
        hash_prefix(s);
        hash_suffix(s);
    }
 
    pair<int, int> getSuffix(int l, int r) {
        auto ret = suffix[l];
        int len = r - l + 1;
        r++;
        if (r < n) {
            ret.fr -= 1LL * suffix[r].fr * pw1[len] % MOD1;
            if (ret.fr < 0)ret.fr += MOD1;
 
            ret.sc -= 1LL * suffix[r].sc * pw2[len] % MOD2;
            if (ret.sc < 0)ret.sc += MOD2;
 
        }
        return ret;
    }
 
    pair<int, int> getPrefix(int l, int r) {
        auto ret = prefix[r];
        int sz = r - l + 1;
        l--;
        if (l >= 0) {
            ret.fr -= 1LL * prefix[l].fr * pw1[sz] % MOD1;
            if (ret.fr < 0)ret.fr += MOD1;
            ret.sc -= 1LL * prefix[l].sc * pw2[sz] % MOD2;
            if (ret.sc < 0)ret.sc += MOD2;
        }
        return ret;
    }
};
 
void build() {
    pw1[0] = pw2[0] = 1;
    for (int i = 1; i < N; ++i) {
        pw1[i] = 1LL * pw1[i - 1] * B1 % MOD1;
        pw2[i] = 1LL * pw2[i - 1] * B2 % MOD2;
    }
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    build();
    string s;
    Hash h(s);
 
 
}
