#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int i,j,x,n, adj[10][10],mst[10][10],visited[10],count=0;

int indegree(int node)
{
    int c=0;
    for(x=0;x<n;x++)
    {
        if(adj[x][node]==1)
        c++;
    }
    return c;
}

void main()
{
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
     printf("Adjcency matrix: \n");

     for(i=0;i<n;i++)
     {
        visited[i]=0;
        for(j=0;j<n;j++)
        {
            printf("[%d][%d] --> ",i,j);
            scanf("%d",&adj[i][j]);
        }
     }

     for(i=0;i<n;i++)
     {
        for(j=0;j<n;j++)
        {
            printf("%d  ",adj[i][j]);
        }
        printf("\n");
     }

    printf("\nTopological sort: ");
    while(count<n)
     for(i=0;i<n;i++)
     {
        if (indegree(i)==0 && visited[i]!=1)
        {
            visited[i]=1;
            printf("%d ",i);
            for(j=0;j<n;j++)
            {
                adj[i][j]=0;
            }
            count++;
            break;

        }
     }
    
    


}