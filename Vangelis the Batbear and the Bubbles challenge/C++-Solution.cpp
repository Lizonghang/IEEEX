#include <cstdio>
#include <cstring>
using namespace std;

const int Nmax = 1005;
int sta[Nmax][Nmax] = {0}, psta[Nmax] = {0};
int n, m;

bool dfs(int now, int tt, int p) {
    psta[now] = tt;
    for(int i = 0; i < n; i++)
        if(sta[now][i] == tt || sta[i][now] == tt) {
            if(psta[i] != tt) {
                if(!dfs(i, tt, now))
                    return false;
            }
            else if(psta[i] == tt && i == p)
                continue;
            else return false;
        }
    return true;
}

int main() {
    int t;
    scanf("%d", &t);
    for(int tt = 1; tt <= t; tt++) {
        bool ans = true;
        scanf("%d%d\n", &n, &m);
        for(int i = 0; i < m; i++) {
            int t1, t2;
            scanf("%d%d", &t1, &t2);
            if(ans) {
                if(t1 > t2) {
                    int a = t1;
                    t1 = t2;
                    t2 = a;
                }
                if(sta[t1][t2] == tt || sta[t2][t1] == tt)
                    ans = false;
                else {
                    sta[t2][t1] = tt;
                    sta[t1][t2] = tt;
                }
            }
        }
        for(int i = 0; i < n && ans; i++)
            if(psta[i] != tt)
                ans = dfs(i, tt, -1);
        printf("%d\n", !ans);
    }
    return 0;
}

