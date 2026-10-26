
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    int wt[101], val[101];

    cout << "Enter weights of items:\n";
    for (int i = 1; i <= n; i++) {
        cin >> wt[i];
    }

    cout << "Enter values of items:\n";
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }

    cout << "Enter knapsack capacity: ";
    cin >> W;

    int dp[102][1001] = {0};

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            // Do not select the current item
            dp[i][w] = dp[i - 1][w];

            // Select the current item if it fits
            if (wt[i] <= w) {
                dp[i][w] = max(
                    dp[i][w],
                    val[i] + dp[i - 1][w - wt[i]]
                );
            }
        }
    }

    cout << "Maximum value: " << dp[n][W] << '\n';

    // Reconstruct selected items
    cout << "Selected item indices: ";
    int w = W;

    for (int i = n; i >= 1; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            cout << i << " ";
            w -= wt[i];
        }
    }

    cout << '\n';

    return 0;
}
