#include<stdio.h>
#include<stdlib.h>
int u[10],n;

int ispresent(int a[],int item,int size)
{
    for(int i =0;i<size;i++)
    {
        if(item==a[i])
        {
            return 1;
        }
    }
    
    return 0;
}
void readset(int a[],int size)
{
    int i,val;
    if(a==NULL)
    {
        for(i=0;i<size;i++)
        {
            printf("Enter element %d: ",i+1);
            scanf("%d",&val);
            if(!ispresent(u,val,n))
            {
                u[i]=val;
            }
            else
            {
                i--;
            }
        }
    }
    else
    {
        for(i=0;i<size;i++)
        {
            printf("Enter element %d: ",i+1);
            scanf("%d",&val);
            if(ispresent(u,val,n) && !ispresent(a,val,size))
            {
                a[i]=val;
            }
            else
            {
                i--;
            }
        }

    }
}
void display(int a[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d - ",a[i]);
    }
    printf("\n");
}

void main()
{
    int n1,n2,s1[10],s2[10],val;
    printf("Ente the universal set size: ");
    scanf("%d",&n);
    readset(NULL,n);
    display(u,n);


    printf("Ente the set1 size: ");
    scanf("%d",&n1);
    readset(s1,n1);
    display(s1,n1);

    printf("Ente the set2 size: ");
    scanf("%d",&n2);
    readset(s2,n2);
    display(s2,n2);

    int b1[n],b2[n];
    for(int i=0;i<n;i++)
    {
        val=u[i];
        if(ispresent(s1,val,n1))
        {
            b1[i]=1;
        }
        else{
            b1[i]=0;
        }
    }
    for(int i=0;i<n;i++)
    {
        val=u[i];
        if(ispresent(s2,val,n2))
        {
            b2[i]=1;
        }
        else{
            b2[i]=0;
        }
    }
    printf("Bit 1: ");
    display(b1,n);
    printf("Bit 2: ");
    display(b2,n);

    printf("UNION: ");
    for(int i=0;i<n;i++)
    {
        if(b1[i]==1 || b2[i]==1)
        {
            printf("1 - ");
        }
        else
        {
            printf("0 -");
        }
        
    }
    printf("\nINtersection: ");
    for(int i=0;i<n;i++)
    {
        if(b1[i]==1 && b2[i]==1)
        {
            printf("1 - ");
        }
        else
        {
            printf("0 -");
        }
    }
}




