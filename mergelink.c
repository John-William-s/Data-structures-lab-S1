#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*current, *temp,*newnode;

struct node *createnode(int value)
{
    newnode = (struct node *) malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
};

void insertion(struct node **head)
{
    int value;
    printf("Enter the value: ");
    scanf("%d",&value);
    newnode = createnode(value);

    if (*head == NULL)
    {
        *head = newnode;
        return;
    }
    current = *head;
    while(current->next!=NULL)
    {
        current = current->next;
    }
    current->next = newnode;

}

void display(struct node *head)
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


void main()
{

    struct node *head=NULL,*head2 = NULL;
    int size,i;
    scanf("%d",&size);
    for(i=0;i<size;i++)
    {
        insertion(&head);
    }

    printf("The first linkedlist is : ");
    display(head);

    scanf("%d",&size);
    for(i=0;i<size;i++)
    {
        insertion(&head2);
    }
    printf("The second linked list: ");
    display(head2);

    current= head;
    while(current->next !=NULL)
    {
        current = current->next;
    }
    current->next = head2;
    printf("The merged link list is: ");
    display(head);
}