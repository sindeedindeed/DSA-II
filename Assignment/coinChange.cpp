#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int coinChange(int n,int x,vector<int>& c){
    vector<int>dp(x + 1, INT_MAX); 
    dp[0] = 0; 
    for(int coin : c){
        for(int i = coin; i <= x; i++) {
            if(dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return dp[x] == INT_MAX ? -1 : dp[x];
}

int main(){
    int n,x;
    cin >>n>>x;
    vector<int> c(n);
    for(int i = 0; i < n; i++){
        cin>>c[i];
    }
    cout << coinChange(n, x, c) << endl;
    return 0;
}
