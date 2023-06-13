#include <bits/stdc++.h>
/*
#define ll long long
#define int ll
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
#define pp push_back
#define bd(n) (n).begin(),(n).end()
#define endl '\n'
#define fast   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define yes cout<< "YES\n";
#define no cout<< "NO\n";
#define PI acos(-1)
#define sin(a) sin((a)*PI/180)
#define cos(a) cos((a)*PI/180)
#define mem(a, b) memset(a, b, sizeof(a))
#define mk make_pair
#define in(v) for (auto & x : (v)) cin >> x
#define out(v) for (auto x : (v)) cout << x << ' '
const ll OO = 1e18;
using namespace std;

void dfs(int node, const vector<vector<int>> &mat, vector<bool> &vis) {
    //    cout<<node<<" ";

    vis[node] = true;
    for (int i = 0; i < mat[node].size(); ++i) {
        if (!vis[mat[node][i]]) {
            dfs(mat[node][i], mat, vis);
        }
    }
}

void bfs(int start, const vector<vector<int>> &mat, vector<int> &vis) {
    queue<int> q;
    q.push(start);
    //    cout<<q.front()<<" ";
    vis[start] = 0;
    while (!q.empty()) {
        int temp = q.front();
        for (int i: mat[temp]) {
            if (vis[i] == -1) {
                q.push(i);
                //                cout<<chek[temp][i]<<" ";
                vis[i] = vis[q.front()] + 1;
            }
        }
        q.pop();
    }

}

int far_point(int start, const vector<vector<int>> &mat, vector<int> &vis) {
    queue<int> q;
    q.push(start);
    //    cout<<q.front()<<" ";
    vis[start] = 0;
    while (!q.empty()) {
        int temp = q.front();
        for (long long i: mat[temp]) {
            if (vis[i] == -1) {
                q.push(i);
                //                cout<<chek[temp][i]<<" ";
                vis[i] = vis[q.front()] + 1;
            }
        }
        if (q.size() == 1)return q.front();
        q.pop();
    }
    return 0;
}

void diameter() {
    int n, m;
    cin >> n >> m;
    int x = 0, y = 0;
    vector<int> vis(n + 1, -1);
    vector<vector<int>> mat(n + 1);
    while (m--) {
        cin >> x >> y;
        mat[x].push_back(y);
        mat[y].push_back(x);
    }
    int temp = far_point(x, mat, vis);
    fill(vis.begin(), vis.end(), -1);
    cout << vis[far_point(temp, mat, vis)];
}

void calc_lps(string str, int lps[]) {
    int i = 0, j = 1;
    lps[0] = 0;
    while (j < str.size()) {
        if (str[i] == str[j]) {
            lps[j] = i + 1;
            ++i;
            ++j;
        } else {
            if (i) {
                i = lps[i - 1];
            } else {
                lps[j] = 0;
                ++j;
            }
        }
    }
}

void kmp() {
    string str;
    string part;
    cin >> part;
    cin >> str;
    int cot = 0;
    int lps[part.size()];
    calc_lps(part, lps);
    int i = 0, j = 0;
    while (i < str.size()) {
        if (str[i] == part[j]) {
            ++i;
            ++j;
        } else {
            if (j)j = lps[j - 1];
            else ++i;
        }
        if (j == part.size()) {
            cout << i << endl;
            j = lps[j - 1];
        }
    }
    cout << endl;
}

void Dijkstra(int s, int vis[], vector<vector<pii>> &mat) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pii>> q;
    vis[s] = 0;
    q.emplace(0, s);
    while (!q.empty()) {
        int d_v = q.top().first;
        int v = q.top().second;
        q.pop();
        if (d_v > vis[v])
            continue;

        for (auto edge: mat[v]) {
            int len = edge.se;
            int to = edge.fi;

            if (vis[v] + len < vis[to]) {
                vis[to] = vis[v] + len;
                q.emplace(vis[to], to);
            }

        }
    }
}


int mul(int a, int b, int mod) {
    return ((a % mod) * (b % mod)) % mod;
}

bool chek_prime(int n) {
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0)return false;
    }
    return true;
}

int po(int num, int power) {
    int res = 1;
    while (power) {
        if (power & 1)res *= num;
        power /= 2;
        num *= num;
    }
    return res;
}

int pomod(int num, int power, int mod) {
    int res = 1;
    while (power) {
        if (power & 1)(res *= num) %= mod;
        power /= 2;
        num *= num;
        num %= mod;
    }
    return res % mod;
}

const int N = 2e5 + 10;
int dxx[] = {+0, +0, -1, +1, +1, +1, -1, -1};
int dyy[] = {-1, +1, +0, +0, +1, -1, +1, -1};

void sieve(vector<int> &spf) {
    for (int x = 1; x < N; x++)
        spf[x] = x;
    for (ll x = 2; x < N; x++) {
        if (spf[x] != x)
            continue;
        for (ll i = x * x; i < N; i += x) {
            if (spf[i] != i)
                continue;
            spf[i] = (int) x;
        }
    }
}

int sumdig(int n) {
    int ans = 0;
    while (n) {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}


void solve() {


}


int32_t main() {
    fast
    int test = 1;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> test;
    while (test--) {
        solve();
    }
}

/*

 */