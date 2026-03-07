string multiply(string a, string b) {
    int n = a.size();
    int m = b.size();

    vector<int> res(n + m, 0);

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int mul = (a[i] - '0') * (b[j] - '0');
            int sum = mul + res[i + j + 1];

            res[i + j + 1] = sum % 10;
            res[i + j] += sum / 10;
        }
    }

    string ans = "";
    for (int x : res) {
        if (!(ans.empty() && x == 0))
            ans += char(x + '0');
    }

    return ans.empty() ? "0" : ans;
}
bool smaller(string a, string b){
    if(a.size() != b.size()) return a.size() < b.size();
    return a < b;
}

string subtractStrings(string a, string b){
    string res="";
    int carry=0;

    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());

    for(int i=0;i<a.size();i++){
        int x=a[i]-'0';
        int y=(i<b.size()?b[i]-'0':0);

        int cur=x-y-carry;
        if(cur<0){
            cur+=10;
            carry=1;
        }else carry=0;

        res+=char(cur+'0');
    }

    while(res.size()>1 && res.back()=='0') res.pop_back();
    reverse(res.begin(),res.end());
    return res;
}

string division(string a,string b){
    string cur="";
    string ans="";

    for(char c:a){
        cur+=c;

        int x=0;
        while(!smaller(cur,b)){
            cur=subtractStrings(cur,b);
            x++;
        }

        ans+=char(x+'0');
    }

    int pos=0;
    while(pos<ans.size()-1 && ans[pos]=='0') pos++;

    return ans.substr(pos);
}
