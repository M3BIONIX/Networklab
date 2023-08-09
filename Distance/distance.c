#include<stdio.h>

int costMatrix[20][20], n;

struct routers
{
    int distance[20];
    int adjacent[20];

}node[20];

void readCost()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", costMatrix[i][j]);
            costMatrix[i][i] = 0;
            node[i].distance[j] = costMatrix[i][j];
            node[i].adjacent[j] = j;
        }
    }
}

void calcCost()
{
    for(int i =0; i < n; i++)
    {
        for(int j =0; j < n; j++)
        {
            for(int k =0; k< n; k++)
            {
                if(node[i].distance[j] > costMatrix[i][k] + node[k].distance[j] )
                    {
                        node[i].distance[j] = costMatrix[i][k] + node[k].distance[j];
                        node[i].adjacent[j] = k;
                    }


            }
        }
    }
}


void readCost()
{
    for(int i = 0; i < n; i++)
    {
        printf("Router : %d \n", i+1);
        for(int j = 0; j < n; j++)
        {
            printf("Node %d via %d : Distance : %d", j+1, node[i].adjacent[j] + 1,node[i].distance[j]);
        }
    }
}