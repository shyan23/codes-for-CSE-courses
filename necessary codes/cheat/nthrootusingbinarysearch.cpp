#include <bits/stdc++.h>
using namespace std;

double root(double n, double s) {
    double l, r;
    double ep = 0.000001; // Epsilon value for comparison

    if (n >= 0 && n <= 1) {
        l = n;
        r = 1;
        return l; // Add return statement for this case
    } else {
        l = 1.0;
        r = n;

        while (r - l > ep) { // Adjusted termination condition
            double mid = (l + r) / 2.0;
            double power = pow(mid, s);
            if (power > n) {
                r = mid;
            } else if (power < n) {
                l = mid;
            } 
        }
        return r;
        // Add a return statement here if the loop doesn't find a solution within the epsilon threshold
    }
}

int main() {
    double n, x;
    cin >> n >> x;
    cout << root(n, x);
    return 0;
}
