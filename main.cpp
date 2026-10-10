#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    if(!(cin >> n >> m)) return 0;
    int r = n - m; // remaining apples after eating m
    vector<long double> E(n+1, 0.0L);
    // E[r] = 0 already
    for(int k = r+1; k <= n; ++k) {
        long double sum = 0.0L;
        for(int y = r; y <= k-1; ++y) sum += E[y];
        E[k] = 1.0L + sum / k;
    }
    // add a tiny epsilon to mitigate floating point rounding issues
    long double result = E[n] + 1e-12L;
    cout.setf(ios::fixed);
    cout << setprecision(2) << (double)result << "\n";
    return 0;
}
