 void solve() {
        auto  z_dunction = [&] (string s ) -> vector<int> {
            int l = 0 , r = 0 ;
            int n = s.length() ;
            vector<int> z(n);
            for (int i = 1 ; i < s.length() ; i++) {
                if (i <= r ) { // inside Z_box
                    int k = i - l ; // mirroring element
                    z[i] = min(z[k] , r - i + 1 );
                }
                // extending the box -> computing match
                // s[z[i]] => prefix char
                // s[i + z[i]] => substring char
                while (i + z[i] < n && s[z[i]] == s[i + z[i]] )z[i]++;

                // to not go out of bounds if box extende
                if (i + z[i] - 1 > r ) {
                    l = i ;
                    r = i + z[i] - 1 ;
                }

            }
            return z ;
        };
        string word , pattern ;
        cin >> word >> pattern ;
        string res = pattern + "$" + word ;
        vector<int> z_array = z_dunction(res) ;
        int cnt = count(z_array.begin(), z_array.end(), pattern.size()) ;
        cout << cnt << '\n';


    }
