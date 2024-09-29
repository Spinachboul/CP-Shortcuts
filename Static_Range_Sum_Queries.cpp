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
# define dbg(...)
# define mod 1000000007
# define INF 1e18
# define vi vector<int>
# define vll vector<ll>
# define vvll vector<vll>
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

vector<int> zFunction(const string& s){
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;

    for (int i = 1; i < n; ++i) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }

        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            ++z[i];
        }

        if (i + z[i] - 1 > r) {  // This condition is fixed
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}



class SegmentTree{
private:
    vi tree;
    int n;

    // build the tree recursively
    void build(vi &arr, int node, int start, int end){
        if(start ==  end){
            tree[node] = arr[start];
        }
        else{
            int mid = (start + end)/2;

            // recursively build the left and the right children
            build(arr, 2*node, start, mid);
            build(arr, 2*node+1, mid+1, end);
            // internal node will have the sum of the children
            tree[node] = tree[2*node] + tree[2*node+1];


        }
    }

    // range sum query recursively
    int rangeSum(int node, int start, int end, int L, int R){
        // base case
        if(R< start || L > end) return 0;

        if(L <= start && R >= end) return tree[node];

        // partial overlap
        int mid = start + (end - start)/2;
        int leftSum = rangeSum(2*node, start, mid, L, R);
        int rightSum = rangeSum(2*node+1, mid+1, end, L, R);
        return leftSum + rightSum;
    }

    // update the tree recursively
    void update(int node, int start, int end , int index, int value){
        if(start == end){
            tree[node] = value;
        }
        else{
            int mid = start + (end - start)/2;
            if(start <= index && index <= mid){
                // recur on the left child
                update(2*node, start, mid, index, value);
            }
            else{
                // recur on the right child
                update(2*node+1, mid+1, end, index, value);
            }
        }
        // internal node update
        tree[node] = tree[2*node] + tree[2*node+1];
    }
    public:
    SegmentTree(vi &arr){
        n = arr.size();
        tree.resize(4*n); // segment tree can have size upto 4*n
        build(arr, 1,0, n-1);
    }

    // public interface for range sum query
    int rangeSum(int L, int R){
        return rangeSum(1, 0, n-1, L, R);
    }

    // public interface for update
    void update(int index, int value){
        update(1, 0, n-1, index, value);
    }

    
};

class FenwickTree{
private:
    int n;
    vi tree;

public:
    FenwickTree(int sz){
        n = sz;
        tree.resize(n+1, 0);

    }

    // update the element at index by delta
    void update(int index , int delta){
        while( index <= n){
            tree[index] += delta;
            index += index & -index; // update the parent
        }

    }

    // compute prefix sum from 1 to index
    int prefixSum(int idx){
        int res = 0;
        while (idx > 0){
            res += tree[idx];
            idx -= idx & -idx; // move to the parent
        }
        return res;
    }

    // range sum from index L to R
    int rangeSum(int L, int R){
        return prefixSum(R) - prefixSum(L-1);
    }
};

void solve()
{
    ll n,q;
    cin >> n >> q;
    vll v(n);
    for(int i=0 ; i<n ; i++){
        cin >> v[i];
    }

    vll prefix(n+1, 0);
    for(int i=1 ; i<=n ; i++){
        prefix[i] = prefix[i-1] + v[i-1];
    }

    while(q--){
        int a, b;
        cin >> a >> b;
        cout << prefix[b] - prefix[a-1] << endl;
    }


    
}



int main()
{
    fast;
    int TCS = 1;
    // cin >> TCS;
    for (int TC = 1; TC <= TCS; ++TC)
    {
      // cout<<"Case "<<TC<<": ";
      solve();
    }
}