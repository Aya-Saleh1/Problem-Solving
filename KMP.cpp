  int strStr(string word, string pattern) {
       vector<int> lps(pattern.size()); 
       int i = 1 , j = 0 ;  
       // building lps 
       lps[0] = 0 ; 
       while(i < pattern.size()){
          if(pattern[i] == pattern[j]){
            lps[i] = j + 1 ; 
            i++, j++; 
          }else {
            if(j == 0 ){
                i++; 
            }else {
                j = lps[j - 1 ]; 
            }
          }
       }
       // search 
       i = 0 , j = 0 ; 
       while(i < word.size() ){
        if(pattern[j] == word[i]){
            i++ , j++ ; 
        }
        else {
            if(j == 0 ){
                i++ ;
            }else {
               j = lps[j - 1 ]; 
            }
        }
        if(j == pattern.size()){
            return i - pattern.size() ; 
        }
       } 
       return -1 ; 
    }
