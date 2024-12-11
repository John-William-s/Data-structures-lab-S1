#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* next;
};

void main() {
    int value, i, n, ch, j;
    struct node *newNode, *current, *head = NULL;

    while(1){
        printf("1: Creation\n2: Display\n3: insertion at begining\n4: insertion at end\n5: insertion with position\n6: Deletion at begining\n7: deletion at end\n8:deletion at any position");
        printf("Enter choice");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("Enter the number of nodes: ");
            scanf("%d", &n);

            for (i = 0; i < n; i++) 
            {
                newNode = (struct node*)malloc(sizeof(struct node));  
                printf("Enter the value: ");
                scanf("%d", &value);
                newNode->data = value;
                newNode->next = NULL;

                if (head == NULL) 
                {
                    head = newNode; 
                    current = newNode;
                } else
                {
                    current->next = newNode; 
                    current = newNode;
                }
            }
        }
        if(ch==2)
        {
            current = head;
            printf("The linked list is: ");
            while (current != NULL) {
                printf("%d  ", current->data);
                current = current->next;
            }
            printf("\n");

        }
        if(ch==3)
        {
            newNode = (struct node*)malloc(sizeof(struct node));  
            printf("Enter the data: ");
            scanf("%d",&value);
            newNode->data=value;
            newNode->next=head;
            head=newNode;
        }
        if(ch==4)
        {
            newNode = (struct node*)malloc(sizeof(struct node));
            printf("Enter the data: ");
            scanf("%d",&value);
            newNode->data=value;
            newNode->next=NULL;
            current=head;
            while (current->next != NULL) 
            {
                current = current->next;
            }
            current->next=newNode;

        }
        if(ch==5)
        {
            printf("Enter the position");
            scanf("%d",&j);
            printf("Enter the data: ");
            scanf("%d",&value);
            newNode = (struct node*)malloc(sizeof(struct node));
            newNode->data=value;
            current=head;
            for(i=1;i<j-1;i++)
            {
                current=current->next;
            }
            newNode->next = current->next;
            current->next=newNode;
            printf("\n");
        }
        if(ch==6)
        {
            head=head->next;
        }
        if(ch==7)
        {
            current=head;
            while(current->next->next != NULL)
            {
                current=current->next;
            }
            current->next=NULL;
        }
        if(ch==8)
        {
            printf("Enter the position");
            scanf("%d",&j);
            current=head;
            for(i=1;i<j-1;i++)
            {
                current=current->next;
            }
            current->next = current->next->next;

        }
}
}
