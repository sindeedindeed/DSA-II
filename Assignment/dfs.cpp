#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<char>>& map, int x, int y, int n, int m) {
    const int horizontal[] = {-1, 1, 0, 0};
    const int vertical[] = {0, 0, -1, 1};

    map[x][y] = '#';

    for (int i = 0; i < 4; ++i) {
        int nx = x + horizontal[i];
        int ny = y + vertical[i];
        
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] == '.') {
            dfs(map, nx, ny, n, m);
        }
    }
}

int roomNumber(vector<vector<char>>& map, int n, int m) {
    int rooms = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (map[i][j] == '.') {
                dfs(map, i, j, n, m);
                rooms++;
            }
        }
    }
    return rooms;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> map(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> map[i][j];
        }
    }

    cout << roomNumber(map, n, m) << endl;

    return 0;
}
