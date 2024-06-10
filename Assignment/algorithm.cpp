#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    int Q;
    int t = 0;

    do
    {
        cin >> N >> Q;
        if (N == 0 && Q == 0)
            break;

        int alg[N];
        
        for (int i = 0; i < N; ++i)
            cin >> alg[i];
        
        sort(alg, alg + N);

        cout << "CASE# " << ++t << ":" << endl;

        for (int i = 0; i < Q; ++i)
        {
            int x;
            cin >> x;
            
            int* p = lower_bound(alg, alg + N, x);

            if (p == alg + N || *p != x)
                cout << x << " not found" << endl;
            else
                cout << x << " found at " << (p - alg + 1) << endl;
        }
    } while (true);

    return 0;
}
