void radix_sort(vector<int> &p , vector<int> &c ) {
    int n = p.size();
    vector<int> cnt(n) , pos(n);
    for (auto i : c) {
        cnt[i]++;
    }
    pos[0] = 0 ;
    vector<int> new_p(n);
    for (int i = 1 ; i < n ; i++) {
        pos[i] = pos[i - 1 ] + cnt[i - 1 ];
    }
    for (auto x : p ) {
        int i = c[x];
        new_p[pos[i]] = x ;
        pos[i]++;
    }
    p = new_p;

}
void solve() {
    // Implementing Suffix Array with O(N log N ) -> Because of Radix sort(o(n)) But this code has more optimization
  string s ; cin >> s ;
      int len = s.size();
    // s += s ;
    s += '$';
    int n = s.size();
    vector<pair < char ,int >> a(n);
    vector<int> p(n) , c(n);
    // for k =  0 ;
    for (int i = 0 ; i < n ; i++)a[i] = {s[i] , i };
    sort(a.begin() , a.end());
    for (int i = 0 ; i < n ; i++)p[i] = a[i].second;
    c[p[0]] = 0 ;
    for (int i= 1 ; i < n ; i++) {
        if (a[i].first == a[i - 1 ].first) {
            c[p[i]] = c[p[i - 1 ]];
        }else c[p[i]] = c[p[ i - 1 ]] + 1 ;
    }
   for (int k = 0; (1 << k) < n; k++) {
      for (int i= 0 ; i < n ; i++) {
          p[i] =( p[i] - (1 << k ) + n) % n ;
       }
       radix_sort(p , c );
       vector<int> c_new(n);
        c_new[p[0]] = 0 ;
        for (int i= 1 ; i < n ; i++) {
            pair <int, int > curr = {c[p[i]] , c[(p[i] + (1 << k ) + n) % n ]} ;
            pair <int, int > prev = {c[p[i - 1 ]] , c[(p[i - 1 ] + (1 << k ) + n) % n ]} ;

            if (prev == curr) {
                c_new[p[i]] = c_new[p[i - 1 ]];
            }else c_new[p[i]] = c_new[p[ i - 1 ]] + 1 ;
        }
       c = c_new ;
    }

    for (int i : p)cout << i << ' ';
// Creating LCP array 
   vector<int> lcp(n); // implementing LCP array O(n)
    int k = 0 ;
    for (int i = 0 ; i < n - 1  ; i++) { // iterate all suffix from 0 to n - 1
        int rank = c[i]; //  rank of string [i ... n ] in suffix array
        if (rank == 0 ) {
            k = 0 ;
            continue ;
        }
        int l =   p[rank - 1 ] ;  //
        while (s[i + k ] == s[l + k ])k++;
        lcp[rank] = k ;
        k = max(k - 1 , 0ll ); // now we need to compare the next suffix with length k - 1
    }
}
