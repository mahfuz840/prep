#include<stdio.h>
#include<string.h>
int X[] = {-1, 0, 1, 0};
int Y[] = {0, -1, 0, 1};
char map[100][100];
void dfs(int x, int y);

int main() {
    int t;
    int i;
    scanf("%d ", &t);
    while(t--) {
        // getchar();
        i = 0;
        while(scanf("%[^\n]%*c", map[i])) {
            if(map[i][0] == '_')
                break;
            
            i++;
        }

        for(int j = 0; j < i; j++)
        {
            int k = strlen(map[j]);

            for(int x = 0; x < k; x++) {
                if(map[j][x] == '*')
                {
                    map[j][x] = '#';
                    dfs(j, x);
                }
            }
        }

        for(int j = 0; j <= i; j++)
            puts(map[j]);
    }

    return 0;
}

void dfs(int x, int y){
    for(int i = 0; i < 4; i++) {
        int yy = y + X[i];
        int xx = x + Y[i];

        // printf("%d %d\n", x, y);

        if(map[xx][yy] == ' ')
        {
            // printf("hamaisi\n");
            map[xx][yy] = '#';
            dfs(xx, yy);
        }
    }
}