#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define pb push_back

vector<int> sumInRanges(vector<int> &arr, int n, vector<vector<ll>> &queries, int q) {
    ll mod = (ll)1e9 + 7;
    ll left, right;
    vector<int> ans;
    vector<int> sum(n + 1);
    sum[0] = 0;
    for(int i = 0; i < n; i++) {
        sum[i + 1] = (sum[i] % mod + arr[i] % mod) % mod;
    } 
    ll tmp = 0;
    for(auto it: queries) {
        left = it[0];
        right = it[1];
        --left;
        tmp = (sum[right % n] - sum[left % n] + ((sum[n] * ((right / n - left / n) % mod)))) % mod;
        ans.pb((tmp + mod) % mod);
    }
    return ans;
}


int main() {
    vector<int> v = {5, 2, 6, 9};
    int n = v.size();
    int q = 3;
    vector<vector<ll>> queries = {{1, 5}, {10, 13}, {7, 11}};
    vector<int> ans = sumInRanges(v, n, queries, q);
    for(auto it: ans) cout << it << " ";
    cout << "\n";
    
    return 0;
}