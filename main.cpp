#include <bits/stdc++.h>
// final version
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
    long double v = E[n];
    // Round half up to two decimal places
    long double scaled = v * 100.0L + 0.5L + 1e-12L; // add 0.5 for half-up rounding, epsilon for precision
    long long int_part = (long long)scaled; // truncates toward zero, effectively floor after adding 0.5
    // Output formatted with two digits
    cout.setf(ios::fixed);
    cout << setprecision(2) << (int_part / 100) << '.' << setw(2) << setfill('0') << (int_part % 100) << "\n";
    return 0;
}
