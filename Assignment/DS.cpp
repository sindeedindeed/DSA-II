#include <iostream>
#include <vector>

using namespace std;

int timeUntilPrinted(const vector<int>& priorities, int m) {
    int higherPriorityJobs = 0;
    int targetPriority = priorities[m];
    for (int priority : priorities) {
        if (priority > targetPriority) {
            higherPriorityJobs++;
        }
    }
    int time = 0;
    while (true) {
        if (priorities.front() == targetPriority) {
            time++;
            if (m == 0) {
                break;
            }
            m--;
            priorities.erase(priorities.begin());
        } else {
            priorities.push_back(priorities.front());
            priorities.erase(priorities.begin());
            if (m == 0) {
                m = priorities.size() - 1;
            } else {
                m--;
            }
        }
    }
    return time + 1; // plus 1 for the final print
}

int main() {
    int numTestCases;
    cin >> numTestCases;

    for (int i = 0; i < numTestCases; ++i) {
        int n, m;
        cin >> n >> m;
        vector<int> priorities(n);
        for (int j = 0; j < n; ++j) {
            cin >> priorities[j];
        }
        cout << timeUntilPrinted(priorities, m) << endl;
    }

    return 0;
}
 