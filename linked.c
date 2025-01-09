#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head = NULL, *current, *temp,*newnode;

struct node *createnode(int value)
{
    newnode = (struct node *) malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
};

void insertion()
{
    int value;
    printf("Enter the value: ");
    scanf("%d",&value);
    newnode = createnode(value);

    if (head == NULL)
    {
        head = newnode;
        return;
    }
    current = head;
    while(current->next!=NULL)
    {
        current = current->next;
    }
    current->next = newnode;

}

void display()
{
    if(head==NULL)
    {
        printf("NULL\n");
        return;
    }

    else
    {
        current = head;
        while (current != NULL)
        {
            if (head == NULL)
                break;
            printf("%d --> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}

void delend()
{
    if (head==NULL)
    {
        printf("List empty\n");
        return;
        
    }

    current = head;
    if(current->next==NULL)
    {
        free(current);
        head = NULL;
        return;
    }
    while (current->next->next!=NULL)
    {
        current=current->next;    
    }
    temp=current->next;
    current->next = NULL;
    free(temp);
}
void delbig()
{

    if (head==NULL)
    {
        printf("List empty\n");
        return;
        
    }
    
    current = head;
    if(head->next==NULL)
    {
        free(current);
        head==NULL;   
    }

    head = head->next;
    free(current);
}

void inbig()
{
    int value;
    printf("Enter the value: ");
    scanf("%d",&value);
    newnode = createnode(value);
    newnode->next = head;
    head=newnode;
}
int size()
{
    int n=0;
    current = head;
    while(current!=0)
    {
        current=current->next;
        n++;
    }
    return n;
}
void inpos()
{

    int val,pos;
    
    printf("Enter the position");
    scanf("%d",&pos);


    if(pos==1)
    {
        inbig();
        return;
    }
    if(pos>size())
    {
        printf("INvlid\n");
        return;
    }
    printf("Enter the value: ");
    scanf("%d",&val);
    newnode = createnode(val);
    current=head;
    for(int i =1;i<pos-1;i++)
    {
        current=current->next;
    }
    
    newnode->next=current->next;
    current->next=newnode;
}

void delpos()
{
    int pos;
    printf("Enter the position");
    scanf("%d",&pos);
    

    if(pos==1)
    {
        delbig();
        return;
    }
    if(pos>size())
    {
        printf("INvlid\n");
        return;
    }
    current=head;
    for(int i =1;i<pos-1;i++)
    {
        current=current->next;
    }
    temp=current->next;
    current->next=temp->next;
    free(temp);



}
void main()
{
    int ch;
    while(1)    
    {
        printf("1.Insertion\n");
        printf("2.Display\n");
        printf("3.Deletion at End\n");
        printf("4.Deletion at begining\n");
        printf("5.Insertioan at begining\n");
        printf("6.Insertion at any pos\n");
        printf("Enter choice: ");
        scanf("%d",&ch);
        printf("\n\n");
        
        if(ch ==1)
        insertion();
        
        
        if(ch==2)
        display();

        if(ch==3)
        delend();

        if(ch==4)
        delbig();

        if(ch==5)
        inbig();

        if(ch==6)
        inpos();

        if(ch==7)
        delpos();
    }
}
