
#include <stdio.h>

struct node
{
    int dist[20];
    int from[20];
} r[10];

int main()
{
    int dmat[20][20];

    int n;
    int count = 0;
    printf("Enter the number of nodes: \n");
    scanf("%d", &n);
    printf("Enter the cost matrix: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &dmat[i][j]);
            dmat[i][i] = 0;
            r[i].dist[j] = dmat[i][j];
            r[i].from[j] = j;
        }
    }

    do
    {
        count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    if (r[i].dist[j] > dmat[i][k] + r[k].dist[j])
                    {
                        r[i].dist[j] = r[i].dist[k] + r[k].dist[j];
                        r[i].from[j] = k;
                        count++;
                     }
                }
            }
        }
    } while (count != 0);

    for (int i = 0; i < n; i++)
    {
        printf("\n\nState value for router %d is \n", i + 1);

        for (int j = 0; j < n; j++)
        {
            printf("\t\nnode %d via %d Distance%d", j + 1, r[i].from[j] + 1, r[i].dist[j]);
        }
    }
    printf("\n\n");

    return 0;
}