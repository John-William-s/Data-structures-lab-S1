#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head = NULL,*temp,*current, *tail,*newnode;

int value;

struct node *createnode()
{
    printf("Enter the data: ");
    scanf("%d",&value);
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    return newnode;
}
void insertion()
{
    if(head==NULL)
    {
        newnode=createnode();
        head=newnode;
    }
    else
    {
        newnode=createnode();
        current=head;
        while(current->next!=NULL)
        {
            current=current->next;
        }
        current->next=newnode;
    }
}
    void display()
    {
        current=head;
        while(current!=NULL)
        {
            printf("%d --> ",current->data);
            current=current->next;
        }  
        printf("NULL\n");      

    }
    void insertpos()
    {
        int pos;
        printf("Enter the posiion: ");
        scanf("%d",&pos);
        newnode=createnode();
        current=head;
        for(int i = 1;i<pos-1;i++)
        {
            current=current->next;
        }
        newnode->next=current->next;
        current->next=newnode;
        printf("inserted");
    }

    void deletepos()
    {
        int pos;
        printf("Enter the posiion: ");
        scanf("%d",&pos);
        current = head;
        for (int i = 1; i < pos - 1; i++)
        {
            current = current->next;
        }
        temp=current->next;
        current->next=current->next->next;
        free(temp);

    }
    void reverse(struct node *current)
    {
        if(current==NULL)
        {
            return;
        }
        reverse(current->next);
        printf("%d --> ",current->data);
}

void main()
{
    int ch;
    while(1)
    {
        scanf("%d",&ch);
        if(ch==1)
        {
            insertion();
        }
        if(ch==2)
            display();
        if(ch==3)
            insertpos();
        if(ch==4)
            deletepos();
        if(ch==5)
        {
            current=head;
            reverse(current);
            printf("NULL\n");
        }
    }

}