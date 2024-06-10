#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<int> prr(10, 0);
        queue<pair<int, int>> print;

        for (int i = 0; i < n; ++i)
        {
            int prior;
            cin >> prior;

            ++prr[prior];
            print.push({prior, i});
        }

        int min = 0;
        bool ap = false;

        while (!ap)
        {
            pair<int, int> cur_job = print.front();
            print.pop();

            bool imp = true;

            for (int i = cur_job.first + 1; i < 10; ++i)
            {
                if (prr[i] > 0)
                {
                    imp = false;
                    break;
                }
            }

            if (imp)
            {
                ++min;

                if (cur_job.second == m)
                {
                    ap = true;
                    cout << min << "\n";
                    break;
                }

                --prr[cur_job.first];
            }
            else
            {
                print.push(cur_job);
            }
        }
    }

    return 0;
}
