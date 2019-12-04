//commenting to change the code
#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
long long l, r;
vector< int > mp[100001];
int visited[100001] = {0};

void dfs(int nd, int col){
    for(int i = 0; i < mp[nd].size(); i++) {
        if(!visited[mp[nd][i]]) {
            visited[mp[nd][i]] = 1;
            if(col == 0)
                r++;
            else
                l++;
            int nCol = 1-col;
            if(nCol < 0)
                nCol = nCol*(-1);
            dfs(mp[nd][i], nCol);
        }
    }
}

int main() {
    int n;

    cin >> n;

    for(int i = 0; i < n-1; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        mp[x].push_back(y);
        mp[y].push_back(x);
    }

    l = 1;
    r = 0;
    visited[1] = 1;

    dfs(1, 0);
    cout << (l*r - (n-1)) << endl;

    return 0;
}