#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1e9 + 7;

int path(int n, const vector<vector<char>>& square){
    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[0][0] = (square[0][0] != '*');

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (square[i][j] != '*') {
                if (i > 0 && square[i-1][j] != '*') {
                    dp[i][j] += dp[i-1][j];
                    dp[i][j] %= MOD;
                }
                if (j > 0 && square[i][j-1] != '*') {
                    dp[i][j] += dp[i][j-1];
                    dp[i][j] %= MOD;
                }
            }
        }
    }

    return dp[n-1][n-1];
}

int main(){
    int n;
    cin >> n;
    vector<vector<char>> square(n, vector<char>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> square[i][j];
        }
    }
    cout << path(n, square) << endl;
    return 0;
}
