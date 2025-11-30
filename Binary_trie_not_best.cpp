// not best optimization , delete and new can cause tle with much nodes up to 1e6 

struct trie {
    struct node {
        node *ch[2];
        int freq[2];
        node() {
            ch[0] = ch[1] = 0;
            freq[0] = freq[1] = 0;
        }
    };

    node *root;

    trie() {
        root = new node();
    }

    void insert(int n) {
        node *curr = root;
        int ret = 0;
        for (int i = 29; i >= 0; i--) {
            int idx = (n >> i) & 1;
            if (curr->ch[idx] == 0) {
                curr->ch[idx] = new node();
            }
            curr->freq[idx]++;
            curr = curr->ch[idx];
        }

    }

   void del(int n , int i , node * curr) {
        if (i == -1 )return ;
        int idx = (n >> i ) & 1 ;
        del(n , i - 1 , curr->ch[idx]);
        curr->freq[idx]--;
        // when returning back from rec
       if (curr->freq[idx] == 0 ) {
           delete curr->ch[idx]; // free the memory
           curr->ch[idx] = 0; // assign it again
       }
    }
    int mx_xor(int n ){
       node *curr = root ;
        int ret = 0 ;
        for (int i = 29 ;i >= 0;i--) {
            int idx = (n >> i) & 1;
            if (curr->ch[idx ^ 1 ] == 0) {
                curr = curr->ch[idx];
            }else {
                curr = curr->ch[idx ^ 1];
                ret|=(1 << i );
            }
        }
        return ret;
    }
};
