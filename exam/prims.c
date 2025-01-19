#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct edge
{
    int u;
    int v;
    int cost;
}*minedge;

int size,start,i,j,mst[20][20],adj[20][20],cost=0,visited[20];

void adjread(int n)
{
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("cost of [%d][%d]-->",i,j);
            scanf("%d",&adj[i][j]);
        }
    }
}

void prims(int start,int n)
{
    int min=INT_MAX,count =0;
    minedge = (struct edge *)malloc(sizeof(struct edge));
    visited[start]=1;
    count++;
    while(count<n)
    {
    for(i=0;i<n;i++)
    {
        if (visited[i] == 1)
        {
            for (j = 0; j < n; j++)
            {
                if (adj[i][j] != 0 && visited[j]==0 && adj[i][j]<min)
                {
                    min=adj[i][j];
                    minedge->u=i;
                    minedge->v=j;
                    minedge->cost=adj[i][j];
                }
            }
        }
    }
    visited[minedge->v]=1;
    mst[minedge->u][minedge->v]=minedge->cost;
    cost+=minedge->cost;
    count++;

    minedge->cost=INT_MAX;
    min=INT_MAX;
    }
    free(minedge);
}

void mstdisplay()
{
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            if(mst[i][j]!=0)
            {
                printf("[%d][%d] --> %d \n",i,j,mst[i][j]);
            }
        }
    }
    printf("Total cost: %d",cost);

}
void main()
{

    printf("Enter hte number of nodes: ");
    scanf("%d",&size);
    // initialisation
    for(i=0;i<size;i++)
    {
        visited[i]=0;
        for(j=0;j<size;j++)
        {
            mst[i][j]=0;
            adj[i][j]=0;
        }
    }

    adjread(size);

    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            if(adj[i][j]!=0)
            printf("[%d][%d]--> %d", i,j,adj[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    while(1)
    {
    printf("Enter start--> ");
    scanf("%d",&start);
    if(start>=0 &&start<size)
        break;
    }


    prims(start,size);

    mstdisplay();
}

