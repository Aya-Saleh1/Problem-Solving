// query in O(1) 
//build in O(n logn)
template<class T>
struct SparseTable {
    static const int mxLog = 21;
    vector<vector<T>> table;
    vector<int> lg;
    int n;

    SparseTable(int sz = 0) {
        if (sz) init(sz);
    }

    void init(int sz) {
        n = sz;
        table.assign(n, vector<T>(mxLog));
        lg.resize(n + 1);
        lg[1] = 0;
        for (int i = 2; i <= n; ++i)
            lg[i] = lg[i / 2] + 1;
    }

    void build(vector<T> &v) {
        n = v.size();
        init(n);
        for (int i = 0; i < n; ++i)
            table[i][0] = v[i];
        for (int j = 1; (1 << j) <= n; ++j) {
            for (int i = 0; i + (1 << j) <= n; ++i) {
                table[i][j] = min(table[i][j - 1],
                                  table[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    T query(int l, int r) {
        if (l > r) return INF;
        int j = lg[r - l + 1];
        return min(table[l][j], table[r - (1 << j) + 1][j]);
    }
};
