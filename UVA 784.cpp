#include<stdio.h>
#include<string.h>
int X[] = {-1, 0, 1, 0};
int Y[] = {0, 1, 0, -1};
char map[100][100];
void dfs(int x, int y);

int main() {
    int t;
    int i;
    scanf("%d\n", &t);
    while(t--) {
        i = 0;
        while(gets(map[i])) {
            if(map[i][0] == '_')
                break;
            
            i++;
        }

        for(int j = 0; j <= i; j++)
        {
            int k = strlen(map[j]);

            for(int x = 0; x < k; x++) {
                if(map[j][x] != ' ' && map[j][x] != '_' && map[j][x] != 'X')
                {
                    map[j][x] = '#';
                    dfs(j, x);
                }
            }
        }

        for(int j = 0; j <= i; j++)
            puts(map[j]);
    }
}

void dfs(int x, int y){
    for(int i = 0; i < 4; i++) {
        x = x + X[i];
        y = y + Y[i];

        if(map[x][y] == ' ')
        {
            map[x][y] = '#';
            dfs(x, y);
        }
    }
}