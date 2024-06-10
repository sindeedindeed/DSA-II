#include <iostream>
#include <vector>
#include <map>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll int n, k;
        cin >> n >> k;
        vector<ll int> a(n);
        map<int, int> rem;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] % k)
                rem[k - (a[i] % k)]++;
        }
        ll int moves = 0;
        bool check = true;
        while (check)
        {
            check = false;
            for (auto i : rem)
            {
                if (i.second == 0)
                    continue;
                else
                    check = true;
                rem[i.first]--;
                ll int num = i.first;
                if (moves % k <= num)
                    moves += (num - (moves % k) + 1);
                else
                {
                    moves += (k - (moves % k) + num + 1);
                }
            }
        }
        cout << moves << endl;
    }
    return 0;
}
