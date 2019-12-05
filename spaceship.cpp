#include<iostream>
int g[7][5];
int dy[3] = {0, -1, 1};
int dx[3] = {-1, -1, -1};
int mx = 0;
void boom(int x, int y);
using namespace std;
void traverse(int x, int y, int coin, bool bomb) {
    if(coin > mx)
        mx = coin;
    for(int i = 0; i < 3; i++) {
        int xx = x+dx[i];
        int yy = y+dy[i];
        if(xx >= 0 && yy < 5 && yy >= 0 && g[xx][yy] == 1)
            {   
                // cout << 1 << " " << xx << "," << yy << endl;
                traverse(xx, yy, coin+1, bomb);
            }
        
    }
    for(int i = 0; i < 3; i++) {
        int xx = x+dx[i];
        int yy = y+dy[i];
        if(xx >= 0 && xx < 5 && yy >= 0 && g[xx][yy] == 0)
         {   
                // cout << 0 << " " << xx << "," << yy << endl;
                traverse(xx, yy, coin, bomb);
         }
        
    }
    if(!bomb){
        boom(x, y);
        // cout << "boom " << x << "," << y << endl;
        bomb = true;
        return traverse(x, y, coin, bomb);
    }
    return;
}

void boom(int x, int y) {
    for(int i = x-1; x-i <= 5; i--) {
        for(int j = 0; j < 5; j++)
            if(i >= 0 && g[i][j] == 2)
                g[i][j] = 0;
    }
}
int main() {
    for(int i = 0; i < 6; i++)
        for(int j = 0; j < 5; j++)
            cin >> g[i][j];

    traverse(6, 2, 0, false);

    cout << mx << endl;

}