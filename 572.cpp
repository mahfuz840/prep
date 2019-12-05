#include<stdio.h>
int X[] = {0, -1, -1, -1, 0, 1, 1, 1};
int Y[] = {-1, -1, 0, 1, 1, 1, 0, -1};
char map[101][101];

void dfs(int x, int y, int m, int n) {
    for(int i = 0; i < 8; i++) {
        int xx = x + X[i];
        int yy = y + Y[i];
        // printf("%d %d\n", xx, yy);
        if(xx >= 0 && xx < m && yy >= 0 && yy < n && map[xx][yy] == '@')
        {
            // printf("hamaisi");
            map[xx][yy] = 'a';
            dfs(xx, yy, m, n);
        }
    }
}

int main() {
    int m, n;
    while(1)
    {
        scanf("%d %d", &m, &n);
        if(m == 0)
            break;

        getchar();

        int count = 0;

        for(int i = 0; i < m; i++){
            scanf("%[^\n]%*c", map[i]);
        }

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
            {
                if(map[i][j] == '@')
                {
                    map[i][j] = 'a';
                    count++;
                    dfs(i, j, m, n);
                }
            }

        printf("%d\n", count);
    }

    return 0;
}