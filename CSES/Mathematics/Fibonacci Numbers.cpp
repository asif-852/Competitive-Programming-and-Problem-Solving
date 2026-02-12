
#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9 + 7;
 
struct Matrix {
    int size;
    vector<vector<long long>> mat;
 
    Matrix(int n) : size(n), mat(n, vector<long long>(n, 0)) {}
 
    // Static function to create identity matrix
    static Matrix identity(int n) {
        Matrix I(n);
        for(int i = 0; i < n; i++) {
            I.mat[i][i] = 1;
        }
        return I;
    }
 
    // Matrix multiplication
    Matrix operator*(const Matrix &other) const {
        Matrix result(size);
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                for(int k = 0; k < size; k++) {
                    result.mat[i][k] += mat[i][j] * other.mat[j][k];
                    if(result.mat[i][k] >= MOD) {
                        result.mat[i][k] %= MOD;
                    }
                }
            }
        }
        return result;
    }
 
    // Matrix exponentiation
    Matrix pow(long long power) const {
        Matrix result = Matrix::identity(size);
        Matrix base = *this;
        while (power > 0) {
            if(power % 2)
                result = result * base;
            base = base * base;
            power /= 2;
        }
        return result;
    }
};
 
long long compute_nth_term(long long n, vector<long long> coeffs, vector<long long> base) {
    int k = coeffs.size();
    if(n < k) return base[base.size() - n - 1] % MOD;
 
    Matrix T(k);
 
    for(int i = 0; i < k; i++) {
        T.mat[0][i] = coeffs[i] % MOD;
    }
 
    for(int i = 1; i < k; i++) {
        T.mat[i][i - 1] = 1;
    }
 
    T = T.pow(n - k + 1);
 
    // Multiply with base vector
    long long result = 0;
    for(int i = 0; i < k; i++) {
        result = (result + T.mat[0][i] * base[i]) % MOD;
    }
 
    return result;
}
 
void solve() {
 
    vector<long long> coeffs = {1, 1};         // F[n] = 1 * F[n - 1] + 1 * F[n - 2]
    vector<long long> base = {1, 0};           // F[1] = 1, F[0] = 0 (terms in gradually decreasing order)
 
    long long n;
    cin >> n;
    cout << compute_nth_term(n, coeffs, base) << '\n';
 
}
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
 
    return 0;
}
