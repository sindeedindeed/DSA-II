#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int rows, cols;
    cin >> rows >> cols;

    vector<string> mapLayout(rows);
    pair<int, int> start, end;
    for (int i = 0; i < rows; ++i) {
        cin >> mapLayout[i];
        for (int j = 0; j < cols; ++j) {
            if (mapLayout[i][j] == 'A') {
                start = {i, j};
            } else if (mapLayout[i][j] == 'B') {
                end = {i, j};
            }
        }
    }

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    vector<vector<pair<int, int>>> previous(rows, vector<pair<int, int>>(cols, {-1, -1}));

    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    const vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    const string moveCharacters = "UDLR";

    bool done = false;

    while (!q.empty() && !done) {
        pair<int, int> current = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int new_row = current.first + moves[i].first;
            int new_col = current.second + moves[i].second;

            if (new_row >= 0 && new_row < rows && new_col >= 0 && new_col < cols && mapLayout[new_row][new_col] != '#' && !visited[new_row][new_col]) {
                visited[new_row][new_col] = true;
                previous[new_row][new_col] = current;
                q.push({new_row, new_col});
                if (new_row == end.first && new_col == end.second) {
                    done = true;
                    break;
                }
            }
        }
    }

    if (!done) {
        cout << "NO\n";
    } else {
        string path;
        for (pair<int, int> current = end; current.first != start.first || current.second != start.second; ) {
            pair<int, int> prev = previous[current.first][current.second];
            if (prev.first == current.first - 1 && prev.second == current.second) {
                path += 'D';
            } else if (prev.first == current.first + 1 && prev.second == current.second) {
                path += 'U';
            } else if (prev.first == current.first && prev.second == current.second - 1) {
                path += 'R';
            } else if (prev.first == current.first && prev.second == current.second + 1) {
                path += 'L';
            }
            current = prev;
        }
        reverse(path.begin(), path.end());
        cout << "YES\n" << path.size() << '\n' << path << '\n';
    }

    return 0;
}
