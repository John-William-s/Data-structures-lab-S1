#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    char data[10];
    struct node *next;
    struct node *prev;
}*head = NULL, *current,*temp, *newnode;

char value[10];

struct node *createnode(char data[])
{
    newnode = (struct node *)malloc(sizeof(struct node));
    strcpy(newnode->data,data);
    newnode->prev = NULL;
    newnode->next = NULL;

    return newnode;
}

void creation()
{
    printf("Enter the string: ");
    gets(value);
    newnode = createnode(value);
    if(head == NULL)
    {
        head = newnode;
    }
    else
    {
        current  = head;
        while(current->next!=NULL)
        {
            current = current->next;
        }
        current->next=newnode;
        newnode->prev=current;
    }
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
            printf("%s --> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}
void check()
{
    current = head;
    while(current!=NULL)
    {
        for(int i=0;current->data[i]!='\0';i++)
        {
            char ch=current->data[i];
            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
            {
                printf("%c\t",ch);
            }
        }
    current = current->next;
    }
}
void main()
{
    creation();
    display();
    check();
}