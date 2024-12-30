#include<stdio.h>
int size;
int vertex[10];
int edge[10][10];
int visited[10];

void dfs(int p);
void main()
{
    int size,ch,i,j,w;
    printf("enter the number of vertices: ");
    scanf("%d",&size);
    
    printf("enter the vertices:");

    for(i=0;i<size;i++){
        scanf("%d",&vertex[i]);
    }

    for(i=0;i<size;i++)
    {
        for(j=i;j<size;j++)
        {
            edge[i][j]=edge[j][i]=0;
            printf("do you want edges between %d and %d \n1.Yes\n2.No\n Enter your choice:",vertex[i],vertex[j]);
            scanf("%d",&ch);
            if(ch==1){
                printf("enter the weight of the edge:");
                scanf("%d",&edge[i][j]);
                edge[j][i]=edge[i][j];
            }
        }
    }

    for(i=0;i<size;i++)
    {
        printf("%d : ",vertex[i]);
        for(j=0;j<size;j++)
        {
            if(edge[i][j]!=0)
            {
                printf("%d ",vertex[j]);
            }
        }
        printf("\n");
    }

//dfs
    int start;

    for(i=0;i<size;i++)
    {
        visited[i]=0;
    }

    printf("enter the node to start:");
    scanf("%d",&start);
    for(i=0;i<size;i++)
    {
        if(start==vertex[i]){

            dfs(i);
            break;
        }
    }
    
}
void dfs(int p)
{
    visited[p] = 1 ;
    printf("%d\t",vertex[p]);
    for(int i = 0; i<size;i++)
    {
        if(edge[p][i] != 0 && visited[i] == 0)
        {
            dfs(i);
        }
    }
}