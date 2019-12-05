#include<iostream>
#include<algorithm>
int g[4][4] = {
            {0, 0, 0, 0},
            {0, 0, 1, 0},
            {0, 0, 0, 1},
            {0, 0, 1, 0}};
int c[4];
bool check(int x, bool visited[], bool rec[]);
bool hasCycle();
void print(bool rec[4]);
using namespace std;

bool hasCycle() {
    bool visited[5] = {0};

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++){
            bool rec[5] = {0};

            if(g[i][j] && check(j, visited, rec) == true)
                return true;
        }
    }

    return false;
}

bool check(int x, bool visited[], bool rec[]) {
    if(!visited[x]) {
        visited[x] = true;
        rec[x] = true;

        int u = x;
        for(int i = 0; i < 4; i++) {
            if(g[u][i] && !visited[i] && check(i, visited, rec)){
                return true;
            }
            else if(g[u][i] && rec[i]){
                print(rec);
                return true;
            }
        }
    }

    rec[x] = false;

    return false;
}
void print(bool rec[4]) {
    for(int i = 0; i < 4; i++)
    {
        if(rec[i])
            c[i] = i;
        else
            c[i] = 0;
    }
    sort(c, c+4);
    for(int i = 0; i < 4; i++)
        cout << c[i] << " ";
    cout << endl;
}
int main() {
    bool res = hasCycle();
    res?cout<<"true":cout << "false";
    cout << endl;
}