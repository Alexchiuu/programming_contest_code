#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

const long long MOD = 998244353;

long long modExp(long long base, long long exponent, long long modulus) {
    long long result = 1;
    base = base % modulus; // Handle base greater than modulus

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        exponent = exponent >> 1; // Divide exponent by 2
        base = (base * base) % modulus; // Square the base
    }

    return result;
}

int gcd(long long a, long long b) {
    while (b != 0) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int modInverse(int x, long long mod) {
    long long a = x, b = mod, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    return (u + mod) % mod;
}

int main() {
    fastio;

    int m, n, p;
    cin >> m >> n >> p;

    if (p == 50) {
        int a = m;
        int b = m + n;
        int inv_b = modInverse(b, MOD);
        cout << (a * inv_b) % MOD << endl;
    } else {
        long long pow_p_m_plus_n = modExp(p, m + n, MOD);
        long long pow_p_n = modExp(p, n, MOD);
        long long pow_100_minus_p_m = modExp(100 - p, m, MOD);
        long long pow_100_minus_p_m_plus_n = modExp(100 - p, m + n, MOD);

        long long a = abs(pow_p_m_plus_n - pow_p_n * pow_100_minus_p_m % MOD) % MOD;
        long long b = abs(pow_p_m_plus_n - pow_100_minus_p_m_plus_n) % MOD;
        int g = gcd(a, b);
        a /= g;
        b /= g;
        int inv_b = modInverse(b, MOD);
        cout << (a * inv_b) % MOD << endl;
    }

    return 0;
}