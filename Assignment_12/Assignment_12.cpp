
#include <iostream>
#include <climits>
using namespace std;

int matrixChainMultiplication(int p[], int n) {
    int dp[100][100] = {0};

    // len is the number of matrices in the chain
    for (int len = 2; len < n; len++) {
        for (int i = 1; i <= n - len; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = dp[i][k]
                         + dp[k + 1][j]
                         + p[i - 1] * p[k] * p[j];

                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    return dp[1][n - 1];
}

int main() {
    int n;
    int p[100];

    cout << "Enter number of dimensions: ";
    cin >> n;

    cout << "Enter dimensions: ";
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    cout << "Minimum number of scalar multiplications: "
         << matrixChainMultiplication(p, n) << '\n';

    return 0;
}
