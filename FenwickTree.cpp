struct fenwick {
    vector<int> arr;
    fenwick(int n) {
        arr = vector<int>(n);
    }

    void add(int idx, int val) {
        while (idx < arr.size()) {
            arr[idx] += val;
            idx = (idx | (idx + 1));
        }
    }

    // diff array idea
    void update(int l, int r, int val) {
        add(l, val);
        if (r + 1 < arr.size()) {
            add(r + 1, -val);
        }
    }

    int query(int idx) {
        int sum = 0;
        while (idx >= 0) {
            sum += arr[idx];
            idx = (idx & (idx + 1)) - 1;
        }
        return sum;
    }
};
