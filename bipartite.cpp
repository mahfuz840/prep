#include<iostream>
#include<queue>
using namespace std;
int v = 4;
int col[4];
int mp[][4] = {{0, 1, 0, 1}, 
            {1, 0, 1, 0}, 
            {0, 1, 0, 1}, 
            {1, 0, 1, 0}};

bool bfs(int src){
    col[src] = 1;
    queue<int> q;
    q.push(src);

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        //there is a self loop which is not allowed
        if(mp[u][u] == 1)
            return false;

        for(int i = 0; i < v; i++) {
            if(mp[u][i] && col[i] == -1) {
                col[i] = 1-col[u];
                q.push(i);
            }

            else if(mp[u][i] && col[u] == col[i])
                return false;
        }
    }

    return true;
}

int main() {

    for(int i = 0; i < v; i++) {
        col[i] = -1;
    }

    bool printed = false;

    for(int i = 0; i < v; i++){
        if(col[i] == -1) {
            if(bfs(i) == false){
                printed = true;
                cout << "Not Bipartite" << endl;
                break;
            }
        }
    }

    if(!printed)
        cout << "Bipartite" << endl;

    return 0;
}