#include<bits/stdc++.h>
using namespace std;

// Function to compute the phi of n
long long phi(long long n) {
    long long result = n;  // Start with n
    for (long long p = 2; p * p <= n; ++p) {
        // Check if p is a factor of n
        if (n % p == 0) {
            // Subtract multiples of this prime
            while (n % p == 0) {
                n /= p;
            }
            result -= result / p;  // phi(n) = phi(n) * (1 - 1/p)
        }
    }
    // If n is still greater than 1, then n itself is a prime factor
    if (n > 1) {
        result -= result / n;
    }
    return result;
}

int main() {
    long long n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Phi(" << n << ") = " << phi(n) << endl;
    return 0;
}
