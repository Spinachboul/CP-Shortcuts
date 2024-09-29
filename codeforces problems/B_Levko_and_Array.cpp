/*-----AUTHOR--------
-------FREEBIE-------
https://codeforces.com/profile/freebie
*/

# include <bits/stdc++.h>
using namespace std;

# define ll long long
# define pb push_back
# define mp make_pair
# define ff first
# define ss second
# define mod 1000000007
// # define int long long
# define INF 1e18
# define vi vector<int>
# define vll vector<ll>
# define pii pair<int, int>
# define pll pair<ll, ll>
# define vvi vector<vi>
# define vpii vector<pii>
# define vpll vector<pll>
# define all(x) x.begin(), x.end()
# define endl "\n"
# define forn(i, n) for(int i = 0; i < n; i++)
# define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

bool isPrime(int n){
    if(n == 1){
        return false;
    }
    for(int i = 2; i*i <= n; i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    return gcd(b, a%b);
}

int lcm(int a, int b){
    return (a*b)/gcd(a, b);
}

int power(int x, int y){
    int res = 1;
    while(y > 0){
        if(y%2 == 1){
            res = res*x;
        }
        x = x*x;
        y = y/2;
    }
    return res;
}

int modInverse(int a, int m){
    int m0 = m;
    int y = 0, x = 1;
    if(m == 1){
        return 0;
    }
    while(a > 1){
        int q = a/m;
        int t = m;
        m = a%m;
        a = t;
        t = y;
        y = x - q*y;
        x = t;
    }
    if(x < 0){
        x = x + m0;
    }
    return x;
}

int modExpo(int x, int y, int p){
    int res = 1;
    x = x%p;
    if(x == 0){
        return 0;
    }
    while(y > 0){
        if(y%2 == 1){
            res = (res*x)%p;
        }
        y = y/2;
        x = (x*x)%p;
    }
    return res;
}



void sieve(int n){
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
    for(int p = 2; p*p <= n; p++){
        if(prime[p] == true){
            for(int i = p*p; i <= n; i += p){
                prime[i] = false;
            }
        }
    }
}   

const int N = 2000+200;
ll dp[N];
vector<ll> v(N);
ll n, k;
inline bool check(int x){
    fill(dp, dp+N, 0);
    ll ans = 0;
    for(ll i=0 ; i<n ; i++){
        dp[i] = 1;

        for(ll j=0 ; j<i; j++){
            if(abs(v[i] - v[j]) <= x * (i-j)){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans  =  max(ans, dp[i]);
    }

    return (n - ans <= k);

}

void solve(){
    cin  >> n >> k;
    // vi v(n);
    for(int i=0 ; i<n ; i++){
        cin >> v[i];
    }

    ll low = -1;
    ll high = 1e9;

    while (high - low > 1){
        ll mid = (low + high) / 2;
        if(check(mid)) high = mid;
        else low = mid;
    }

    cout << high << endl;
}

int main(){
    fast;
    int t;
    t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}