#include<stdio.h>
void left(int x, int y, int len);
void up(int x, int y, int len);
void right(int x, int y, int len);
void down(int x, int y, int len);

int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
int map[1001][1001];
int visited[1001][1001];
int count;
int r, c, x, y, l;


void dfs(int x, int y, int len) {

    visited[x][y] = 1;
    count++;

    if(map[x][y] == 1) {
        left(x, y, len);
        up(x, y, len);
        right(x, y, len);
        down(x, y, len);
    }
    else if(map[x][y] == 2) {
        up(x, y, len);
        down(x, y, len);
    }

    else if (map[x][y] == 3)
    {
        left(x, y, len);
        right(x, y, len);
    }
    else if (map[x][y] == 4)
    {
        up(x, y, len);
        right(x, y, len);
    }
    else if(map[x][y] == 5) {
        right(x, y, len);
        down(x, y, len);
    }
    else if(map[x][y] == 6) {
        left(x, y, len);
        down(x, y, len);
    }
    else if(map[x][y] == 7) {
        left(x, y, len);
        up(x, y, len);
    }
}

void left(int x, int y, int len) {
    int xx = x + dx[0];
    int yy = y + dy[0];
    if(xx >= 0 && xx < r && yy >= 0 && yy < c && map[xx][yy] >= 1 && map[xx][yy] <= 7 && len > 0 && !visited[xx][yy]
    && (map[xx][yy] == 1 || map[xx][yy] == 3 || map[xx][yy] == 4 || map[xx][yy] == 5)) {
        // count++;
        // printf("left\n");
        dfs(xx, yy, len-1);
    }
}

void up(int x, int y, int len) {
    int xx = x + dx[1];
    int yy = y + dy[1];
    if(xx >= 0 && xx < r && yy >= 0 && yy < c && map[xx][yy] >= 1 && map[xx][yy] <= 7 && len > 0 && !visited[xx][yy]
     && (map[xx][yy] == 1 || map[xx][yy] == 2 || map[xx][yy] == 5 || map[xx][yy] == 6)) {
        // count++;
        // printf("up\n");

        dfs(xx, yy, len-1);
    }
}

void right(int x, int y, int len) {
    int xx = x + dx[2];
    int yy = y + dy[2];
    if(xx >= 0 && xx < r && yy >= 0 && yy < c && map[xx][yy] >= 1 && map[xx][yy] <= 7 && len > 0 && !visited[xx][yy]
    && (map[xx][yy] == 1 || map[xx][yy] == 3 || map[xx][yy] == 7 || map[xx][yy] == 6)) {
        // count++;
        // printf("right\n");

        dfs(xx, yy, len-1);
    }
}

void down(int x, int y, int len) {
    int xx = x + dx[3];
    int yy = y + dy[3];
    if(xx >= 0 && xx < r && yy >= 0 && yy < c && map[xx][yy] >= 1 && map[xx][yy] <= 7 && len > 0 && !visited[xx][yy]
    && (map[xx][yy] == 1 || map[xx][yy] == 2 || map[xx][yy] == 4 || map[xx][yy] == 7)) {
        // printf("down\n");
        
        dfs(xx, yy, len-1);
    }
}

int main() {
    int t;

    scanf("%d", &t);
    while (t--)
    {
        count = 0;
        scanf("%d %d %d %d %d", &r, &c, &x, &y, &l);

        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++){
                scanf("%d", &map[i][j]);
                visited[i][j] = 0;
            }

        if(map[x][y] >= 1 && map[x][y] <= 7)
            dfs(x, y, l-1);

        printf("%d\n", count);
    }

    return 0;
}