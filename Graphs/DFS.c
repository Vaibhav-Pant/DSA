//  Depth first search

/*
    Graph G{V,E}
    Mark all nodes v in V as unvisited;
    Make Adj Matrix for graph.

    DFS(G, u) // u is the node
    u.visited = true
    for each unvisited neighbour v of u
    {
        DFS(G,v);
    }
*/

#include<stdio.h>

int visited[7] = {0,0,0,0,0,0,0};

int a[7][7] = {

    {0,1,1,1,0,0,0},
    {1,0,0,1,0,0,0},
    {1,0,0,1,1,0,0},
    {1,1,1,0,1,0,0},
    {0,0,1,1,0,1,1},
    {0,0,0,0,1,0,0},
    {0,0,0,0,1,0,0}
};

void DFS(int x)
{
    printf("%d ",x);
    visited[x] = 1;
    for(int i = 0; i < 7; i++)
    {
        if(a[x][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

int main(){
     // DFS implementation 

    //         0 -- 1
    //         | \  |
    //         |  \ |
    //         2 -- 3
    //         \  /
    //          4
    //         / \
    //        5   6

    DFS(0);
    return 0;
}