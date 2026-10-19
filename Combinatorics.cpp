// mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
// mt19937 rnd2(chrono::steady_clock::now().time_since_epoch().count());

#define int long long
#define ll long long
#define int64 long long
#define endl "\n"
#define pb push_back
#define all(x) x.begin(), x.end()
#define print(x) for(auto i : x) cout << i << ' ';
ll MOD = 1e9 + 7;
ll INF = 1e18;
ll mod = 998244353;
int mx = 1e6;
vector<int> fact(mx + 1), inv(mx + 1);

namespace combinatorics
{
    ll MOD;
    vector<ll> fac,inv,finv;
    ll nCr(ll x,ll y)
    {
        if(x<0||y>x||y<0)return(0);
        return(fac[x]*finv[y]%MOD*finv[x-y]%MOD);
    }
    ll nPr(ll x,ll y)
    {
        if(x<0||y>x||y<0)return 0;
        return fac[x]*finv[x-y]%MOD;
    }
    ll power(ll b,ll n)
    {
        b%=MOD;
        ll s=1;
        while(n)
        {
            if(n%2==1)s=s*b%MOD;
            b=b*b%MOD;
            n/=2;
        }
        return s;
    }
    void init(int n,ll mod)
    {
        fac.resize(n+1);
        inv.resize(n+1);
        finv.resize(n+1);
        MOD=mod;
        fac[0]=inv[0]=inv[1]=finv[0]=finv[1]=1;
        for(ll i=1;i<=n;++i)fac[i]=fac[i-1]*i%MOD;
        for(ll i=2;i<=n;++i)inv[i]=MOD-MOD/i*inv[MOD%i]%MOD;
        for(ll i=2;i<=n;++i)finv[i]=finv[i-1]*inv[i]%MOD;
    }
    ll mul(ll a,ll b)
    {
        return ((a%MOD)*(b%MOD))%MOD;
    }
    ll add(ll a,ll b)
    {
        return ((a%MOD)+(b%MOD))%MOD;
    }
    ll sub(ll a,ll b)
    {
        return (((a-b)%MOD)+MOD)%MOD;
    }
    ll divide(ll a,ll b)
    {
       return mul(a,power(b,MOD-2));
    }
    ll Inv(int x)
    {
        return power(x,MOD-2);
    }
    ll catalan(int n)
    {
        return (nCr(2*n,n)*Inv(n+1))%MOD;
    }
    ll StarsAndPars(ll n,ll k)
    {
        return nCr(n+k-1,k-1);
    }
};


int binpow(int a, int b, int m) {
    int res = 1;
    while(b) {
        if(b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
 
void precomp() {
    fact[0] = 1;
    for(int i = 1; i <= mx; i++) fact[i] = fact[i - 1] * i % MOD;
    inv[mx] = binpow(fact[mx], MOD - 2, MOD);
    for(int i = mx - 1; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % MOD;
}

long long C[35][35];
 
void precompute2() {
    for (int i = 0; i <= 34; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) C[i][j] = 1;
            else C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
}
