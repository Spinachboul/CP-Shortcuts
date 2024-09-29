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

bool isPleasantPair(const string &s, int i, int j, int k){
    if(k>=i && k<j){
        if(s[k] != s[k+1] && (s[k] != s[i] && s[k+1] != s[j])){
            return true;
        }
    }
    return false;
    
}

void solve(){
    int n;
    cin >> n;
    string s; cin >> s;

    unordered_map<char, int> freq;

    // Count the frequency of each character
    for (char c : s) {
        freq[c]++;
    }

    // Create a vector of pairs (frequency, character)
    vector<pair<int, char>> sortedChars;
    for (auto &entry : freq) {
        sortedChars.push_back(make_pair(entry.second, entry.first));
    }

    // Sort the characters by frequency in descending order
    sort(sortedChars.rbegin(), sortedChars.rend());

    // Create a vector to hold the reordered string
    vector<char> reordered(n);

    // Place characters in the result array in a way that avoids adjacent duplicates
    int index = 0;
    for (int i = 0; i < sortedChars.size(); ++i) {
        int count = sortedChars[i].first;
        char ch = sortedChars[i].second;

        for (int j = 0; j < count; ++j) {
            // Place character in alternate positions
            if (index >= n) {
                index = 1;  // Start filling odd positions after even ones are filled
            }
            reordered[index] = ch;
            index += 2;
        }
    }

    // Print the reordered string
    for (char c : reordered) {
        cout << c;
    }
    cout << endl;
    

}
int main(){
    fast;
    int t;
    t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}