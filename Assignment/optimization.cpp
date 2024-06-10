#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int optimize(int n, int m, int k, vector<int>& person, vector<int>& flat) {
    sort(person.begin(), person.end());
    sort(flat.begin(), flat.end());

    int allocated = 0;
    int i = 0, j = 0;

    while (i < n && j < m) {
        if (abs(person[i] - flat[j]) <= k) {
            allocated++;
            i++;
            j++;
        } else if (person[i] < flat[j]) {
            i++;
        } else {
            j++;
        }
    }

    return allocated;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> person(n);
    for (int i = 0; i < n; ++i) {
        cin >> person[i];
    }

    vector<int> flat(m);
    for (int i = 0; i < m; ++i) {
        cin >> flat[i];
    }

    cout << optimize(n, m, k, person, flat) << endl;

    return 0;
}
