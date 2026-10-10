#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    if(!(cin >> n >> m)) return 0;
    int r = n - m; // remaining apples after eating m
    vector<double> E(n+1, 0.0);
    // E[r] = 0 already
    for(int k = r+1; k <= n; ++k) {
        double sum = 0.0;
        for(int y = r; y <= k-1; ++y) sum += E[y];
        E[k] = 1.0 + sum / k;
    }
    cout.setf(ios::fixed);
    cout << setprecision(2) << E[n] << "\n";
    return 0;
}
