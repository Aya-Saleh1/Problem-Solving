// Hashing Using SegTree (Ex: cses problem "Palindrome Queries" ) 
struct segtree {
    vector<int> t;
    string s;
    int n;
 
    segtree(const string& s_) {
        s = s_;
        n = s.size();
        t.assign(4 * n, 0);
    }
    void build(int idx, int start, int end) {
        if (start == end) {
            t[idx] = (s[start] - 'a' + 1) % MOD2;
        } else {
            int mid = (start + end) / 2;
            build(2 * idx, start, mid);
            build(2 * idx + 1, mid + 1, end);
            int len = mid - start + 1;
          // here we're doing Hash = hash_left + (hash_right * power(len_left)
          // we can do the opposite for all the tree -> hash = right + (left * pow(len_right) -> hash = right + (left * pow(end - mid )) 
            t[idx] = (t[2 * idx ] + (t[2 * idx + 1 ] * p[mid - start + 1 ]) % MOD2) % MOD2;
        }
    }
    int query(int idx, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) {
            return t[idx] % MOD2;
        }
        int mid = (start + end) / 2;
        int q1 = query(2 * idx, start, mid, l, r);
        int q2 = query(2 * idx + 1, mid + 1, end, l, r);
        int len = max(0LL, min(r, mid) - max(l, start) + 1);
        return (q1 + q2 * p[len] % MOD2) % MOD2;
    }
    void update(int idx, int start, int end, int pos, char new_val) {
        if (start == end) {
            s[pos] = new_val;
            t[idx] = (new_val - 'a' + 1) % MOD2;
        } else {
            int mid = (start + end) / 2;
            if (pos <= mid)
                update(2 * idx, start, mid, pos, new_val);
            else
                update(2 * idx + 1, mid + 1, end, pos, new_val);
            int len = mid - start + 1;
            t[idx] = (t[2 * idx ] + (t[2 * idx + 1 ] * p[mid - start + 1 ]) % MOD2) % MOD2;
        }
    }
};
 
void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
 
    p.assign(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        p[i] = (p[i - 1] * P) % MOD2;
    }
 
    segtree t1(s);
    t1.build(1, 0, n - 1);
    string rev = s;
    reverse(rev.begin(), rev.end());
    segtree t2(rev);
    t2.build(1, 0, n - 1);
 
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int pos;
            char ch;
            cin >> pos >> ch;
            --pos;
            t1.update(1, 0, n - 1, pos, ch);
            t2.update(1, 0, n - 1, n - 1 - pos, ch);
        } else {
            int l, r;
            cin >> l >> r;
            --l; --r;
            int h1 = t1.query(1, 0, n - 1, l, r);
            int h2 = t2.query(1, 0, n - 1, n - 1 - r, n - 1 - l);
 
            if (h1 == h2) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
