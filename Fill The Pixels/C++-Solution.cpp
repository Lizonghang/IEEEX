#include <iostream>
#include <queue>

using namespace std;

const int Nmax = 1e3 + 5;
int n, m, data[Nmax][Nmax];
typedef pair<int, int> Pair;

const int dx[3][4] = {{0, 0, 0, 0}, {0, 0, 1, -1}, {1, -1, 1, -1}};
const int dy[3][4] = {{0, 0, 0, 0}, {1, -1, 0, 0}, {1, 1, -1, -1}};

void bfs(int i, int j, int k) {
    queue<Pair> q;
    q.push(Pair(i, j));
    ++data[i][j];
    while(!q.empty()) {
        Pair now = q.front();
        q.pop();
        for(int ii = 1; ii < 3; ii++) {
            if(k & ii) {
                for(int jj = 0; jj < 4; jj++) {
                    int nx = now.first + dx[ii][jj];
                    int ny = now.second + dy[ii][jj];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                        continue;
                    if(data[nx][ny] == k) {
                        ++data[nx][ny];
                        q.push(Pair(nx, ny));
                    }
                }
            }
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d\n", &m, &n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++)
                data[i][j] = getchar() - '0';
            getchar();
        }
        int ans[4] = {0};
        for(int k = 1; k < 4; k++) {
            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                    if(data[i][j] == k) {
                        bfs(i, j, k);
                        ans[k]++;
                    }
        }
        printf("%d %d %d\n", ans[1], ans[2], ans[3]);
    }
    return 0;
}
