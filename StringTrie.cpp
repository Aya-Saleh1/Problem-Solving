struct trie {
    struct node {
        node *ch[26];
        int prefix , end ;
        node() {
            prefix = end = 0 ;
            memset(ch, 0, sizeof(ch)) ;
        }
    };
    node *root;
    trie () {
        root = new node();
    }
    void insert(string s ) {
        node *curr = root ;
        int ret = 0 ; 
        for (auto c : s ) {
            int idx = c - 'a' ;
            if (curr->ch[idx] == 0 ) {
                curr->ch[idx] = new node();
            }
            curr = curr->ch[idx];
            curr->prefix++;
        }
        
        curr->end++;
    }
    int search(string s ) {
        node *curr = root;
        for (auto c : s ) {
            int idx = c - 'a' ;
            if (curr->ch[idx] == 0 ) {
                return 0;
            }
            curr = curr->ch[idx];

        }
        return curr->prefix;
    }
};
