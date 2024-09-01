#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int dx[8] = {-2, -2, -1, -1, +1, +1, +2, +2};
int dy[8] = {-1, +1, -2, +2, -2, +2, -1, +1};

const int maxn = 10;
char a[maxn][maxn];
bool visited[maxn][maxn];
int cost[maxn][maxn];

bool isValidPosition(int x, int y) {
    if ((x >= 1 && x <= 8) && (y >= 1 && y <= 8)) return true;
    return false;
}

void bfs(int x1, int y1) {
    queue<pair<int, int>> q;
    q.push({x1, y1});
    visited[x1][y1] = true;
    while (!q.empty()) {
        pair<int, int> top = q.front();
        q.pop();
        int x2 = top.first;
        int y2 = top.second;
        for (int i = 0; i < 8; ++i) {
            int x3 = x2 + dx[i];
            int y3 = y2 + dy[i];
            if (isValidPosition(x3, y3) && !visited[x3][y3]) {
                cost[x3][y3] = cost[x2][y2] + 1;
                if (a[x3][y3] == 'B') return;
                q.push({x3, y3});
                visited[x3][y3] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        memset(a, '-', sizeof(a));
        memset(visited, false, sizeof(visited));
        memset(cost, 0, sizeof(cost));
        string s1, s2;
        cin >> s1 >> s2;
        // Xu ly xau
        int x1 = (int)(s1[0] - 'a') + 1;
        int y1 = (int)(s1[1] - '0');
        int x2 = (int)(s2[0] - 'a') + 1;
        int y2 = (int)(s2[1] - '0');

        a[x1][y1] = 'A';
        a[x2][y2] = 'B';

        bfs(x1, y1);

        cout << cost[x2][y2] << "\n";
    }


    return 0;
}
