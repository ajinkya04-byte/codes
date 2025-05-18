#include <iostream>
using namespace std;

int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int a[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}
    };

void dfs(int i){
    int j;
    cout<<i<<endl;
    visited[i]=1;
    for (int j = 0; j < 7; j++)
    {
        if (a[i][j]==1 && !visited[j]){
            dfs(j);
        }
        
        
    }
    
}

int main()
{   //DFS Implementation
    dfs(4);
    return 0;
}